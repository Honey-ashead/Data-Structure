#pragma once
#include <iostream>

template <class T>
class CircularQueue
{
public:
	explicit CircularQueue(int MAX_CAPACITY = 100) {
		capacity = MAX_CAPACITY + 1;
		array = new T[capacity];
		front = 0;
		rear = 0;
	}

	~CircularQueue() {
		delete[] array;
		front = 0;
		rear = 0;
	}

	bool isEmpty() const {
		return (front == rear);
	}

	bool isFull() const {
		return (rear + 1) % capacity == front;
	}

	void Push(const T& item) {
		if (isFull()) {
			std::cout << "The queue is full!" << std::endl;
			return;
		}
		array[rear++] = item;
	}

	void Pop() {
		if (isEmpty()) {
			std::cout << "The queue is empty!" << std::endl;
			return;
		}
		front = (front + 1) % capacity;
	}

	T& Front() const {
		if (isEmpty()) {
			std::cout << "The queue is empty!" << std::endl;
			exit(EXIT_FAILURE);
		}
		return array[front];
	}

	T& Rear() const {
		if (isEmpty()) {
			std::cout << "The queue is empty!" << std::endl;
			exit(EXIT_FAILURE);
		}
		return array[rear-1];
	}

private:
	T * array;
	int capacity;
	int front;
	int rear;
};