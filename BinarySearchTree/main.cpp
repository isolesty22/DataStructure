#include <iostream>
#include "AVL.h"
#include "RBT.h"

int main()
{
	std::string str1 = "meimei1";
	std::string str2 = "meimei2";

	//BST<std::string> bst;

	//bst.insert(1, str1);
	//bst.insert(2, str2);
	//bst.inorder();

	//bst.remove(1);
	//bst.remove(2);
	//bst.inorder();

	//AVL<std::string> avl;

	//avl.insert(1, str1);
	//avl.insert(2, str2);
	//avl.inorder();

	//avl.remove(1);
	//avl.remove(2);
	//avl.inorder();

	RBT<std::string> rbt;
	 
	/*rbt.insert(1, str1);
	rbt.insert(2, str2);
	rbt.inorder();

	rbt.remove(1);
	rbt.remove(2);*/

	for (int i = 0; i < 20; i++)
	{
		rbt.insert(i, str1);
	}
	rbt.preorder();
	std::cout << std::endl;

	rbt.remove(5);
	rbt.remove(15);
	rbt.remove(12);

	rbt.preorder();
}