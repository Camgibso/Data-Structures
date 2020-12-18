//final.h

#include <vector>
#include <iostream>
using namespace std;
typedef unsigned int uint;

class Dijsktra {
public:
	Dijsktra(int numVertices, int source);

	void setWeight(int from, int to, uint weight);
	void calculateDistance();
	void printPath(const int to) const;
	int getDistance(const int to);
private:
	int getClosestUnknownNode() const;
	vector< vector<int> > graph;
	vector<uint> distance;
	vector<bool> known;
	vector<int> prev;
	int numVertices;
	int source;
};