#include <iostream>
#include <cassert>

using namespace std;

/* Definition of LinkNode */
struct LinkNode
{
    int data;
    LinkNode *next;
    LinkNode(LinkNode *ptr = nullptr) { next = ptr; };
    LinkNode(const int item, LinkNode *ptr = nullptr)
    {
        data = item;
        next = ptr;
    }
};

/* Definition of LinkedQueue */
class LinkedQueue
{
public:
    LinkedQueue();
    ~LinkedQueue();
    bool Enqueue(const int x);
    int Dequeue();
    int getFront() const;
    bool isEmpty() const { return size == 0; }
    int Size() const { return size; }
    void Show() const;

private:
    LinkNode *head; // with head pointer
    LinkNode *tail;
    int size;
};

LinkedQueue::LinkedQueue()
{
    head = new LinkNode(0);
    head->next = nullptr;
    tail = head;
    size = 0;
}

LinkedQueue::~LinkedQueue()
{
    LinkNode *curr;
    while (head != nullptr)
    {
        curr = head;
        head = head->next;
        delete curr;
    }
}

bool LinkedQueue::Enqueue(const int x)
{
    LinkNode *curr = new LinkNode(x);
    if (curr == nullptr)
        return false;

    tail->next = curr;
    tail = tail->next;
    size++;
    return true;
}

int LinkedQueue::Dequeue()
{
    if (isEmpty())
    {
        cerr << "The queue is empty!" << endl;
        exit(EXIT_FAILURE);
    }
    LinkNode *curr = head->next;
    int value = curr->data;
    head->next = curr->next;
    delete curr;
    size--;
    return value;
}

int LinkedQueue::getFront() const
{
    if (isEmpty())
    {
        cerr << "The queue is empty!" << endl;
        exit(EXIT_FAILURE);
    }
    return head->next->data;
}

void LinkedQueue::Show() const
{
    LinkNode *curr = head->next;
    while (curr != nullptr)
    {
        cout << curr->data << " ";
        curr = curr->next;
    }
    cout << endl;
}

int main()
{
    LinkedQueue queue;
    for (int i = 0; i < 10; ++i)
        queue.Enqueue(i * i + 1);
    cout << queue.getFront() << endl;
    cout << "The size of the queue is " << queue.Size() << endl;
    queue.Dequeue();
    cout << "The size of the queue is " << queue.Size() << endl;
    queue.Show();
    return 0;
}
