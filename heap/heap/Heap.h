#pragma once

class node
{
private:
	int m_key;
public:
	node(int key = 0) :m_key(key) {}
	int getKey() { return m_key; }
	void setKey(int key) { m_key = key; }
};

class Heap
{
private:
	node* m_data = new node[200];
	int size;

public:
	Heap() :size(0) {}

	node& getParent(int i) { return m_data[(i - 1) / 2]; }
	node& getLeft(int i) { return m_data[i * 2 + 1]; }
	node& getRight(int i) { return m_data[i * 2 + 2]; }

	void insert(int key);
	node remove();
};

