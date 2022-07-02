#include "LinkQueue.h"
#include <iostream>

using namespace std;

LinkQueue::LinkQueue(int value) {
	root = new Node;
    root -> next = new Node(value);
	head = root;
	tail = root -> next;
}

LinkQueue::~LinkQueue() {
	while (head != tail) {
		struct Node * p = head;
		head = head->next;
		delete p;
	}
	delete tail;
}

void LinkQueue::Enqueue(int value) {
	auto * newNode = new Node(value);
	tail -> next = newNode;
	tail = newNode;
	newNode -> next = nullptr;
}

void LinkQueue::Dequeue() {
	if (!Empty()) {
        head = head -> next;
        root -> next = head;
	} else {
		cerr << "Queue is empty!" << endl;
	    exit(EXIT_FAILURE);
	}
}

bool LinkQueue::Empty() const {
	return head == tail;
}

int LinkQueue::Front() const {
    if (!Empty())
	    return head -> next -> data;
	else {
		cerr << "Queue is empty!" << endl;
	    exit(EXIT_FAILURE);
	}
	
}

void LinkQueue::Show() const {
	struct Node * p = head -> next;
	while (p) {
		cout << p->data << " ";
		p = p->next;
	}
//	cout << endl;
}