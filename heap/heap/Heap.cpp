#include "Heap.h"

void Heap::insert(int key)
{
	int index = size;
	m_data[size++].setKey(key);
	
	while (index > 0 && m_data[index].getKey() > getParent(index).getKey())
	{
		//대입연산자 필요 없음
		node temp = m_data[index];
		m_data[index] = getParent(index);
		getParent(index) = temp;
		index = (index - 1) / 2;
	}
}

node Heap::remove()
{
	if (size == 0) return 0;

	node item = m_data[0];
	m_data[0] = m_data[--size];

	int index = 0;
	int child = 1;

	//리프노드가 아니라면
	while (child < size)
	{
		//오른쪽이 더크다면 그걸로, 없다면 왼쪽걸로
		if (child + 1 < size && getLeft(index).getKey() < getRight(index).getKey())
			child++;

		if (m_data[index].getKey() < m_data[child].getKey())
		{
			node temp = m_data[index];
			m_data[index] = m_data[child];
			m_data[child] = temp;
			index = child;
			child = index * 2 + 1;
		}
		else
		{
			break;
		}
	}

	return item;
}
