#include <iostream>
#include <cassert>

using namespace std;

class Queue
{
public:
    Queue(int sz = 100);
    ~Queue() { delete[] queue; };
    bool Enqueue(int x);
    bool Dequeue(int &x);
    bool getFront(int &x);
    bool isEmpty() const { return front == rear; };
    bool isFull() const { return (rear + 1) % maxSize == front; };
    int getSize() const { return maxSize; };
    void makeEmpty() { front = rear = 0; }
    void Show() const;

private:
    int rear;
    int front;
    int maxSize;
    int *queue;
};

Queue::Queue(int sz) : front(0), rear(0), maxSize(sz)
{
    queue = new int[maxSize];
    assert(queue != nullptr);
}

bool Queue::Enqueue(int x)
{
    if (isFull())
    {
        cerr << "The queue is full!" << endl;
        return false;
    }
    queue[rear] = x;
    rear = (rear + 1) % maxSize;
    return true;
}

bool Queue::Dequeue(int &x)
{
    if (isEmpty())
    {
        cerr << "The queue is empty!" << endl;
        return false;
    }
    x = queue[front];
    front = (front + 1) % maxSize;
    return true;
}

bool Queue::getFront(int &x)
{
    if (isEmpty())
    {
        cerr << "The queue is empty!" << endl;
        return false;
    }
    x = queue[front];
    return true;
}

void Queue::Show() const
{
    int p = front;
    while ((p + 1) % maxSize <= rear)
    {
        cout << queue[p] << " ";
        p++;
    }
}

int main()
{
    Queue queue;
    int value;
    for (int i = 0; i < 5; ++i)
    {
        queue.Enqueue(i * i + 1); // 1 2, 5, 10, 17
        if (i >= 3)
            queue.Dequeue(value);
    }
    queue.Show();
    return 0;
}
