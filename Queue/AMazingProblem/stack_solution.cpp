#include <stack>
#include <iostream>
#include "definition.h"

enum directions {N, S, W, E};
using namespace std;

ostream & operator<<(ostream & os, stack<position>& s);
int main()
{
	struct offset move[4] = {{0, -1}, {0, 1}, {-1, 0}, {1, 0}};
	stack<position> s;
    struct position pos{0, 0, E};
    s.push(pos);
    int visited[ROW][COL] = {0};

    int i, j, dir;

    while (!s.empty()) {
        i = s.top().x;
        j = s.top().y;
        dir = s.top().dir;
        s.pop();
        for (auto & p : move)
        {
            int g = i + p.x;
            int h = j + p.y;
            if (!isValid(g, h))
                continue;
            if (g == ROW - 1 && h == COL - 1) {
                pos = {i, j, dir};
                s.push(pos);
                cout << s;
                return 0;
            }
            if (!maze[g][h] && !visited[g][h]) {
                visited[g][h] = 1;
                pos = {g, h, dir};
                s.push(pos);
                i = g;
                j = h;
//                dir = S;
            }
        }

    }
    cout << "Failed" << endl;
	return 0;
}

ostream & operator<<(ostream & os, stack<position>& s)
{
    while (!s.empty())
    {
        printf("(%d, %d) -> ", s.top().x, s.top().y);
        s.pop();
    }
    return os;
}