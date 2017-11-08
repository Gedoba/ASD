#include "TSPGreedySolver.h"

vector<int> TSPAlgorithmA(Graph* graph)
{
	vector<int> cykl;
	set<Edge> zbior_krawedzi = graph->getEdgesSet();
	int n = graph->getVerticesCount();
	
	bool* czy_odwiedzilam = new bool[n];
	//Pierwszy odwiedzam od razu
	czy_odwiedzilam[0] = 1;
	for (int i = 1; i < n; i++)
	{
		czy_odwiedzilam[i] = false;
	}
	//Wrzucam pierwszy wierzcholek do cyklu
	cykl.push_back(0);

	

	for (int i = 0; i < n; i++)
	{
		
		set<Edge> sasiedzi = graph->getOutEdges(i);	//Lista s¹siadów
		//int k = graph->outDegree(i);//Licznoœæ s¹siadów i
		int wierzch; //wierzcholek po ktorym chodze
		int waga; //waga do szukania minimalnej
		
		//Szukam najtañszego
		for (set<Edge>::iterator it = sasiedzi.begin(); it != sasiedzi.end(); ++it)
		{

			int pom = (*it).getTo();
			//O ile nie odwiedzony
			if (czy_odwiedzilam[pom] == 0)
			{
				waga = (*(it)).getWeight();
				wierzch =pom;

			}
			
		}
		

		//Odwiedzam ten najtañszy
		czy_odwiedzilam[wierzch] = true;
		cykl.push_back(wierzch);

	}
	

	cykl.push_back(0);


	return cykl;
}


vector<int> TSPAlgorithmB(Graph* graph)
{
	return vector<int>();
}


