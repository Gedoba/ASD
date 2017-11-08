#pragma once
#include<set>
#include<list>
#include<algorithm>
using namespace std;

namespace AMDGraph
{
	class Edge
	{
	private:
		int from, to;
		bool directed;
		double weight;
	public:
		Edge(int, int, bool = false, double = 1);
		Edge(const Edge& copy);
		int getFrom() const;
		int getTo() const;
		bool isDirected() const;
		double getWeight() const;

		int getMinVertex() const;
		int getMaxVertex() const;
	};
	bool operator==(const Edge& e1, const Edge& e2);
	bool operator!=(const Edge& e1, const Edge& e2);
	bool operator<(const Edge& e1, const Edge& e2);
	bool operator<=(const Edge& e1, const Edge& e2);
	bool operator>(const Edge& e1, const Edge& e2);
	bool operator>=(const Edge& e1, const Edge& e2);

	class Graph
	{
	private:
		int verticesCount;
		bool directed;
	protected:
		Graph(int verticesCount, bool directed);
		virtual void addEdge(const Edge& edge) = 0;
	public:
		bool isDirected() const;
		int getVerticesCount() const;

		void addEdge(int from, int to, double weight = 1);

		virtual void removeEdge(const Edge& edge) = 0;
		void removeEdge(int from, int to);

		virtual bool containsEdge(int from, int to) = 0;

		virtual int outDegree(int vertex);
		virtual set<Edge> getOutEdges(int v) const = 0;
		virtual int getEdgesCount();

		virtual set<Edge> getInEdges(int v) = 0;
		virtual int inDegree(int vertex);

		virtual double getEdgeWeight(int from, int to) = 0;
		virtual void changeEdgeWeight(int from, int to, double delta) = 0;

		bool empty();
		set<Edge> getEdgesSet() const;
		
		virtual ~Graph();
	};

	class MatrixGraph : public Graph
	{
	private:
		double** weightMatrix;
		bool** existMatrix;
	protected:
		virtual void addEdge(const Edge& edge);
	public:
		MatrixGraph(int verticesCount, bool directed);
		virtual void removeEdge(const Edge& edge);

		virtual bool containsEdge(int from, int to);

		virtual set<Edge> getOutEdges(int v) const;

		virtual set<Edge> getInEdges(int v);

		virtual double getEdgeWeight(int from, int to);
		virtual void changeEdgeWeight(int from, int to, double add);	

		virtual ~MatrixGraph();
	};

	class ListGraph : public Graph
	{
	private:
		list<Edge>* edgeList;
	protected:
		virtual void addEdge(const Edge& edge);
	public:
		ListGraph(int verticesCount, bool directed);
		ListGraph(const Graph& other);
		virtual void removeEdge(const Edge& edge);

		virtual bool containsEdge(int from, int to);

		virtual set<Edge> getOutEdges(int v) const;
		virtual set<Edge> getInEdges(int v);

		virtual double getEdgeWeight(int from, int to);
		virtual void changeEdgeWeight(int from, int to, double add);

		~ListGraph();
	};
}