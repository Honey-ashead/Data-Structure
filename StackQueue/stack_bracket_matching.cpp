#include <stack>
#include <iostream>
#include <string>
#include <cassert>

using namespace std;

bool bracket_matching(string expression);
int main()
{
    string expression = "(())()";
    bool judge = bracket_matching(expression);
    if (judge)
        cout << "True!" << endl;
    else
        cout << "False!" << endl;
    return 0;
}

bool bracket_matching(string expression)
{
    stack<char> stk;
    for (char c : expression)
    {
        assert(c == '(' || c == ')');
        if (c == '(')
            stk.push(c);
        else
        {
            if (stk.empty())
                return false;
            stk.pop();
        }
    }
    if (stk.empty())
        return true;
    return false;
}