#include "PrepareFlow.h"

Graph* blockadeHelper(int n, int officeA, int officeB, vector<pair<int, int>> roads)
{
	Graph* graf = new ListGraph(n, true);

	for (auto it = roads.begin(); it != roads.end(); ++it)
	{
			graf->addEdge((*it).first, (*it).second);
			graf->addEdge((*it).second, (*it).first);
		
	}

	return graf;
}

// Wartoœæ 0 w tablicy capacity oznacza, ¿e w danym mieœcie nie ma ograniczenia
Graph* transportHelper(Graph * map, int capacity[], int start, vector<int> ends)
{
	int miast = map->getVerticesCount();
	
	

	Graph* nowy = new ListGraph(map->getVerticesCount()+1, true);


	for (int i = 0; i < miast; i++)
	{
		for (int j = 0; j < miast; j++)
		{
			if (map->containsEdge(i, j))
			{
				nowy->addEdge(i,j,capacity[i]);
			}
		}

	}


	//Ile koñców
	int n = ends.size();

	int* wagi_poprzednich = new int[n]; //Wagi ostatnich

	for (int i = 0; i < n; i++)
		wagi_poprzednich = 0;


	//Liczê wagi koñców
	for (vector<int>::iterator it = ends.begin(); it != ends.end(); ++it)
	{
		for (int k = 0; k < miast; k++)
		{
			if (map->containsEdge((*it), k))
				wagi_poprzednich[(*it)] = wagi_poprzednich[(*it)] + capacity[(*it)];

		}
	}

	//£¹czê koñce z ostatnim wierzcho³kiem
	for (vector<int>::iterator it = ends.begin(); it != ends.end(); ++it)
	{
		nowy->addEdge((*it), miast +1,wagi_poprzednich[(*it)]);
	}

	


	

	return nowy;
}
