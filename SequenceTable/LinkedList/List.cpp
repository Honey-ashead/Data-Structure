#include "List.h"
using namespace std;

template <class T>  // copy constructor
List<T>::List(List<T>& L)
{
    T value;
    LinkNode<T> * src = L.head;
    LinkNode<T> * dest = head = new LinkNode<T>;

    while (src -> next){
        value = src -> next -> data;
        dest -> next = new LinkNode<T>(value);
        dest = dest -> next;
        src = src -> next;
    }
    dest -> next = nullptr;
}

template <class T> // free space
void List<T>::makeEmpty() {
    LinkNode<T> * p;
    while (head -> next)
    {
        p = head -> next;
        head -> next = p -> next;
        delete p;
    }
}

template <class T> // get the length os the List
int List<T>::Length() {
    LinkNode<T> * ptr = head -> next; // point to the first node
    int count = 0;
    while (ptr)
    {
        count++;
        ptr = ptr -> next;
    }
    return count;
}

template <class T> // locate the ith ListNode
LinkNode<T> * List<T>::Locate(int i) {
    if (i < 0)
        return nullptr;
    LinkNode<T> * ptr = head;
    for (int k = 0; k < i; ++k)
    {
        if (ptr == nullptr)
            break;
        ptr = ptr -> next;
    }
    return ptr;
}

template <class T>
LinkNode<T> * List<T>::Search(T data) {
    LinkNode<T> * ptr = head -> next;
    while (ptr){
        if (ptr -> data == data)
            break;
        ptr = ptr -> next;
    }
    return ptr;
}

template <class T>
bool List<T>::Insert(int i, T data) {
    LinkNode<T> * ptr = Locate(i);
    if (ptr == nullptr)
        return false;
    auto * newNode = new LinkNode<T>(data);
    if (newNode == nullptr){
        cerr << "Fail to allocate space!" << endl;
        exit(EXIT_FAILURE);
    }
    newNode -> next = ptr -> next;
    ptr -> next = newNode;
    return true;
}

template <typename T>
bool List<T>::Remove(int i, T& data) {
    LinkNode<T> * ptr = Locate(i-1);
    if (ptr == nullptr || ptr -> next == nullptr)
        return false;
    LinkNode<T> * temp = ptr -> next;
    ptr -> next = temp -> next;
    data = temp -> data;
    delete temp;
    return true;
}

template <class T>
bool List<T>::Add(T data)
{
    LinkNode<T> * ptr = head;
    while (ptr -> next){
        ptr = ptr -> next;
    }
    auto * newNode = new LinkNode<T>(data);
    ptr -> next = newNode;
    newNode -> next = nullptr;
    return true;
}

template <class T>
void List<T>::show() {
    LinkNode<T> * ptr = head -> next;
    while (ptr){
        cout << ptr -> data << " ";
        ptr = ptr -> next;
    }
    cout << endl;
}
