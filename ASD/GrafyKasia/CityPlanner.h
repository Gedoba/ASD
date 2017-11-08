#pragma once
#include <vector>
#include <set>
#include "Graph.h"

namespace AMDGraph
{
	vector<int> planCity(Graph* city, Graph* cost, int start = 0);
}
