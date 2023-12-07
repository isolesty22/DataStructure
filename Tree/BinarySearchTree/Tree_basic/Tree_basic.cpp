#include <iostream>
#include "BinSrchTree.h"

int main()
{
	BinSrchTree<int> tree;
	tree.insert(5, 0);
	tree.insert(3, 0);
	tree.insert(7, 0);
	tree.insert(4, 0);

	tree.inorder();
	tree.preorder();

	tree.remove(5);
	tree.remove(3);

	std::cout << '\n';
	
	tree.inorder();
	tree.preorder();

	std::cout << '\n';

	tree.insert(7, 0);
	tree.insert(2, 0);
	tree.insert(5, 0);
	tree.insert(8, 0);
	tree.insert(1, 0);

	tree.preorder();
}