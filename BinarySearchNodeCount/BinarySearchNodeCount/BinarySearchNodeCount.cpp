// BinarySearchNodeCount.cpp : 콘솔 응용 프로그램에 대한 진입점을 정의합니다.
//

#include "stdafx.h"

struct Node
{
	Node* left = nullptr;
	Node* right = nullptr;
};

int BCount(Node* node)
{
	if (node == nullptr)
		return 0;

	int count = 1;

	count += BCount(node->left);
	count += BCount(node->right);

	//return BCount(node->left) + BCount(node->right) + 1;

	return count;
}

int _tmain(int argc, _TCHAR* argv[])
{
	Node* node1 = new Node;
	Node* node2 = new Node;
	Node* node3 = new Node;

	node1->left = node2;
	node1->right = node3;

	int count = BCount(node1);

	printf("%d", count);


	getchar();
	getchar();

	delete node1;
	delete node2;
	delete node3;


	return 0;
}

