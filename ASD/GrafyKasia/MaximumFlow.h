#pragma once
#include <vector>
#include "Graph.h"
using namespace AMDGraph;

double maximumFlow(Graph* g, int s, int t);
std::vector<int> findAugmentingPath(Graph* g, int s, int t);
void augmentFlow(Graph* g, std::vector<int> path);
