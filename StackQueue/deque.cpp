#include <iostream>
#include <cassert>
#include <cstdlib>

using namespace std;

class Deque
{
public:
    Deque(int sz = 100);
    ~Deque() { delete[] deque; }
    bool isEmpty() const { return front == rear; }
    bool isFull() const { return (rear + 1) % maxSize == front; }
    int getHead() const;
    int getTail() const;
    bool EnqueueHead(int x);
    bool EnqueueTail(int x);
    int DequeueHead();
    int DequeueTail();
    void Show() const;

private:
    int *deque;
    int front;
    int rear;
    int maxSize;
};

Deque::Deque(int sz) : front(0), rear(0), maxSize(sz)
{
    deque = new int[maxSize];
    assert(deque != nullptr);
}

int Deque::getHead() const
{
    if (isEmpty())
    {
        cerr << "The queue is empty!" << endl;
        exit(EXIT_FAILURE);
    }
    return deque[front];
}

int Deque::getTail() const
{
    if (isEmpty())
    {
        cerr << "The queue is empty!" << endl;
        exit(EXIT_FAILURE);
    }
    return deque[rear];
}

bool Deque::EnqueueHead(int x)
{
    if (isFull())
    {
        cerr << "The queue is full!" << endl;
        return false;
    }
    front = (front - 1 + maxSize) % maxSize; // front--
    deque[front] = x;
    return true;
}

bool Deque::EnqueueTail(int x)
{
    if (isFull())
    {
        cerr << "The queue is full!" << endl;
        return false;
    }
    rear = (rear + 1) % maxSize; // front--
    deque[rear] = x;
    return true;
}

int Deque::DequeueHead()
{
    if (isEmpty())
    {
        cerr << "The queue is empty!" << endl;
        exit(EXIT_FAILURE);
    }
    front = (front + 1) % maxSize;
    return deque[front];
}

int Deque::DequeueTail()
{
    if (isEmpty())
    {
        cerr << "The queue is empty!" << endl;
        exit(EXIT_FAILURE);
    }
    rear = (rear - 1 + maxSize) % maxSize;
    return deque[rear];
}

void Deque::Show() const
{
    int p = front;
    while ((p + 1) % maxSize <= rear)
    {
        cout << deque[p] << " ";
        p++;
    }
    cout << endl;
}

int main()
{
    Deque deque;
    int i;
    for (i = 0; i < 10; ++i)
    {
        deque.EnqueueTail(i * i + 1);
        if (i > 5)
            deque.DequeueHead();
    }
    deque.Show();
    return 0;
}