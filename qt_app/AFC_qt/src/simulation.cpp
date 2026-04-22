#include <iostream>
#include <vector>
#include <algorithm>
#include "simulation.h"
using namespace std;


Point Robot::getNextMove() {
    if (pathIndex + 1 < (int)path.size()) return path[pathIndex + 1];
    return currentPos;
}
// 8x7 맵 정의 (1: 기둥/장애물, 0: 이동 가능)
int world_map[7][8] = {
    {1, 1, 1, 0, 1, 0, 1, 0},
    {1, 1, 1, 0, 0, 0, 0, 0},
    {1, 1, 1, 0, 0, 0, 0, 0},
    {1, 1, 1, 0, 1, 1, 1, 1},
    {1, 0, 0, 0, 0, 0, 0, 0},
    {1, 0, 0, 1, 1, 1, 1, 1},
    {0, 0, 0, 0, 0, 0, 0, 0}
};

// 대피소 목록 정의
vector<Point> shelters = {{2, 5}, {4, 2}, {4, 3}, {4, 4}};
// vector<Point> shelters = {{2, 5}};

void setCriticalZone(Point p) {
    if (p.y == 6 && (p.x == 0 || p.x == 1)) {
        world_map[6][0] = 2;
        world_map[6][1] = 2;
    }
    if (p.x == 3 && (p.y == 0 || p.y == 1)) {
        world_map[0][3] = 2;
        world_map[1][3] = 2;
    }
}

bool isCriticalZone(Point p) {
    // 상차지
    if (p.y == 6 && (p.x == 0 || p.x == 1)) {
        return true;
    }
    // 하역장 Z
    if (p.x == 3 && (p.y == 0 || p.y == 1)) {
        return true;
    }
    return false;
}

void showMap(){
    for (int y = 0; y < 7; y++) {
        for (int x = 0; x < 8; x++) {
            cout << world_map[y][x] << " ";
        }
        cout << endl;
    }
};

void simulateStep(vector<Robot>& robots) {
    for(int y=0; y<7; y++) for(int x=0; x<8; x++) if(world_map[y][x] != 1) world_map[y][x] = 0;
    for(auto& r : robots) {
        setCriticalZone(r.currentPos);
        world_map[r.currentPos.y][r.currentPos.x] = 3;
    }

    showMap();

    for (auto& r : robots) {
        if (r.isFinished) continue;

        if (r.blockedCnt >= 3) {
            // [예외 처리 3: 경로 업데이트] 길이 막혀있을 때 3번 카운트 후
            r.path = findPath(r.currentPos, r.finalGoal, world_map);
            r.pathIndex = 0;

            // 만약 경로가 막혀있다면
            if (r.path.empty()) {
                // 만약 다른 대기 중인 터틀 봇이 있다면, 우선순위를 따져 낮은 순위의 터틀 봇을 대피소로 보냄
                bool isSlave = false;
                for(auto& other : robots) {
                    if(other.blockedCnt == 3 && other.priority > r.priority) {
                        r.blockedCnt = 0;
                        continue;
                    }
                }

                // [예외 처리 4: 대피소 이동]
                cout << "Can't Find Path." << endl;
                cout << "Robot " << r.id << " : Finding Shelter...\n";

                // 가장 가깝고, 비어있으며 도달 가능한 대피소로 가는 경로 찾기
                vector<Point> shelterPath = findValidShelterPath(r.currentPos, shelters, world_map);

                if (!shelterPath.empty()) {
                    r.path = shelterPath;
                    r.blockedCnt = 0;
                    cout << "Robot " << r.id << " : Moving To Shelter\n";
                    r.isWaiting = true;
                    continue;
                } else {
                    cout << "Robot " << r.id << " : [WARNING!!] CAN'T FIND ANY SHELTERS\n";
                    continue;
                }
            } else {
                cout << "Best Path XY:" << endl;
                for (auto p : r.path) {
                    cout << "{" << p.x << ", " << p.y << "}, ";
                }
                cout << "Way Designation complete" << endl;

                r.blockedCnt = 0;
                continue;
            }
        }

        Point next = r.getNextMove();

        // [예외 처리 1: 우선순위 양보]
        bool needToYield = false;
        for(auto& other : robots) {
            if(other.id != r.id && !other.isFinished) {
                if(other.getNextMove().x == r.getNextMove().x && other.getNextMove().y == r.getNextMove().y) {
                    if(r.priority > other.priority) { needToYield = true; break; }
                }
            }
        }
        if (needToYield) {
            r.blockedCnt++;
            cout << "Robot " << r.id << " yields path.\n"; continue;
        }

        // [예외 처리 2: 임계 구역 진입 통제 - 지능적 필터링]
        if (isCriticalZone(next)) {
            bool zoneBlocked = false;
            for(auto& other : robots) {
                if(other.id != r.id) {
                    if(isCriticalZone(other.currentPos)) {
                        // 상황 A: 내가 이 구역을 "목적지"로 삼고 들어가려 할 때 (작업자)
                        if(isCriticalZone(r.finalGoal)) {
                            // 안에 누군가(작업자든 통행자든) 있다면 절대 진입 금지 (데드락 방지)
                            zoneBlocked = true;
                            break;
                        }
                        // 상황 B: 나는 그냥 "통과"만 할 건데 (통행자)
                        else {
                            // 안에 있는 녀석이 아직 "움직이는 중"이라면 충돌 위험으로 대기
                            if(!other.isFinished) {
                                zoneBlocked = true;
                                break;
                            }
                            // 안에 있는 녀석이 "작업 완료"해서 멈춰있다면, 내 길(next)만 안 막으면 통과 가능
                        }
                    }
                }
            }
            if (zoneBlocked && !isCriticalZone(r.currentPos)) {
                cout << "Robot " << r.id << " waits outside Critical Zone.\n";
                r.blockedCnt++;
                continue;
            }
        }

        // [이동 로직]
        // 내 다음 칸에 다른 로봇이 서 있다면(작업 완료 로봇 포함) 못 감
        if (world_map[next.y][next.x] == 0 || world_map[next.y][next.x] == 2 || (next.x == r.currentPos.x && next.y == r.currentPos.y)) {
            world_map[r.currentPos.y][r.currentPos.x] = 0;
            if (!(next.x == r.currentPos.x && next.y == r.currentPos.y)) {
                r.currentPos = next;
                r.pathIndex++;
            }
            world_map[r.currentPos.y][r.currentPos.x] = 3;
            cout << "Robot " << r.id << " moved to (" << r.currentPos.x << ", " << r.currentPos.y << ")\n";
        } else {
            r.blockedCnt++;
            cout << "Robot " << r.id << " is WAITING (Path Blocked by Robot at " << next.x << "," << next.y << ")\n";
            continue;
        }

        if (r.currentPos.x == r.path.back().x && r.currentPos.y == r.path.back().y) {
            // 대피소에서 대기 중이 아니라면
            if(!r.isWaiting) {
                r.isFinished = true;
                cout << "Robot " << r.id << " arrived at GOAL.\n";
            } else {
                if (world_map[r.finalGoal.y][r.finalGoal.x] == 0) {
                    cout << "Robot " << r.id << " : Goal is now free. Re-routing...\n";

                    vector<Point> newPath = findPath(r.currentPos, r.finalGoal, world_map);

                    if (!newPath.empty()) {
                        r.path = newPath;
                        r.pathIndex = 0;
                        r.isWaiting = false;
                        r.blockedCnt = 0;

                        cout << "Robot " << r.id << " : Leaving shelter and moving to goal.\n";
                    } else {
                        cout << "Robot " << r.id << " : Path to goal still blocked.\n";
                    }
                } else {
                    cout << "Robot " << r.id << " : Goal still occupied. Waiting...\n";
                }
            }
        }

        r.blockedCnt = 0;
    }
}