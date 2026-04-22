#ifndef SIMULATION_H
#define SIMULATION_H
#include <vector>
#include "pathfinding.h"
using namespace std;


extern int world_map[7][8];
extern std::vector<Point> shelters;

void setCriticalZone(Point p);
bool isCriticalZone(Point p);
void showMap();

struct Robot {
    int id, priority;
    Point currentPos, finalGoal;
    std::vector<Point> path;
    int pathIndex = 0, blockedCnt = 0;
    bool isFinished = false, isWaiting = false;
    Point getNextMove();
};

void simulateStep(std::vector<Robot>& robots);
#endif // SIMULATION_H
