#pragma once
#include <vector>
#include "Graph.h"

using namespace std;
using namespace AMDGraph;

Graph* blockadeHelper(int n, int officeA, int officeB, vector<pair<int, int>> roads);

Graph* transportHelper(Graph* map, int capacity[], int start, vector<int> ends);
