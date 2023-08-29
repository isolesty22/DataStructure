//#pragma once
//
//class Stack
//{
//private:
//	int* m_data;
//	int m_top;
//	int m_capacity;
//
//public:
//	Stack(int stackSize = 10) {
//		m_data = new int[stackSize];
//		m_top = -1;
//		m_capacity = stackSize;
//	};
//	~Stack() { delete[] m_data; };
//
//	//void resize();  //±ÍÂú;;
//	void push(int data);
//	int pop();
//	int size() { return m_top+1; };
//	bool empty() { return m_top == -1; };
//	bool full() { return m_top+1 == m_capacity; };
//	int top();
//};
//
