#include "navi.h"
#include <cmath>
#include <iostream>
using namespace std;

static int g_startCol = 0;
static int g_startRow = 0;

Direction getDirectionTo(Point from, Point to) {
    if (to.x > from.x) return Direction::EAST;
    if (to.x < from.x) return Direction::WEST;
    if (to.y > from.y) return Direction::SOUTH;
    return Direction::NORTH;
}

int getTurnAction(Direction current, Direction target) {
    if (current == target) return 0;

    if (current == Direction::EAST  && target == Direction::NORTH) return  1;
    if (current == Direction::NORTH && target == Direction::WEST)  return  1;
    if (current == Direction::WEST  && target == Direction::SOUTH) return  1;
    if (current == Direction::SOUTH && target == Direction::EAST)  return  1;

    if (current == Direction::EAST  && target == Direction::SOUTH) return -1;
    if (current == Direction::SOUTH && target == Direction::WEST)  return -1;
    if (current == Direction::WEST  && target == Direction::NORTH) return -1;
    if (current == Direction::NORTH && target == Direction::EAST)  return -1;

    return 2;  // 180도
}

Direction yawToDirection(double yaw) {
    cout<<yaw;
    if      (std::abs(yaw)          < 0.4) return Direction::EAST;
    else if (std::abs(yaw - M_PI_2) < 0.3) return Direction::NORTH;
    else if (std::abs(yaw + M_PI_2) < 0.3) return Direction::SOUTH;
    else                                    return Direction::WEST;
}

std::string directionToString(Direction dir) {
    switch (dir) {
    case Direction::NORTH: return "NORTH (위)";
    case Direction::SOUTH: return "SOUTH (아래)";
    case Direction::EAST:  return "EAST  (오른쪽)";
    case Direction::WEST:  return "WEST  (왼쪽)";
    }
    return "UNKNOWN";
}
void setStartCell(int col, int row) {
    g_startCol = col;
    g_startRow = row;
}

Point odomToGrid(double odom_x, double odom_y) {
    int col = g_startCol + (int)(odom_x / 0.30);
    int row = g_startRow + (int)(odom_y / 0.30);
    return {col, row};
}
void printNavigationStep(int robotId, Point from, Point to, Direction currentDir) {
    Direction targetDir = getDirectionTo(from, to);
    int turn = getTurnAction(currentDir, targetDir);

    cout << "[Robot " << robotId << "] ";
    cout << "현재 방향: " << directionToString(currentDir) << "\n";

    if (turn == 0) {
        cout << "[Robot " << robotId << "] ";
        cout << "방향 유지 → 직진\n";
    } else if (turn == 1) {
        cout << "[Robot " << robotId << "] ";
        cout << "좌회전 → 목표 방향: " << directionToString(targetDir) << "\n";
        cout << "[Robot " << robotId << "] ";
        cout << "방향 확인 완료: " << directionToString(targetDir) << "\n";
    } else if (turn == -1) {
        cout << "[Robot " << robotId << "] ";
        cout << "우회전 → 목표 방향: " << directionToString(targetDir) << "\n";
        cout << "[Robot " << robotId << "] ";
        cout << "방향 확인 완료: " << directionToString(targetDir) << "\n";
    } else if (turn == 2) {
        cout << "[Robot " << robotId << "] ";
        cout << "180도 회전 → 목표 방향: " << directionToString(targetDir) << "\n";
        cout << "[Robot " << robotId << "] ";
        cout << "방향 확인 완료: " << directionToString(targetDir) << "\n";
    }

    cout << "[Robot " << robotId << "] ";
    cout << "전진: (" << from.x << "," << from.y << ") → ("
         << to.x << "," << to.y << ")\n";
}