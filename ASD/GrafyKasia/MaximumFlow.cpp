#include "MaximumFlow.h"
#include "GraphAlgorithms.h"
#include "Graph.h"

using namespace std;
using namespace AMDGraph;


double maximumFlow(Graph* g, int s, int t) {
	return 0;
}

vector<int> findAugmentingPath(Graph* g, int s, int t) {
	
	vector<int> powiekszajaca;
	vector<int> pusty;

	int n = g->getVerticesCount();

	int aktualny = s;
	powiekszajaca.push_back(s);
	

	//Czy odwiedzone, wszystkie nie i pierwszy tak
	int* czy_odwiedzony = new int[n]();
	czy_odwiedzony[0] = 1;


	int do_akt = 0;//Liczba krawedzi do aktualnego wierzcholka

	//Dop�ki nie zako�cz� �cie�ki t
	while (powiekszajaca.back() != t)
	{
		set<Edge> sasiedzi = g->getOutEdges(aktualny);
		
		//Przechodz� po s�siadach mojego wierzcho�ka

		for (set<Edge>::iterator it = sasiedzi.begin(); it != sasiedzi.end(); ++it)
		{

			//O ile kraw�d� dobrze skierowana to tam id� i zamie� aktualny wierzcho�ek
			if ((*it).getFrom() == aktualny)
			{
				//odwiedzam, oznaczam jako aktualny
				czy_odwiedzony[(*it).getTo()]=1;
			
				aktualny = (*it).getTo();
				
				powiekszajaca.push_back(aktualny);
				
				break;	
			}
			//pop_back - usuwa ostatni element vectora

			//Je�eli z aktualnego wierzcho�ka nie ma kraw�dzi wychodz�cych zwr�� pusty wektor
			if (g->outDegree(aktualny) == 0)
			{
				return pusty;
			}
			
		}
	}
	

	return powiekszajaca;

}

void augmentFlow(Graph* g, vector<int> path)
{
	int n = g->getVerticesCount();
	set<Edge> wszystkie = g->getEdgesSet();

	int minimum = 2654654;
	//begin - wskazuje na pierwszy elemtn
	int poprzednik = *path.begin();
	
	//Znajduje minimum w tej �ciezce
	for (vector<int>::iterator it = path.begin(); it != path.end(); ++it)
	{
		//Aktualna krawedz skad
		//double waga= getEdgeWeight((*it),poprzednik)
	//	if (waga< minimum)
	//	{
	//		poprzednik = (*it);
	//	}
	}




}
