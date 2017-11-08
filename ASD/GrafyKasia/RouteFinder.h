#pragma once
#include <vector>
#include <set>
#include "Graph.h"

namespace AMDGraph 
{

	class GraphVisitor
	{
	public:
		virtual void didEnterEdge(int from, int to) {}
		virtual void didEnterVertex(int v) {}
	};

	void bfs(Graph& g, GraphVisitor& visitor);
	void bfsComponent(Graph& g, GraphVisitor& visitor, int v);
	
	void dfs(Graph&, GraphVisitor&);
	void dfsComponent(Graph& g, GraphVisitor& visitor, int v);
	bool isBridge(Graph& g, const Edge&);

	vector<int> findRoute(const std::set<int>& stops, int start, 
		const std::vector<std::vector<int>>& timetable);
}
