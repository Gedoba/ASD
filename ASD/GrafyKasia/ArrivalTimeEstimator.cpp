#include <map>
#include "ArrivalTimeEstimator.h"
#include "Graph.h"
#include "GraphAlgorithms.h"

using namespace AMDGraph;
using namespace std;

vector<int> findArrivals(int nStops,
	vector<vector<pair<int, int>>> lines,
	std::pair<int, int> start) {
	return vector<int>();
}

Graph* makeGraph(int nStops, vector<vector<pair<int, int>>> lines,
	std::pair<int, int> start, vector<pair<int, int>>* byStop) {

	int n = lines.size();


	int wierzcholki = 0;
	//Szukam wielkosci grafu - ide po wektorach i sprawdzam ich licznoœæ
	for (int i = 0; i < n; i++)
	{
		int m = lines[i].size();
		wierzcholki = m + wierzcholki;
	}
	Graph* graf = new ListGraph(wierzcholki, true);



	//Idê po ca³ym grafie, 
	for (int i = 0; i < nStops; i++)
	{
		//sk¹d idzie krawêdz - z jakiego przystanku idziemy
		for (auto it = byStop[i].begin();it != byStop[i].end();++it)
		{
			//do jakiego przystanku jedziemy?
			for (auto iter = byStop[i].begin(); iter != byStop[i].end(); ++iter)
			{
				int czas_odj = it->second;
				int czas_przyj = iter->second;
			
				if(czas_przyj<=czas_odj)
				graf->addEdge(it->first, iter->first, czas_przyj - czas_odj);

			}

		}
	}

	//Dodam krawêdzie na których siê czeka
	for (int i = 0; i < nStops; i++)
	{
		
	}


		
	return graf;
}

