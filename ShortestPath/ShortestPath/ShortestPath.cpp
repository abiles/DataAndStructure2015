// ShortestPath.cpp : �ܼ� ���� ���α׷��� ���� �������� �����մϴ�.
//

#include "stdafx.h"

struct Vertex
{
	std::vector<Edge*> IngoingEdges;
};

struct Edge
{
	Vertex* startVertex = nullptr;
	Vertex* endVertex = nullptr;
	int		weight = 0;
};

struct Graph
{
	std::vector<Vertex*> vertices;
};


int shortestPath(Graph* graph, Vertex* source)
{

}

int _tmain(int argc, _TCHAR* argv[])
{


	return 0;
}

