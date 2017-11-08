#include<queue>
#include "Graph.h"
#include "GraphAlgorithms.h"

using namespace AMDGraph;

namespace AMDGraph 
{
	void dfsR(Graph& g, GraphVisitor& visitor, int v, bool* visited);

	void dfs(Graph& g, GraphVisitor& visitor)
	{
		bool* visited = new bool[g.getVerticesCount()];

		for (int i = 0; i < g.getVerticesCount(); ++i) {
			visited[i] = false;
		}
		for (int i = 0;i < g.getVerticesCount();++i)
			if (!visited[i])
			{
				visitor.didEnterEdge(-1, i);
				dfsR(g, visitor, i, visited);
			}
		g.getEdgesCount();
		delete[] visited;
	}

	void dfsComponent(Graph& g, GraphVisitor& visitor, int v) 
	{
		bool * visited = new bool[g.getVerticesCount()];
		for (int i = 0;i < g.getVerticesCount();++i)
			visited[i] = false;
		visitor.didEnterEdge(-1, v);
		dfsR(g, visitor, v, visited);
		delete[] visited;
	}

	void dfsR(Graph& g, GraphVisitor& visitor, int v, bool* visited)
	{
		visited[v] = true;
		visitor.didEnterVertex(v);
		set<Edge> edges = g.getOutEdges(v);
		for (auto it = edges.begin(); it != edges.end(); ++it) {
			visitor.didEnterEdge(v, it->getTo());
			if (!visited[it->getTo()]) {
				dfsR(g, visitor, it->getTo(), visited);
			}
		}
	}

	void bfsComponent(Graph& g, GraphVisitor& visitor, int v);
	void bfsComponent(Graph& g, GraphVisitor& visitor, int v, bool * visited);

	void bfs(Graph& g, GraphVisitor& visitor) {
		bool* visited = new bool[g.getVerticesCount()];
		for (int i = 0; i < g.getVerticesCount(); ++i) {
			visited[i] = false;
		}

		for (int i = 0;i < g.getVerticesCount();++i)
			if (!visited[i])
				bfsComponent(g, visitor, i, visited);
		delete[] visited;
	}

	void bfsComponent(Graph& g, GraphVisitor& visitor, int v) {
		bool* visited = new bool[g.getVerticesCount()];
		for (int i = 0; i < g.getVerticesCount(); ++i) {
			visited[i] = false;
		}
		bfsComponent(g, visitor, v, visited);
		delete[] visited;
	}

	void bfsComponent(Graph& g, GraphVisitor& visitor, int v, bool* visited) {
		queue<int> q;
		visitor.didEnterEdge(-1, v);
		visited[v] = true;
		q.push(v);
		while (!q.empty()) {
			int v = q.front();
			q.pop();
			visitor.didEnterVertex(v);
			visited[v] = true;
			set<Edge> outEdges = g.getOutEdges(v);
			for (auto e = outEdges.begin(); e != outEdges.end();++e) {
				visitor.didEnterEdge(e->getFrom(), e->getTo());
				if (!visited[e->getTo()])
					q.push(e->getTo());
			}
		}

	}

	double* bellmanFord(Graph& g, double** costs, int** previous) {
		double* d = new double[g.getVerticesCount()];
		int* prev = new int[g.getVerticesCount()];
		for (int i = 0;i < g.getVerticesCount();++i) {
			d[i] = 1e7;
			prev[i] = -1;
		}
		d[0] = 0;
		for (int i = 1;i < g.getVerticesCount();++i) {
			for (Edge e : g.getEdgesSet()) {
				if (d[e.getTo()] > d[e.getFrom()] + e.getWeight()) {
					d[e.getTo()] = d[e.getFrom()] + e.getWeight();
					prev[e.getTo()] = e.getFrom();
				}
			}
		}
		for (Edge e : g.getEdgesSet()) {
			if (d[e.getTo()] > d[e.getFrom()] + e.getWeight()) {
				throw new exception("Negative cycle");
			}
		}

		*costs = d;
		*previous = prev;
	}

	void ReachableFinder::didEnterVertex(int v) {
		reachableVertices.insert(v);
	}
	const set<int>& ReachableFinder::getReachableVertices() {
		return reachableVertices;
	}
}