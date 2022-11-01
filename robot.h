#pragma once
#include <iostream>
#include <math.h>

using namespace std;

// Robot object which holds current location with x and y value, target location, and path it has traveled
class Robot
{
public:
    // constructors:
    Robot(int curX, int curY, int targetX, int targetY);
    Robot(int curX, int curY, int targetX, int targetY, string path);

    // prints all shortest paths from current location to target location
    void printShortestPath();

private:
    // instance variables
    int curX, curY, targetX, targetY, sd; // sd stands for Shortest Distance

    // path robot has traveled. String comprised of 'N', 'E', 'S', 'W'
    string path;

    // helper recursive method:
    void printShortestPath(Robot &r, int &numOfPaths);

    // returns true if robot can and is allowed to go north
    bool shouldGoNorth();

    // returns true if robot can and is allowed to go south
    bool shouldGoSouth();

    // returns true if robot can and is allowed to go east
    bool shouldGoEast();

    // returns true if robot can and is allowed to go west
    bool shouldGoWest();
};