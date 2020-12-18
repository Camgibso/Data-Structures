#include "Graph.h"
#include <stdio.h>
#include <stdlib.h>

int main() {
	Graphp G = graph_constr();
	add_node(G, 'A');
	add_node(G, 'B');
	add_node(G, 'C');
	add_node(G, 'D');
	add_node(G, 'E');
	add_node(G, 'F');
	add_edge(G, 'C', 'B', 3);
	add_edge(G, 'C', 'E', 12);
	add_edge(G, 'C', 'D', 8);
	add_edge(G, 'E', 'C', 12);
	add_edge(G, 'E', 'D', 1);
	add_edge(G, 'D', 'C', 8);
	add_edge(G, 'D', 'E', 1);
	add_edge(G, 'B', 'C', 3);
	add_edge(G, 'B', 'A', 5);
	add_edge(G, 'A', 'B', 5);
	add_edge(G, 'B', 'D', 2);
	add_edge(G, 'D', 'B', 2);

	BFT(G, 'C');
	DFT(G, 'C');

	system("pause");
	return 0;
}