#include "Graph.h"
using namespace AMDGraph;

MatrixGraph::MatrixGraph(int verticesCount, bool directed)
	: Graph(verticesCount, directed) 
{
	weightMatrix = new double*[verticesCount];
	existMatrix = new bool*[verticesCount];
	for (int i = 0; i < verticesCount; ++i)
	{
		weightMatrix[i] = new double[verticesCount];
		existMatrix[i] = new bool[verticesCount];
		for (int j = 0; j < verticesCount; ++j)
		{
			weightMatrix[i][j] = 0;
			existMatrix[i][j] = false;
		}
	}		
}

MatrixGraph::~MatrixGraph()
{
	for (int i = 0; i < getVerticesCount(); ++i)
	{
		delete[] weightMatrix[i];
		delete[] existMatrix[i];
	}
	delete[] weightMatrix;
	delete[] existMatrix;
}

void MatrixGraph::addEdge(const Edge& e) 
{
	weightMatrix[e.getFrom()][e.getTo()] = e.getWeight();
	existMatrix[e.getFrom()][e.getTo()] = true;
	if (!isDirected())
	{
		weightMatrix[e.getTo()][e.getFrom()] = e.getWeight();
		existMatrix[e.getTo()][e.getFrom()] = true;
	}
}

void MatrixGraph::removeEdge(const Edge& e)
{
	weightMatrix[e.getFrom()][e.getTo()] = 0;
	existMatrix[e.getFrom()][e.getTo()] = false;
	if (!isDirected())
	{
		weightMatrix[e.getTo()][e.getFrom()] = 0;
		existMatrix[e.getTo()][e.getFrom()] = false;
	}
}

bool MatrixGraph::containsEdge(int from, int to)
{
	return existMatrix[from][to];
}

set<Edge> MatrixGraph::getOutEdges(int v) const
{
	set<Edge> edges;
	for (int i = 0; i < getVerticesCount();++i)
		if (existMatrix[v][i])
			edges.insert(Edge(v, i, isDirected(), weightMatrix[v][i]));
	return edges;
}

set<Edge> MatrixGraph::getInEdges(int v)
{
	set<Edge> edges;
	for (int i = 0; i < getVerticesCount();++i)
		if (existMatrix[i][v])
			edges.insert(Edge(i, v, isDirected(), weightMatrix[i][v]));
	return edges;
}



double MatrixGraph::getEdgeWeight(int from, int to)
{
	return weightMatrix[from][to];
}

void MatrixGraph::changeEdgeWeight(int from, int to, double add)
{
	weightMatrix[from][to] += add;
	if (isDirected())
		weightMatrix[to][from] += add;
}
