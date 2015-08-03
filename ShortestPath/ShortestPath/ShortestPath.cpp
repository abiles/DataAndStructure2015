// ShortestPath.cpp : 콘솔 응용 프로그램에 대한 진입점을 정의합니다.
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

