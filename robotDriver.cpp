#include <iostream>
#include <math.h>
#include "robot.h"

using namespace std;

// main method tests Robot funtionality
int main()
{
    Robot r1(1, 1, 1, 1);
    cout << "r1:" << endl;
    r1.printShortestPath(); // should not print any paths (robot is already at target)

    Robot r2(5, 0, 15, 0);
    cout << "\nr2:" << endl;
    r2.printShortestPath(); // should not print any paths (impossible to move a direction more than 2 times in a row)

    Robot r3(1, 2, 3, 5);
    cout << "\nr3:" << endl; // should be 7 total paths
    r3.printShortestPath();

    Robot r4(24, 16, 20, 8);
    cout << "\nr4:" << endl; // should be 15 total paths
    r4.printShortestPath();

    Robot r5(0, 0, 1, 1); // should be 2 total paths
    cout << "\nr5:" << endl;
    r5.printShortestPath();

    Robot r6(14, 15, 15, 15); // should be 1 total path
    cout << "\nr6:" << endl;
    r6.printShortestPath();
}