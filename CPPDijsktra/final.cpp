//final.cpp
#include <iostream>
#include <vector>
#include "final.h"
#define NOT_A_VERTEX -1
#define INFINITY 99999 //max distance for comparison
using namespace std;


void Dijsktra::setWeight(int from, int to, uint weight) {
	graph[from-1][to-1] = weight;	//lets user set the weight
}

int Dijsktra::getClosestUnknownNode() const {
	// the uknown vertex with the closest distance among all has to be adjacent to a known vertex
	uint minDistance = INFINITY;
	int closestVertex = NOT_A_VERTEX;
	for (int i = 0; i < numVertices; i++) {	//iterate to get closest node
		if ((!known[i]) && minDistance > distance[i]) {
			minDistance = distance[i];
			closestVertex = i;
		}
	}
	return closestVertex;
}

void Dijsktra::calculateDistance() {
	int closestUnknownNode = getClosestUnknownNode(); //iterate to find closest node
	for (int i = 0; i < numVertices && closestUnknownNode != NOT_A_VERTEX; i++) {
		known[closestUnknownNode] = true;
		for (int i = 0; i < numVertices; i++) {
			if (graph[closestUnknownNode][i] < distance[i]) {	//compare distance
				distance[i] = graph[closestUnknownNode][i] + distance[closestUnknownNode];
				prev[i] = closestUnknownNode;
			}
		}
		closestUnknownNode = getClosestUnknownNode();
	}
}

int Dijsktra::getDistance(const int to) {
	return distance[to-1];
}

void Dijsktra::printPath(const int to) const {
	if (prev[to] == source) {
		cout << source + 1 << " -> ";
	}
	else if (prev[to] != NOT_A_VERTEX) {
		printPath(prev[to]);
		cout << prev[to] + 1 << " -> ";
	}
	else {
		cout << "There is no path to ";
	}
}

Dijsktra::Dijsktra(int numVertices, int source) :
	numVertices(numVertices), source(source-1) {	//take in # of vert and source-1
	source = this -> source;
	graph.resize(numVertices, vector<int>(numVertices,INFINITY));//resize graph so it contains n elements
	distance.resize(numVertices, INFINITY); //resize distance
	known.resize(numVertices, false);
	prev.resize(numVertices, NOT_A_VERTEX);
	graph[source][source] = 0;
	distance[source] = 0;
}