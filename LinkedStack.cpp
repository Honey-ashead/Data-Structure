#include <iostream>
#include <cassert>

using namespace std;

/* Definition of LinkNode */
struct LinkNode
{
    int data;
    LinkNode *next;
    LinkNode(LinkNode *ptr = nullptr) { next = ptr; }
    LinkNode(const int item, LinkNode *ptr = nullptr)
    {
        data = item;
        next = ptr;
    }
};

/* Definition of LinkedStack */
class LinkedStack
{
public:
    LinkedStack()
    {
        top = new LinkNode(0);
        size = 0;
    }
    ~LinkedStack() { makeEmpty(); };
    void Push(int x);
    bool Pop(int &x);
    bool getTop(int &x);
    bool isEmpty() const { return top->next == nullptr; }
    int Size() const;
    void makeEmpty();
    void Show() const;

private:
    LinkNode *top;
    int size;
};

// top -> an -> an-1 -> ... -> a1
void LinkedStack::Push(int x)
{
    LinkNode *curr = new LinkNode(x);
    curr->next = top->next;
    top->next = curr;
    size++;
}

bool LinkedStack::Pop(int &x)
{
    if (isEmpty())
        return false;
    LinkNode *target = top->next; // the node to be popped
    x = target->data;
    top->next = target->next;
    delete target;
    size--;
    return true;
}

int LinkedStack::Size() const
{
    return size;
}

bool LinkedStack::getTop(int &x)
{
    if (isEmpty())
    {
        cerr << "The stack is empty!" << endl;
        return false;
    }
    x = top->next->data;
    return true;
}

void LinkedStack::makeEmpty()
{
    LinkNode *curr;
    while (top != nullptr)
    {
        curr = top;
        top = top->next;
        delete curr;
    }
}

void LinkedStack::Show() const
{
    LinkNode *curr = top->next;
    while (nullptr != curr)
    {
        cout << curr->data << " ";
        curr = curr->next;
    }
    cout << endl;
}

int main()
{
    LinkedStack stack;
    for (int i = 0; i < 10; ++i)
    {
        stack.Push((i + 1) * (i + 1));
    }
    int value;
    stack.Pop(value);
    cout << "value = " << value << endl;

    stack.getTop(value);
    cout << "value = " << value << endl;
    stack.Show();

    cout << "The size of the stack is " << stack.Size() << endl;
    return 0;
}
