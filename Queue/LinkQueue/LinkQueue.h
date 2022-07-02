#pragma once 
#include <iostream>

struct Node {
	explicit Node () {next = nullptr;}
	explicit Node (int value, struct Node * ptr = nullptr) {data = value; next = ptr;}
	int data;
	struct Node * next;
};

class LinkQueue {
public:
	LinkQueue() {root = new Node; head = root; tail = root;}
	explicit LinkQueue(int value);
	~LinkQueue();
	void Enqueue(int value);
	void Dequeue();
	int Front() const;
	bool Empty() const;
	void Show() const;
private:
	struct Node * head;
	struct Node * tail;
	struct Node * root;
};