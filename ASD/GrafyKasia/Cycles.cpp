#include "Cycles.h"
using namespace std;
using namespace AMDGraph;

set<Edge> addCycles(set<Edge> c1, set<Edge> c2)
{
	//Uzupelnij
	return set<Edge>();
}

vector<set<Edge>> getFundamentalCycles(Graph* g, Graph* tree)
{

	vector<set<Edge>> krawedzie;
	PathsFinder pf(*tree);
	dfs(*tree, pf);

	return krawedzie;
}

PathsFinder::PathsFinder(Graph& graph) 
	: graph(graph)
{
	int n = graph.getVerticesCount();
	visited = new bool[n];
	parent = new int[n];
	for (int i = 0; i < n; i++)
	{
		visited[i] = 0;
	}


}

// Metoda jest wywoływana kiedy 
// from - numer wierzchołka, z którego zostaje odwiedzony
// to   - numer wierzchołka, który zostanie odwiedzony
// Uwaga: dla pierwszego wierzchołka w składowej: from = -1, a to = (jego numer)
// Returns: jeśli metoda zwróci false, to wierzchołek nie zostanie odwiedzony
bool PathsFinder::willEnterVertex(int from, int to)
{
	if (visited[to] == true)
	{
		graph.removeEdge(from, to);
		return true;
	}
	return false;
}

void PathsFinder::didEnterVertex(int v)
{
	//puste
}

set<Edge> AMDGraph::PathsFinder::getPathBetween(int u, int v)
{
	set<Edge> drogau=getPathToRoot(u);
	set<Edge> drogav= getPathToRoot(v);
	set<Edge> ostateczna=drogav;
	int n = 0;
	//Dodam do zbioru krawędzie u
	for (set<Edge>::iterator it = drogau.begin(); it != drogau.end(); ++it)
	{
		
	}
	//Usune ze zbioru krawedzie powtarzające się
	for (set<Edge>::iterator it = drogau.begin(); it != drogau.end(); ++it)
	{
		for (set<Edge>::iterator it2 = drogav.begin(); it2 != drogav.end(); ++it2)
		{
		
			if ((*it) == (*it2))
				ostateczna.insert(*it);

		}
	}


	//Uzupelnij
	return ostateczna;
}

set<Edge> AMDGraph::PathsFinder::getPathToRoot(int u)
{
	
	int k = 0;
	set<Edge> path;




	//Nieobowiazkowe
	return set<Edge>();
}


