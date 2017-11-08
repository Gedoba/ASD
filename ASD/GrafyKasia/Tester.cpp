#include "Tester.h"


bool checkIfTree(Graph &graph, int root)
{
	bool* visited = new bool[graph.getVerticesCount()];
	for (int i = 0; i < graph.getVerticesCount(); ++i) {
		visited[i] = false;
	}

	stack<int> st = stack<int>();
	st.push(root);
	visited[root] = true;
	while (!st.empty())
	{
		int v = st.top();
		st.pop();
		auto neighbours = graph.getOutEdges(v);
		for (auto it = neighbours.begin(); it != neighbours.end(); it++)
		{
			int s = it->getTo();
			if (visited[s]) {
				continue;
			}
			st.push(s);
			visited[s] = true;
		}
	}

	for (int i = 0; i < graph.getVerticesCount(); i++) {
		if (visited[i] == false)
			return false;
	}

	return graph.getEdgesCount() == graph.getVerticesCount() - 1;
}


//tri-version
double test(Graph& graph, int root)
{
	double sum = 0;

	bool* visited = new bool[graph.getVerticesCount()];
	for (int i = 0; i < graph.getVerticesCount(); ++i) {
		visited[i] = false;
	}

	stack<int> st = stack<int>();
	stack<int> par = stack<int>();
	st.push(root);
	par.push(-1);
	visited[root] = true;
	while (!st.empty())
	{
		int v = st.top();
		int p = par.top();
		st.pop();
		par.pop();
		auto neighbours = graph.getOutEdges(v);
		for (auto it = neighbours.begin(); it != neighbours.end(); it++)
		{
			int s = it->getTo();
			if (visited[s]) {
				continue;
			}
			sum += it->getWeight();
			st.push(s);
			par.push(v);
			visited[s] = true;
		}
	}
	return sum;
}