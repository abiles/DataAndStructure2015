// Breadth-FirstSearch.cpp : �ܼ� ���� ���α׷��� ���� �������� �����մϴ�.
//

#include "stdafx.h"

struct Node
{
	Node()
	{
		neighbor.reserve(5);
	}

	int  value = 0;
	bool isPushed = false;
	std::vector<Node*> neighbor;
};

struct Graph
{
	Node* source = nullptr;
};


// Graph�� source�� ��� �ִ� queue�� �ʱ� ������ ���� �ִٰ� ����
// source�� isPushed�� true�� ����� ��

void BFS(std::queue<Node*>* queue)
{
	if (queue->empty() || queue == nullptr)
		return;

	Node* tmpNode = queue->front();
	queue->pop();

	printf("%d\n", tmpNode->value);

	for (auto pNode : tmpNode->neighbor)
	{
		if (false == pNode->isPushed)
		{
			pNode->isPushed = true;
			queue->push(pNode);
		}
	}

	BFS(queue);
}


int _tmain(int argc, _TCHAR* argv[])
{
	Node* nodes = new Node[7];

	for (int i = 0; i < 7; ++i)
	{
		nodes[i].value = i;
	}

	nodes[0].neighbor.push_back(&nodes[1]);
	nodes[0].neighbor.push_back(&nodes[2]);
	nodes[0].neighbor.push_back(&nodes[3]);
	
	nodes[2].neighbor.push_back(&nodes[4]);
	nodes[2].neighbor.push_back(&nodes[5]);

	nodes[3].neighbor.push_back(&nodes[6]);

	
	std::queue<Node*> queue; 
	
	queue.push(&nodes[0]);
	nodes[0].isPushed = true;

	BFS(&queue);

	getchar();
	getchar();

	delete[] nodes;

	return 0;
}

