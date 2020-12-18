//main.cpp

#include "final.h"
#include <iostream>
#include <vector>
using namespace std;

int main() {
	int N, E, source;	//user interface
	cout << "Enter the number of vertices: "; //# of nodes
	cin >> N;	//input of number of vert
	cout << "Enter the number of edges: ";
	cin >> E;
	cout << "Enter the identifier of the source node: ";
	cin >> source;
	Dijsktra d(N, source);
	for (int i = 0; i < E; i++) {
		int from, to, cost;
		cout << "Enter the edge (from, to, cost): ";
		cin >> from >> to >> cost;
		d.setWeight(from, to, cost);	//construct the graph from user input
	}
	
	d.calculateDistance();
	cout << "Enter the destination node(1 - " << N << ")" <<": ";
	int input;
	while (cin >> input) {
		cout << "Distance: " << d.getDistance(input) << endl << "Path: ";
		d.printPath(input-1);
		cout << input << endl << "Enter the destination node(1 - " << N << ")" << ": ";
	}

	return 0;
}