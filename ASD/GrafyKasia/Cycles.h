#pragma once
#include <vector>
#include <set>
#include <algorithm>
#include "Graph.h"

using namespace AMDGraph;

set<Edge> addCycles(set<Edge> c1, set<Edge> c2);
vector<set<Edge>> getFundamentalCycles(Graph* g, Graph* tree);
namespace AMDGraph
{
	class GraphVisitor
	{
	public:
		virtual bool willEnterVertex(int from, int to) = 0;
		virtual void didEnterVertex(int v) = 0;
	};

	void dfs(Graph&, GraphVisitor&);
	void bfs(Graph&, GraphVisitor&);

	class PathsFinder : public GraphVisitor
	{
	public:
		PathsFinder(Graph& graph);
		bool willEnterVertex(int from, int to);
		void didEnterVertex(int v);
		set<Edge> getPathBetween(int u, int v);
	private:
		set<Edge> getPathToRoot(int u);
		Graph& graph;
		bool* visited;
		int* parent;
	};
}
