// Breadth-FirstSearch.cpp : 콘솔 응용 프로그램에 대한 진입점을 정의합니다.
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


// Graph의 source만 들어 있는 queue가 초기 값으로 들어와 있다고 가정
// source의 isPushed를 true로 해줘야 함

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

