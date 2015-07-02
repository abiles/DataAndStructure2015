// Depth-FirstSearch.cpp : 콘솔 응용 프로그램에 대한 진입점을 정의합니다.
//

#include "stdafx.h"

struct Node
{
	bool isVisited = false;
	int  value = 0;
	std::vector<Node*> neighbor;
};

struct Graph
{
	std::vector<Node*> allNodes;
};

//void makeGraph(Graph* graph, Node* nodes)
//{
//	graph = new Graph;
//	nodes = new Node[7];
//
//	for (int i = 0; i < 7; ++i)
//	{
//		nodes[i].value = i;
//		graph->allNodes.push_back(&nodes[i]);
//	}
//	
//	nodes[0].neighbor.push_back(&nodes[1]);
//	
//	nodes[1].neighbor.push_back(&nodes[5]);
//	nodes[1].neighbor.push_back(&nodes[2]);
//	nodes[1].neighbor.push_back(&nodes[0]);
//
//	nodes[2].neighbor.push_back(&nodes[4]);
//	nodes[2].neighbor.push_back(&nodes[3]);
//	nodes[2].neighbor.push_back(&nodes[1]);
//
//	nodes[3].neighbor.push_back(&nodes[2]);
//
//	nodes[4].neighbor.push_back(&nodes[2]);
//
//	nodes[5].neighbor.push_back(&nodes[6]);
//	nodes[5].neighbor.push_back(&nodes[2]);
//
//	nodes[6].neighbor.push_back(&nodes[5]);
//}

void depthFirstSearch(Graph* graph)
{
	if (graph == nullptr) return;

	Node* sourceNode = graph->allNodes[0];
	
	std::stack<Node*> nodeStack;
	nodeStack.push(sourceNode);

	printf("Depth First Search Start!\n");
	while (!nodeStack.empty())
	{
		Node* tmpNode = nodeStack.top();
		nodeStack.pop();
		tmpNode->isVisited = true;
		printf("%d\n", tmpNode->value);

		for (int i = 0; i < tmpNode->neighbor.size(); ++i)
		{
			if (!(tmpNode->neighbor[i]->isVisited))
			{
				nodeStack.push(tmpNode->neighbor[i]);
			}
		}
		
	}

}



int _tmain(int argc, _TCHAR* argv[])
{
	Graph*graph = new Graph;
	Node*nodes = new Node[7];

	for (int i = 0; i < 7; ++i)
	{
		nodes[i].value = i;
		graph->allNodes.push_back(&nodes[i]);
	}

	nodes[0].neighbor.push_back(&nodes[1]);

	nodes[1].neighbor.push_back(&nodes[0]);
	nodes[1].neighbor.push_back(&nodes[5]);
	nodes[1].neighbor.push_back(&nodes[2]);

	nodes[2].neighbor.push_back(&nodes[1]);
	nodes[2].neighbor.push_back(&nodes[4]);
	nodes[2].neighbor.push_back(&nodes[3]);

	nodes[3].neighbor.push_back(&nodes[2]);

	nodes[4].neighbor.push_back(&nodes[2]);

	nodes[5].neighbor.push_back(&nodes[6]);
	nodes[5].neighbor.push_back(&nodes[2]);

	nodes[6].neighbor.push_back(&nodes[5]);
	//makeGraph(graph, nodes);
	depthFirstSearch(graph);

	getchar();
	getchar();

	delete graph;
	delete[] nodes;
	
	return 0;
}

