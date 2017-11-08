#pragma once
#include <vector>
#include "Graph.h"

using namespace std;

AMDGraph::Graph* makeGraph(int n, vector<vector<double>> rates);
double exchangeCurrencies(int n, vector<vector<double>> rates, int k, 
	std::vector<int>& path);