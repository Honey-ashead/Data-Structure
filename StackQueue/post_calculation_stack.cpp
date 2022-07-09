#include <stack>
#include <iostream>
#include <string>
#include <cstdlib>
#include <cstring>
#include <cassert>

using namespace std;

// post-order expression evaluation
double calculate(string expression);

int main()
{
    string expression = "23*1/";
    double result = calculate(expression);
    cout << expression << " = " << result << "\n";
    return 0;
}

// we assert that the given expression is valid
double calculate(string expression)
{
    stack<char> s;
    int left;
    int right;
    for (char c : expression)
    {
        if (isdigit(c))
            s.push(c - '0');
        else
        {
            right = s.top();
            s.pop();
            left = s.top();
            s.pop();
            if (c == '+')
            {
                s.push(left + right);
            }

            else if (c == '-')
                s.push(left - right);
            else if (c == '*')
                s.push(left * right);
            else
            {
                assert(c == '/');
                if (right == 0)
                {
                    cerr << "Division cannot be 0!" << endl;
                    exit(EXIT_FAILURE);
                }
                s.push(left / right);
            }
        }
    }
    return s.top();
}
