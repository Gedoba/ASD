#include <iostream>
#include <vector>
#include <algorithm>
#include <string.h>
#include <map>
#include "Graph.h"
#include "GraphAlgorithms.h"
#include "MaximumFlow.h"

using namespace AMDGraph;
using namespace std;

template<typename T>
ostream& operator<<(ostream& os, const vector<T>& p) {
	os << "(";
	if (p.size() != 0) {
		for (int i = 0;i < p.size() - 1;++i)
			os << p[i] << ",";
		os << p[p.size() - 1];
	}
	os << ")";
	return os;
}

int main(int argc, char** argv)
{
	const int ntest = 1;
	//// Przygotowanie testow
	Graph* test0 = new ListGraph(6, true);
	test0->addEdge(0, 1, 3);
	test0->addEdge(1, 2, 2);
	test0->addEdge(2, 3, 3);
	test0->addEdge(0, 4, 3);
	test0->addEdge(4, 5, 3);
	test0->addEdge(5, 3, 2);
	test0->addEdge(5, 2, 4);
	test0->addEdge(4, 1, 2);
	
	Graph* test1 = new ListGraph(5, true);
	test1->addEdge(1, 0, 10);
	test1->addEdge(1, 4, 2);
	test1->addEdge(4, 2, 7);
	test1->addEdge(0, 3, 5);
	test1->addEdge(3, 2, 4);
	test1->addEdge(0, 4, 5);
	
	Graph* test2 = new ListGraph(5, true);
	test2->addEdge(1, 4, 4);
	test2->addEdge(2, 4, 2);
	test2->addEdge(3, 4, 8);

	Graph* test3 = new ListGraph(3, true);
	test3->addEdge(1, 0, 2);
	test3->addEdge(1, 2, 5);

	Graph* test4 = new ListGraph(10, true);
	test4->addEdge(0, 1, 5);
	test4->addEdge(1, 3, 3);
	test4->addEdge(1, 2, 2);
	test4->addEdge(0, 2, 3);
	test4->addEdge(2, 3, 5);
	test4->addEdge(3, 4, 2);
	test4->addEdge(3, 5, 2);
	test4->addEdge(3, 6, 4);
	test4->addEdge(4, 7, 1);
	test4->addEdge(5, 7, 3);
	test4->addEdge(6, 7, 5);
	test4->addEdge(4, 6, 1);
	test4->addEdge(7, 8, 7);
	test4->addEdge(8, 9, 10);
	test4->addEdge(7, 2, 2);
	test4->addEdge(4, 0, 11);
	test4->addEdge(3, 0, 2);

	Graph* g[] = {
		test0, test1, test2, test3, test4, test4
	};
	int s[] = {
		0, 1, 0, 0, 0, 4
	};
	int t[] = {
		3, 2, 4, 2, 9, 7
	};
	double r[] = {
		5, 11, 0, 0, 7, 8
	};
	vector<int> p[] = {
		{0, 1, 2, 3},
		{1, 0, 3, 2},
		{},
		{},
		{0, 2, 3, 4, 7, 8, 9},
		{4, 0, 1, 3, 5, 7}
	};
	vector<double> w[] = {
		{1, 0, 1},
		{6, 1, 0},
		{},
		{},
		{2, 4, 1, 0, 6, 9},
		{9, 3, 1, 0, 1}
	};
	vector<int> e1 = { 0, 1, 5 };
	vector<int> e2 = { 2, 3 };
	vector<int> e3 = { 0, 1, 4, 5 };
	vector<int> e4 = { 0, 1, 2, 3, 4, 5 };

	//// Sprawdz wykonanie zadania
	bool error;
	cout << "Etap 1";
	for (int i : e1) {
		cout << endl << "Test " << i << "\t";
		error = false;
		vector<int> p = findAugmentingPath(g[i], s[i], t[i]);
		if (p.empty()) {
			cout << endl << "Pusta sciezka" << endl;
			error = true;
			continue;
		}
		if (p.front() != s[i]) {
			cout << endl << "Niepoprawny poczatek" << endl;
			error = true;
		}
		if (p.back() != t[i]) {
			cout << endl << "Niepoprawny koniec" << endl;
			error = true;
		}
		for (int j = 0;j < p.size() - 1;++j)
			if (!g[i]->containsEdge(p[j], p[j + 1])) {
				cout << endl << "Niepoprawna krawedz: ("
					<< p[j] << "," << p[j + 1] <<")" << endl;
				error = true;
			}
		if (!error)
			cout << "OK" << endl;
	}

	cout << endl << "Etap 2";
	for (int i : e2) {
		cout << endl << "Test " << i << "\t";
		error = false;
		vector<int> p = findAugmentingPath(g[i], s[i], t[i]);
		if (!p.empty())
			cout << "BLAD" << endl;
		else 
			cout << "OK" << endl;
	}
	cout << endl << "Etap 3";
	for (int i : e3) {
		cout << endl << "Test " << i << "\t";
		error = false;
		ListGraph cp = ListGraph(*g[i]);
		augmentFlow(&cp, p[i]);
		for (int j = 0;j < p[i].size() - 1;++j)
			if (cp.getEdgeWeight(p[i][j], p[i][j + 1]) != w[i][j]) {
				cout << endl << "Niepoprawna waga krawedzi ("
					<< p[i][j] << "," << p[i][j + 1] << ")" << endl;
				error = true;
			}
		if (!error)
			cout << "OK" << endl;
	}

	cout << endl << "Etap 4";
	for (int i : e4) {
		error = false;
		cout << endl << "Test  " << i << "\t";
		ListGraph cp = ListGraph(*g[i]);
		double flow = maximumFlow(&cp, s[i], t[i]);
		if (flow != r[i]) {
			cout << endl << "Niepoprawny przeplyw: " << flow
				<< " (oczekiwano: " << r[i] << ")" << endl;
			error = true;
		}
		if (!error)
			cout << "OK" << endl;
	}

	for (int i = 0;i < ntest;++i)
		delete g[i];

	system("PAUSE");
	return 0;
}
