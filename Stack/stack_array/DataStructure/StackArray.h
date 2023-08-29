#pragma once
#include <assert.h>

template<typename T>
class StackArray
{
private:
	T* m_data;
	int m_top;
	int m_capacity;

public:
	StackArray(int stackSize = 10);
	~StackArray();

	bool isEmpty() { return m_top == -1; };
	bool isFull() { return m_top + 1 >= m_capacity; };
	int size(){ return m_top + 1; };
	void push(T data);
	T pop();
	void display();
	T peek() { return m_data[m_top]; };
};

template<typename T>
inline StackArray<T>::StackArray(int stackSize)
{
	m_top = -1;
	m_data = new T[stackSize];
	m_capacity = stackSize;
}

template<typename T>
inline StackArray<T>::~StackArray()
{
	delete[] m_data;
}

template<typename T>
inline void StackArray<T>::push(T data)
{
	if (isFull())
	{
		std::cout << "full stack" << std::endl;
		return;
	}
	m_data[++m_top] = data;
}

template<typename T>
inline T StackArray<T>::pop()
{
	if (isEmpty())
	{
		std::cout << "empty" << std::endl;
		return 0;
	}

	return m_data[m_top--];
}

template<typename T>
inline void StackArray<T>::display()
{
	for (int i = 0; i <= m_top; i++)
	{
		std::cout << m_data[i] << std::endl;
	}
}
