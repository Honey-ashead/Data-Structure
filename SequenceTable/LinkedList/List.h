#pragma once
#include <iostream>

template <class T>
struct LinkNode{
    T data;
    LinkNode<T> * next;
    explicit LinkNode(LinkNode<T> * ptr = nullptr): next(ptr){}
    explicit LinkNode(const T& data, LinkNode<T> * ptr = nullptr): data(data), next(ptr){}
    ~LinkNode(){delete next;}
};

template <typename T>
class List {
public:
    List(){head = new LinkNode<T>;}  // additional head node
    explicit List(const T data){head = new LinkNode<T>(data);}
    List(List<T> &L);
    void makeEmpty();
    ~List(){makeEmpty();}
    int Length();
    LinkNode<T> * getHead() {return head;}
    LinkNode<T> * Search(T data);
    LinkNode<T> * Locate(int i);
    bool Insert(int i, T data);
    bool Remove(int i, T& data);
    bool isEmpty() {return head->next == nullptr;}
    bool isFull() {return false;}
    bool Add(T data);
    void show();
private:
    LinkNode<T> * head;
};