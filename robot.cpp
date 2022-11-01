#include <iostream>
#include "robot.h"
#include <math.h>

using namespace std;

// implementation of constructor with no path given
Robot::Robot(int curX, int curY, int targetX, int targetY)
{
    this->curX = curX;
    this->curY = curY;
    this->targetX = targetX;
    this->targetY = targetY;
    this->sd = abs(this->curX - this->targetX) + abs(this->curY - this->targetY);
    this->path = "";
}

// implementation of constructor with path given
Robot::Robot(int curX, int curY, int targetX, int targetY, string path)
{
    this->curX = curX;
    this->curY = curY;
    this->targetX = targetX;
    this->targetY = targetY;
    this->sd = abs(this->curX - this->targetX) + abs(this->curY - this->targetY);
    this->path = path;
}

// facade method which calls actual recursive method
void Robot::printShortestPath()
{
    int numOfPaths = 0;
    printShortestPath(*this, numOfPaths);
    cout << "Number of Paths: " << numOfPaths << endl;
}

// recursive method which prints every shortest path of robot once robot has reached target
void Robot::printShortestPath(Robot &r, int &numOfPaths)
{
    // base case:
    if (r.sd == 0) // if length of shortest path is 0, robot is at target value
    {
        if (r.path.length() > 0) // if path is not empty
        {
            numOfPaths++;
            cout << r.path << endl;
        }
        return;
    }
    if (r.shouldGoNorth())
    {
        // new robot is closer to target gaurenteed
        Robot closer(r.curX, r.curY + 1, r.targetX, r.targetY, r.path + 'N'); // new robot that is north of current
        printShortestPath(closer, numOfPaths);
    }
    if (r.shouldGoEast())
    {
        // new robot is closer to target gaurenteed
        Robot closer(r.curX + 1, r.curY, r.targetX, r.targetY, r.path + 'E'); // new robot that is east of current
        printShortestPath(closer, numOfPaths);
    }
    if (r.shouldGoSouth())
    {
        // new robot is closer to target gaurenteed
        Robot closer(r.curX, r.curY - 1, r.targetX, r.targetY, r.path + 'S'); // new robot that is east of current
        printShortestPath(closer, numOfPaths);
    }
    if (r.shouldGoWest())
    {
        // new robot is closer to target gaurenteed
        Robot closer(r.curX - 1, r.curY, r.targetX, r.targetY, r.path + 'W'); // new robot that is east of current
        printShortestPath(closer, numOfPaths);
    }
}

// All shouldGo methods determine if robot is allowed to go the given direction

bool Robot::shouldGoNorth()
{
    if (abs(this->curX - this->targetX) + abs((this->curY + 1) - this->targetY) >= this->sd || (this->path[this->path.length() - 2] == 'N' && this->path[this->path.length() - 1] == 'N'))
    {
        return false;
    }
    return true;
}

bool Robot::shouldGoSouth()
{
    if (abs(this->curX - this->targetX) + abs((this->curY - 1) - this->targetY) >= this->sd || (this->path[this->path.length() - 2] == 'S' && this->path[this->path.length() - 1] == 'S'))
    {
        return false;
    }
    return true;
}

bool Robot::shouldGoEast()
{
    if (abs((this->curX + 1) - this->targetX) + abs(this->curY - this->targetY) >= this->sd || (this->path[this->path.length() - 2] == 'E' && this->path[this->path.length() - 1] == 'E'))
    {
        return false;
    }
    return true;
}

bool Robot::shouldGoWest()
{
    if (abs((this->curX - 1) - this->targetX) + abs(this->curY - this->targetY) >= this->sd || (this->path[this->path.length() - 2] == 'W' && this->path[this->path.length() - 1] == 'W'))
    {
        return false;
    }
    return true;
}