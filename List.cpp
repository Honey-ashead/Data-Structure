#include <iostream>
#include <cstdlib>

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

/* Definition of List */
class List
{
private:
    LinkNode *head;

public:
    List()
    {
        head = new LinkNode;
        head->next = nullptr;
    }
    List(const int x) { head = new LinkNode(x); }
    List(List &L);
    ~List() { makeEmpty(); }
    void makeEmpty();
    int Length();
    LinkNode *getHead() { return head; }
    LinkNode *Search(int x);
    LinkNode *Locate(int i);
    bool getData(int i, int &x);
    void setData(int i, int x);
    bool Insert(int i, int x);
    bool Remove(int i, int &x);
    bool isEmpty() { return head->next == nullptr; }
    bool isFUll() { return false; }
    void Show();
    List &operator=(List &L);
};

List::List(List &L)
{
    int temp;
    LinkNode *src = L.head;
    LinkNode *dest = new LinkNode;
    head = dest;
    while (src->next != nullptr)
    {
        temp = src->data;
        dest->next = new LinkNode(temp);
        dest = dest->next;
        src = src->next;
    }
    dest->next = nullptr;
}

void List::makeEmpty()
{
    LinkNode *temp;
    while (head->next != nullptr)
    {
        temp = head->next;
        head = head->next;
    }
    delete temp;
}

int List::Length()
{
    int count = 0;
    LinkNode *p = head->next;
    while (p != nullptr)
    {
        count++;
        p = p->next;
    }
    return count;
}

LinkNode *List::Search(int x)
{
    LinkNode *curr = head->next;
    while (curr != nullptr)
    {
        if (curr->data == x)
            break;
        else
            curr = curr->next;
    }
    return curr;
}

LinkNode *List::Locate(int i)
{
    if (i < 0)
        return nullptr;
    LinkNode *curr = head; // i = 0, returns the head
    int j = 0;
    while (curr != nullptr && j < i)
    {
        curr = curr->next;
        j++;
    }
    return curr; // curr = nullptr or it is fine
}

bool List::getData(int i, int &x)
{
    if (i <= 0) // since the head contains no valid data
        return false;
    LinkNode *curr = Locate(i);
    if (nullptr == curr)
        return false;

    x = curr->data;
    return true;
}

void List::setData(int i, int x)
{
    if (i <= 0)
    {
        cerr << "Invalid index " << i << endl;
        exit(EXIT_FAILURE);
    }
    LinkNode *curr = Locate(i);
    if (nullptr == curr)
    {
        cerr << "Invalid index " << i << endl;
        exit(EXIT_FAILURE);
    }
    curr->data = x;
}

bool List::Insert(int i, int x)
{
    LinkNode *curr = Locate(i);
    if (nullptr == curr)
    {
        cerr << "Invalid index " << i << endl;
        return false;
    }
    LinkNode *newNode = new LinkNode(x);
    newNode->next = curr->next;
    curr->next = newNode;
    return true;
}

bool List::Remove(int i, int &x)
{
    if (i <= 0)
    {
        cerr << "Invalid index " << i << endl;
        return false;
    }
    LinkNode *curr = Locate(i - 1);
    if (curr == nullptr || curr->next == nullptr)
    {
        cerr << "Invalid index " << i << endl;
        return false;
    }
    LinkNode *temp = curr->next;
    x = temp->data;
    curr->next = temp->next;
    temp->next = nullptr;
    delete temp;
    return true;
}

void List::Show()
{
    LinkNode *curr = head->next;
    while (curr != nullptr)
    {
        cout << curr->data << " ";
        curr = curr->next;
    }
    cout << endl;
}

List &List::operator=(List &L)
{
    int temp;
    LinkNode *src = L.getHead();
    LinkNode *dest = new LinkNode;
    head = dest;
    while (src->next != nullptr)
    {
        temp = src->data;
        dest->next = new LinkNode(temp);
        dest = dest->next;
        src = src->next;
    }
    dest->next = nullptr;
    return *this;
}

int main()
{
    List list;
    for (int i = 0; i < 10; i++)
    {
        list.Insert(i, i * i + 1);
    }
    list.Show();
    return 0;
}
