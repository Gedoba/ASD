//
// Created by Wojciech Ciok on 06/11/2017.
//
#include <stdio.h>
#include <vector>
#include "Vertex.h"

using namespace std;

class Graph{
private:
    vector<Vertex> vertieces;
public:
    //add a vertex to vertieces
    void addVertex(int vertex);

    //delete a vertex from vertieces
    void delVertex(int vertex);

    //connect two vertieces
    void addConnection(int a, int b);

    //delete a connection between two vertieces
    void delConnection(int a, int b);

    //check if your graph contains a given vertex
    bool contains(int a);

    //print vertieces with their connections
    void print();

    //get position of a given vertex in vertieces
    int indexValue(int a);

    //check if all veriteces are of an even degree
    bool isEven();

    //check if given vertieces are neighbours in your graph
    bool common_neighbour(int a, int b);

    //return G^2
    Graph retSqr();

    //return G^3
    Graph retCube();
};