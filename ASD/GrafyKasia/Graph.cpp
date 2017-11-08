#include "Graph.h"
using namespace AMDGraph;

const double Epsilon = 1e-5;

Edge::Edge(int from, int to, bool directed, double weight)
{
	this->from = from;
	this->to = to;
	this->directed = directed;
	this->weight = weight;
}

Edge::Edge(const Edge& copy)
{
	this->from = copy.from;
	this->to = copy.to;
	this->directed = copy.directed;
	this->weight = copy.weight;
}

int Edge::getFrom() const
{
	return from;
}

int Edge::getTo() const
{
	return to;
}

bool AMDGraph::Edge::isDirected() const
{
	return directed;
}

double Edge::getWeight() const
{
	return weight;
}

int AMDGraph::Edge::getMinVertex() const
{
	return from < to ? from : to;
}

int AMDGraph::Edge::getMaxVertex() const
{
	return from > to ? from : to;
}

bool AMDGraph::operator==(const Edge& e1, const Edge& e2)
{
	if(e1.isDirected())
		return e1.getFrom() == e2.getFrom() && e1.getTo() == e2.getTo()
			&& abs(e1.getWeight()-e2.getWeight()) < Epsilon 
			&& e1.isDirected() == e2.isDirected();
	return ((e1.getFrom() == e2.getFrom() && e1.getTo() == e2.getTo())
		|| (e1.getFrom() == e2.getTo() && e1.getTo() == e2.getFrom()))
		&& abs(e1.getWeight() - e2.getWeight()) < Epsilon
		&& e1.isDirected() == e2.isDirected();
}

bool AMDGraph::operator!=(const Edge& e1, const Edge& e2)
{
	return !(e1 == e2);
}

bool AMDGraph::operator<(const Edge& e1, const Edge& e2)
{
	if (e1.isDirected() != e2.isDirected())
		return !e1.isDirected();
	if(e1.isDirected())
		return e1.getFrom() < e2.getFrom() 
			|| (e1.getFrom() == e2.getFrom() && e1.getTo() < e2.getTo())
			|| (e1.getFrom() == e2.getFrom() && e1.getTo() == e2.getTo() && e1.getWeight()-e2.getWeight() < -Epsilon);
	return e1.getMinVertex() < e2.getMinVertex()
		|| (e1.getMinVertex() == e2.getMinVertex() && e1.getMaxVertex() < e2.getMaxVertex())
		|| (e1.getMinVertex() == e2.getMinVertex() && e1.getMaxVertex() == e2.getMaxVertex() && e1.getWeight() - e2.getWeight() < -Epsilon);
}

bool AMDGraph::operator<=(const Edge& e1, const Edge& e2)
{
	return e1 < e2 || e1 == e2;
}

bool AMDGraph::operator>(const Edge& e1, const Edge& e2)
{
	return !(e1 <= e2);
}

bool AMDGraph::operator>=(const Edge& e1, const Edge& e2)
{
	return !(e1 < e2);
}



Graph::Graph(int verticesCount, bool directed)
	: verticesCount(verticesCount), directed(directed){}

Graph::~Graph(){}

bool Graph::isDirected() const { return directed; }

int Graph::getVerticesCount() const { return verticesCount; }

void Graph::addEdge(int from, int to, double weight) { addEdge(Edge(from, to, directed, weight)); }

void Graph::removeEdge(int from, int to) { removeEdge(Edge(from, to, 1)); }


int Graph::getEdgesCount()
{
	int count = 0;
	for (int i = 0; i < getVerticesCount(); ++i)
		count += outDegree(i);
	if (!isDirected())
		return count / 2;
	return count;
}

int Graph::outDegree(int vertex)
{
	return getOutEdges(vertex).size();
}

int Graph::inDegree(int vertex)
{
	return getInEdges(vertex).size();
}

bool AMDGraph::Graph::empty()
{
	for (int i = 0; i < getVerticesCount(); ++i)
		if (!getOutEdges(i).empty())
			return false;
	return true;
}

set<Edge> Graph::getEdgesSet() const
{
	set<Edge> edges;
	for (int i = 0;i < getVerticesCount();++i)
	{
		set<Edge> out = getOutEdges(i);
		edges.insert(out.begin(), out.end());
	}
	if (!isDirected())
	{
		for (auto e = edges.begin(); e != edges.end();++e)
			if (e->getFrom() > e->getTo())
			{
				e = edges.erase(e);
				--e;
			}
	}
	return edges;
}