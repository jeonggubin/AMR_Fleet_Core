#ifndef NAVI_H
#define NAVI_H
#include "pathfinding.h"
#include <string>
enum class Direction { NORTH, SOUTH, EAST, WEST };


std::string directionToString(Direction dir);

// 두 셀 사이의 이동 방향 계산
Direction getDirectionTo(Point from, Point to);

// 현재 방향에서 목표 방향으로 가기 위한 회전 계산
// 반환값: -1 = 우회전, 1 = 좌회전, 0 = 직진
int getTurnAction(Direction current, Direction target);

// yaw 값으로 현재 방향 반환
Direction yawToDirection(double yaw);
void setStartCell(int col, int row);
Point odomToGrid(double odom_x, double odom_y);
#endif // NAVI_H

