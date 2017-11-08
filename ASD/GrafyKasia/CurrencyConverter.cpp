#include "CurrencyConverter.h"
#include "Graph.h"

using namespace AMDGraph;
using namespace std;

double exchangeCurrencies(int n, vector<vector<double>> rates, int k,
	vector<int>& path) {
	Graph* g = makeGraph(n, rates);
	double* koszt_drogi = new double[n];
	int* przedostatni = new int[n];
	for (int i = 1; i < n; i++)
	{
		koszt_drogi[i] = 1000;
		przedostatni[i] = -1;
	}

	koszt_drogi[0] = 0;

	
	double koszt = 1000;
	int dlugosc = 0;
	int wierzcholek = 0;
	int wierzcholek2 = 0;
	
	
	Graph* nowy = g;
	Graph* S = new ListGraph(n, true); //nowy graf  do którego bêdê wrzucaæ krawêdzie te co mnie interesuj¹


	while (wierzcholek!=k)
	{

		set<Edge> wychodzace = nowy->getOutEdges(wierzcholek);
		//Szukam najtañszego wierzcho³ka - wierzcholek
		for (set<Edge>::iterator it = wychodzace.begin(); it != wychodzace.end(); ++it)
		{
			if ((*it).getWeight() <= koszt)
			{
				koszt = (*it).getWeight();
				wierzcholek2 = (*it).getTo();
			}

		}
	
		// najtañszy s¹siad - wierzcholek, 
		nowy->removeEdge(wierzcholek, wierzcholek2); //usuwam najtañszy, dodaje do grafu S
		S->addEdge(wierzcholek, wierzcholek2, koszt);		//dodaje do S
		//Dla ka¿dego s¹siada u czyli

		//s¹siedzi do wierzcho³ka najtañszego od 0 oprócz 0
		set<Edge> wychodzace2 = nowy->getOutEdges(wierzcholek2);

	

		for (set<Edge>::iterator it = wychodzace2.begin(); it != wychodzace2.end(); ++it)
		{
			//waga krawedzi u-v
			//to nie int
			Edge a((*it), wierzcholek2,true);
		
			if (koszt_drogi[(*it)] > koszt_drogi[wierzcholek2] + a.getWeight())
			{
				koszt_drogi[(*it)] = koszt_drogi[wierzcholek2];
				przedostatni[(*it)] = wierzcholek2;
			}
		}


	}



	int suma = 0;
	for (int i = 0; i < n; i++)
	{
		suma = koszt_drogi[i] + suma;
	}
	delete g;
	return suma;
}

Graph* makeGraph(int n, vector<vector<double>> rates) {

	Graph* graf = new ListGraph(n, true);
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < n; j++)
		{
			if(i!=j && rates[i][j]!=0)
			graf->addEdge(i, j, rates[i][j]);
		}
	}
	

	return graf;
}
