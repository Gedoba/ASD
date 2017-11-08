#pragma once
#include "Graph.h"

namespace AMDGraph {
	class GraphVisitor
	{
	public:
		virtual void didEnterEdge(int from, int to) {}
		virtual void didEnterVertex(int v) {}
	};

	class ReachableFinder : public GraphVisitor {
		set<int> reachableVertices;
	public:
		virtual void didEnterVertex(int v) override;
		const set<int>& getReachableVertices();
	};

	void bfs(Graph& g, GraphVisitor& visitor);
	void bfsComponent(Graph& g, GraphVisitor& visitor, int v);

	void dfs(Graph&, GraphVisitor&);
	void dfsComponent(Graph& g, GraphVisitor& visitor, int v);

	double* bellmanFord(Graph& g, double** costs, int** previous);
}