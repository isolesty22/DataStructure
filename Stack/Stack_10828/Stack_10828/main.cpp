#include <iostream>
#include <string>

class Stack
{
private:
	int* m_data;
	int m_top;
	int m_capacity;

public:
	Stack(int stackSize = 10) {
		m_data = new int[stackSize];
		m_top = -1;
		m_capacity = stackSize;
	};
	~Stack() { delete[] m_data; };

	void resize();  //귀찮;;
	void push(int data);
	int pop();
	int size() { return m_top + 1; };
	bool empty() { return m_top == -1; };
	bool full() { return m_top + 1 == m_capacity; };
	int top();
};

void Stack::push(int data)
{
	if (!full())
		m_data[++m_top] = data;
	else
	{
		resize();
		m_data[++m_top] = data;
	}
}

int Stack::pop()
{
	if (empty())
		return -1;
	else
		return m_data[m_top--];
}

int Stack::top()
{
	if (empty())
		return -1;
	return m_data[m_top];
}

void Stack::resize()
{
	//공간 재할당, 복사
	int* temp = new int[m_capacity + 20];
	m_capacity += 20;

	for (int i = 0; i < m_top + 1; i++)
	{
		temp[i] = m_data[i];
	}

	//삭제 
	delete[] m_data;
	m_data = temp;

}

int main()
{
	using namespace std;

	Stack stack(10);

	int commandNum;
	cin >> commandNum;

	string command;

	for (int i = 0; i < commandNum; i++)
	{
		cin >> command;
		
		if (command == "push")
		{
			int num;
			cin >> num;
			stack.push(num);
		}
		else if (command == "pop")
			cout << stack.pop() << endl;
		else if (command == "size")
			cout << stack.size() << endl;
		else if (command == "empty")
			cout << stack.empty() << endl;
		else if (command == "top")
			cout << stack.top() << endl;
		else
			i--;
	}
}