#include "RouteFinder.h"
#include <map>
#include <queue>

using namespace AMDGraph;

vector<int> AMDGraph::findRoute(const set<int>& stops, int start, const vector<vector<int>>& timetable)
{
	vector<int> droga;
	int n = timetable.size();
	Graph *graf = new ListGraph(n*n, false);

	for (auto it = timetable.begin(); it != timetable.end(); ++it)
	{
		for (auto it2 = timetable.begin(); it2 != timetable.end(); ++it2)
		{
			graf.addEdge((*it), (*it2));
		}
	}

	int przy =stops.size();
	


	for (auto it = timetable.begin(); it != timetable.end(); ++it)
	{
		for (auto it2 = timetable.begin(); it2 != timetable.end(); ++it2)
		{
			Edge krawedz = ((*it), (*it2));
			if ((isBridge(graf, krawedz)==true &&  );

			droga.push_back(krawedz);
		}
	}
	



	return droga;
}