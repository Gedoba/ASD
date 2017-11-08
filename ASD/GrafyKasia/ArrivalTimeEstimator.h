#pragma once
#include <vector>
#include "Graph.h"

std::vector<int> findArrivals(int nStops, std::vector<std::vector<std::pair<int, int>>> lines, 
	std::pair<int, int> start);

AMDGraph::Graph* makeGraph(int nStops, std::vector<std::vector<std::pair<int, int>>> lines,
	std::pair<int, int> start, vector<pair<int, int>>* byStop);