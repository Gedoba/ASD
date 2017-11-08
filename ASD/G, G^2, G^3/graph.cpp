#include <stdio.h>
#include <iostream>
#include <vector>
#include "graph.h"
using namespace std;

void Graph::addVertex(int vertex) {

    //firts check if your graph doesn't already contain vertex
    for(int x = 0; x < vertieces.size();x++)
        if(vertieces[x].getIndex()==vertex){
            cout << "the graph already contains vertex " << vertex << endl;
            return;
        }
    //if not add it
    vertieces.push_back(Vertex(vertex));
}


void Graph::delVertex(int vertex) {

    //if the graph is empty there is nothing to delete
    if(vertieces.empty()){
        cout << "the graph is empty" << endl;
        return;
    }

    //you can't delete a vertex which is not in the graph
    if(!contains(vertex)){
        cout << "there is no vertex " << vertex << endl;
        return;
    }

    //delete all edges connected to vertex
    for(int x = 0; x<vertieces.size(); x++){
        if(vertieces[x].contains(vertex))
            vertieces[x].unpair(vertex);
    }

    //delete vertex
    vertieces.erase(vertieces.begin()+indexValue(vertex));
}


void Graph::addConnection(int a, int b) {

    //check if the graph contains given vertieces
    if(this->contains(a) && this->contains(b)){
        //there is no edge connecting a vertex to itself
        if(a==b){
            cout << "you can't connect a vertex to itself" << endl;
            return;
        }

        //this connection might already exist
        if(vertieces[indexValue(a)].contains(b))
            return;

        //make edges a-b, b-a
        vertieces[indexValue(a)].pair(b);
        vertieces[indexValue(b)].pair(a);
    }
    else
        cout << "invalid vertieces" << endl;
}


void Graph::delConnection(int a, int b) {

    //check if the graph contains given vertieces
    if(this->contains(a) && this->contains(b)){

        //there is no edge connecting a vertex to itself
        if(a==b){
            cout << "there is no such connection" << endl;
            return;
        }

        //delete edges
        if(vertieces[indexValue(a)].contains(b))
            vertieces[indexValue(a)].unpair(b);
        if(vertieces[indexValue(b)].contains(a))
            vertieces[indexValue(b)].unpair(a);
        else
            cout << "there is no such connection" << endl;
    }
    else
        cout << "invalid vertieces" << endl;
}


bool Graph::contains(int a) {

    //check in the graph if it contains vertex a
    for(int x = 0; x < vertieces.size(); x++){
        if(vertieces[x].getIndex() == a){
            return true;
        }
    }
    return false;
}


void Graph::print() {

    for(int x = 0; x < vertieces.size(); x++){
        cout << vertieces[x].getIndex() << ": ";
        vertieces[x].print();
    }
    cout<<endl;
}


int Graph::indexValue(int a) {

    //return coordinate of 'a' in vertieces
    for(int x = 0; x < vertieces.size(); x++){
        if(vertieces[x].getIndex() == a)
            return x;
    }
}


bool Graph::isEven() {

    //for every vertex check if it is of an even degree
    for(int x = 0; x<vertieces.size(); x++){
        if(!vertieces[x].isEven()){
            cout << "there is an odd degree vertex" << endl;
            return false;
        }
    }
    cout << "all vertieces degrees are even" << endl;
    return true;
}


bool Graph::common_neighbour(int a, int b) {

    //take every vertex connected to 'a'
    for(int x = 0; x<vertieces[indexValue(a)].getConnecions().size(); x++){
        //if any of these verieces is connected to 'b' you're home
        if(vertieces[indexValue(b)].contains(vertieces[indexValue(a)].getConnecions()[x]))
            return true;
    }
    return false;
}


Graph Graph::retSqr() {

    //make a copy of you graph
    Graph a = *this;

    //take every vertex in vertieces
    for(int x = 0; x<vertieces.size();x++){

        //take every other vertex "behind" 'x' (this is why y=x+1)
        for(int y = x+1; y<vertieces.size(); y++){

            //check if they have a common neighbour
            if(common_neighbour(vertieces[x].getIndex(),vertieces[y].getIndex()))

                //if they do, connect them
                a.addConnection(vertieces[x].getIndex(),vertieces[y].getIndex());
        }
    }
    return a;
}


Graph Graph::retCube() {

    //make a new graph equal to your graph^2
    Graph b = this->retSqr();

    //go to every vertex in vertieces
    for(int x = 0; x<vertieces.size(); x++){

        //for every of these verieces go through their connections
        for(int y = 0; y<vertieces[x].getConnecions().size(); y++){

            //check if any of these has a common neighbour with the remaining ones
            for(int z = x+1; z<vertieces.size(); z++){
                if(common_neighbour(vertieces[x].getConnecions()[y],vertieces[z].getIndex()))

                    //if they do make a connection between 'x' and 'z' (note not 'y' and 'z')
                    b.addConnection(vertieces[x].getIndex(),vertieces[z].getIndex());
            }
        }
    }
    return b;
}
