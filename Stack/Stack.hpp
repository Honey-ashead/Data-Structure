#ifndef STACK_STACK_H
#define STACK_STACK_H
#include <iostream>

template <typename T>
class Stack
{
public:
	explicit Stack(int stackCapacity = 10) : top(-1), capacity(stackCapacity)
	{
		if (stackCapacity < 1)
			throw "Stack capacity must be greater than 0!";
		stack = new T[capacity];
	};

	~Stack()
	{
		delete[] stack;
	}

	bool IsEmpty() const
	{
		return top == -1;
	};

	T &Top() const
	{
		if (IsEmpty())
			throw "Stack is empty!";
		return stack[top];
	};

	void Push(const T &value)
	{
		if (top == capacity - 1)
		{
			ChangeSize1D(stack, capacity, 2 * capacity);
			capacity *= 2;
		}
		stack[++top] = value;
	};

	void Pop()
	{
		if (IsEmpty())
			throw "Stack is empty!";
		top--;
	};

	void ChangeSize1D(T *ptr, const int oldSize, const int newSize)
	{
		if (newSize <= 0)
			throw "Stack size must be greater than 0!";
		T *temp = new T[newSize];
		int number = oldSize > newSize ? newSize : oldSize;
		copy(ptr, ptr + number, temp);
		delete[] ptr;
		ptr = temp;

//        for (int num: ptr)
//            std::cout << "num = " << num << std::endl;
	}

private:
	T *stack;
	int top;
	int capacity;

	void copy(T *src, T *srcend, T *dest)
	{
		if (src > srcend)
			throw "Fail to allocate new memory!";
		while (src < srcend)
			*dest++ = *src++;
	}
};

#endif // STACK_STACK_H
