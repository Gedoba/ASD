#include "CityPlanner.h"
#include "GraphAlgorithms.h"

vector<int> AMDGraph::planCity(Graph* city, Graph* cost, int start)
{
	int n=city->getVerticesCount();
	int* stopien = new int[n];
	for (int i = 0; i < n; i++)
	{
		stopien[i] = 0;
	}

	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < n; j++)
		{
			if (i != j)
			{
				if (city->containsEdge(i, j) == 1)
				{
					stopien[i]++;
					stopien[j]++;
				}
			}
		}

	}

	for (int i = 0; i < n; i++)
	{
		stopien[i] = stopien[i] / 2;
	}

	list<int> nieparzysci;
	
	for (int i = 0; i < n; i++)
	{
		if (stopien[i] % 2 == 1)
		{
			nieparzysci.push_back(i);

		}
	}
	
	int pom1; //Sk¹d najtañsza krawêdŸ
	int pom2; //Dok¹d najtañsza krawêdŸ
	
	//Szukam minimalnych wag krawêdzi, ale sposród tylko tych które s¹ miêdzy wierzcho³kami nale¿¹cymi do listy wy¿ej
	//Ile krawêdzi dodac do grafu
	int ilewliscie = nieparzysci.size();

	for (int k = 0; (k < ilewliscie / 2); k++)
	{	
		int koszt = 1000000;
		for (list<int>::iterator it = nieparzysci.begin(); it != nieparzysci.end(); ++it)
		{
			for (list<int>::iterator ite = nieparzysci.begin(); ite != nieparzysci.end(); ++ite)
			{
				if (*it != *ite && city->containsEdge(*it,*ite)==0)
				{
					
					Edge pom = cost->getEdge(*it,*ite);
					int a = pom.getWeight();
					if (a < koszt)
					{
						pom1 = *it;
						pom2 = *ite;
						
					}
				}

			}
		}
		//Mam minimalny wierzcho³ek, dodaje go do grafu city i usuwam z listy, ¿eby znowu jej nie znaleŸæ
		//Znaleziona krawêdŸ o minimalnej wadze krawêdŸ (pom1, pom2)
		
	
		city->addEdge(pom1,pom2);
		
		nieparzysci.remove(pom1);
		nieparzysci.remove(pom2);
		
	}
	




	return vector<int>();
}
