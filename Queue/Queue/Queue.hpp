#pragma once
#include <iostream>

template <class T>
class Queue{
public:
	Queue(int queueCapacity = 10) {
		capacity = queueCapacity;
		rear = -1;
		front = -1;
		array = new T[capacity];
	}
	~Queue() {delete[] array;}
	bool IsEmpty() const {return front == rear;}
	T& Front() const {return array[front];}
	T& Rear() const {return array[rear];}
	void Push(const T& item) {
		// if (front == -1) front = 0;
		// array is full
		if (rear == capacity - 1) { 
			T * temp = new T[capacity * 2];
			for (int i = 0; i < capacity; ++i)
				temp[i] = array[i];
			delete[] array;
			array = temp;
			capacity *= 2;
		}
		array[++rear] = item;
	}
	void Pop() {front++;}
private:
	int capacity;
	T * array;
	int front;
	int rear;
};