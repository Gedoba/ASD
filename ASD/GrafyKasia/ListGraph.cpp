#include <algorithm>
#include <cmath>
#include"Graph.h"
using namespace AMDGraph;

ListGraph::ListGraph(int verticesCount, bool directed) 
	: Graph(verticesCount, directed)
{
	edgeList = new list<Edge>[verticesCount];
}

ListGraph::ListGraph(const Graph& other)
	: Graph(other.getVerticesCount(), other.isDirected())
{
	edgeList = new list<Edge>[other.getVerticesCount()];
	for (Edge e : other.getEdgesSet())
		addEdge(e);
}

ListGraph::~ListGraph()
{
	delete[] edgeList;
}

void ListGraph::addEdge(const Edge& edge)
{
	list<Edge>& l = edgeList[edge.getFrom()];
	if (find(l.begin(), l.end(), edge) != l.end())
		return;
	edgeList[edge.getFrom()].push_back(edge);
	if (!isDirected())
		edgeList[edge.getTo()].push_back(Edge(edge.getTo(), edge.getFrom(), isDirected(), edge.getWeight()));
}

void ListGraph::removeEdge(const Edge& edge)
{
	for (auto it = edgeList[edge.getFrom()].begin(); it != edgeList[edge.getFrom()].end();) {

		if (it->getFrom() == edge.getFrom() && it->getTo() == edge.getTo())
			it = edgeList[edge.getFrom()].erase(it);
		else
			it++;
	}

	if (!isDirected()) {
		for (auto it = edgeList[edge.getTo()].begin(); it != edgeList[edge.getTo()].end();) {

			if (it->getFrom() == edge.getTo() && it->getTo() == edge.getFrom())
				it = edgeList[edge.getTo()].erase(it);
			else
				it++;
		}
	}
}

bool ListGraph::containsEdge(int from, int to)
{
	for (Edge e : edgeList[from])
		if (e.getTo() == to)
			return true;
	return false;
}

set<Edge> ListGraph::getOutEdges(int v) const
{
	return set<Edge>(edgeList[v].begin(), edgeList[v].end());
}

set<Edge> ListGraph::getInEdges(int v)
{
	set<Edge> edges;
	for (int w = 0; w < getVerticesCount(); ++w)
	{
		for (list<Edge>::iterator it = edgeList[w].begin(); it != edgeList[w].end(); ++it)
			if (it->getTo() == v)
				edges.insert(*it);
	}
	return edges;
}

double ListGraph::getEdgeWeight(int u, int v) 
{
	for (Edge e : edgeList[u])
		if (e.getTo() == v)
			return e.getWeight();
	return 0;
}

void ListGraph::changeEdgeWeight(int u, int v, double delta)
{
	double w = getEdgeWeight(u, v);
	Edge e = Edge(u, v, isDirected(), w + delta);
	if (containsEdge(u, v)) {
		removeEdge(Edge(u, v));
	}
	if(e.getWeight() != 0)
		addEdge(e);
}
