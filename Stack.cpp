#include <iostream>
#include <cassert>
#include <cstdlib>

using namespace std;

const int maxStackSize = 100;
const int stackIncreaseSize = 20; // for overflowProcess

class Stack
{
public:
    Stack(int sz = 100);
    ~Stack() { delete[] stack; }
    void Push(const int x);
    bool Pop(int &x);
    bool getTop(int &x);
    bool isEmpty() const { return top == -1; };
    bool isFull() const { return top == maxSize - 1; };
    int getSize() { return top + 1; }
    void makeEmpty() { top = -1; }
    void Show() const;

private:
    int *stack;
    int top;
    int maxSize;
    void overflowProcess();
};

Stack::Stack(int sz)
{
    stack = new int[sz];
    top = -1;
    maxSize = maxStackSize;
    assert(stack != nullptr);
}

void Stack::overflowProcess()
{
    int *newStack = new int[maxSize + stackIncreaseSize];
    assert(newStack != nullptr);
    for (int i = 0; i < top + 1; ++i)
        newStack[i] = stack[i];
    maxSize += stackIncreaseSize;
    delete[] stack;
    stack = newStack;
}

void Stack::Push(int x)
{
    if (isFull())
        overflowProcess();
    stack[++top] = x;
}

bool Stack::Pop(int &x)
{
    if (isEmpty())
        return false;
    x = stack[top--];
    return true;
}

bool Stack::getTop(int &x)
{
    if (isEmpty())
        return false;
    x = stack[top];
    return true;
}

void Stack::Show() const
{
    for (int i = 0; i < top + 1; ++i)
        cout << stack[i] << " ";
    cout << endl;
}

int main()
{
    Stack stack;
    for (int i = 0; i < 20; ++i)
        stack.Push(i * i + 1);
    stack.Show();
    return 0;
}
