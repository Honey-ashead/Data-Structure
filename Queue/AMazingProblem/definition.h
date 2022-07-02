#pragma once
#include <iostream>
#define ROW 9
#define COL 9
int maze[ROW][COL] = {{0,1,0,1,0,1,1,0,1},
                      {0,0,0,1,1,0,1,1,0},
                      {0,1,0,1,1,1,0,1,1},
                      {0,1,0,0,0,1,1,0,1},
                      {1,0,1,1,0,0,1,1,1},
                      {1,1,0,0,1,0,0,1,0},
                      {1,0,1,1,1,1,0,1,1},
                      {0,1,1,0,1,0,0,1,1},
                      {1,0,1,1,0,0,0,0,0},
				};

//int maze[ROW][COL] = {0};
struct offset
{
	int x;
	int y;
};

struct position{
	int x;
	int y;
    int dir;
};

bool isValid(int x, int y)
{
    return x >= 0 && x < ROW && y >= 0 && y < COL;
}