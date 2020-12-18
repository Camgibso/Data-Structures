#include "Graph.h"
#include <stdlib.h>
#include <stdio.h>

Nodep node_constr(char label) {
	Nodep newNode = (Nodep)malloc(sizeof(Node));
	newNode->label = label;
	newNode->adjacent = 0;
	newNode->next = 0;
	newNode->prev = 0;
	newNode->visited = 0;
	return newNode;
}

ListNodep list_node_constr(Nodep insertNode, int weight) {
	ListNodep newNode = (ListNodep)malloc(sizeof(ListNode));
	newNode->datum = insertNode;
	newNode->weight = weight;
	newNode->next = 0;
	newNode->prev = 0;
	return newNode;
}

Graphp graph_constr() {
	Graphp graph = (Graphp)malloc(sizeof(Graph));
	graph->head = 0;
	graph->tail = 0;
	graph->vertices = 0;
	graph->visited = 0;
	return graph;
}

void graph_destr(Graphp G) {
	destr_nodes(G->vertices);
}

void destr_nodes(Nodep node) {
	if (node == 0) {
		return;
	}
	else {
		destr_nodes(node->next);
		destr_adj(node->adjacent);
		free(node);
	}
}

void destr_adj(ListNodep ln) {
	if (ln == 0) {
		return;
	}
	else {
		destr_adj(ln->next);
		free(ln);
	}
}

int add_node(Graphp G, char label) {
	//label must be unique
	for (Nodep temp = G->vertices; temp != 0; temp = temp->next) {
		if (temp->label == label) {
			return 0;
		}
	}

	Nodep newNode = node_constr(label);
	if (G->vertices != 0) {
		G->vertices->prev = newNode;
	}
	newNode->next = G->vertices;
	G->vertices = newNode;

	return 1;
}

int add_edge(Graphp G, char from, char to, int weight) {
	Nodep temp, start, end;

	//find start of edge
	for (temp = G->vertices; temp != 0; temp = temp->next) {
		if (temp->label == from) {
			break;
		}
	}

	//return false if node was not found
	if (temp == 0) {
		return 0;
	}
	else {
		start = temp;
	}

	//find the end of the edge
	for (temp = G->vertices; temp != 0; temp = temp->next) {
		if (temp->label == to) {
			break;
		}
	}

	//return false if node was not found
	if (temp == 0) {
		return 0;
	}
	else {
		end = temp;
	}

	//add edge by adding node to 
	ListNodep newNode = list_node_constr(end, weight);
	if (start->adjacent != 0) {
		start->adjacent->prev = newNode;
	}
	newNode->next = start->adjacent;
	start->adjacent = newNode;
	return 1;
}

void push(Graphp G, Nodep node) {
	ListNodep newNode = list_node_constr(node, G);
	if (G->head == 0) {
		G->head = newNode;
		G->tail = newNode;
	}
	else {
		G->head->prev = newNode;
		newNode->next = G->head;
		G->head = newNode;
	}
}

Nodep stack_pop(Graphp G) {
	if (G->head == 0) {
		return 0;
	}
	else {
		Nodep retVal = G->head->datum;
		ListNodep temp = G->head;
		G->head = G->head->next;
		if (G->head != 0) {
			G->head->prev = 0;
		}
		else {
			G->tail = 0;
		}
		free(temp);
		return retVal;
	}
}

Nodep queue_pop(Graphp G) {
	if (G->head == 0) {
		return 0;
	}
	else {
		Nodep retVal = G->tail->datum;
		ListNodep temp = G->tail;
		G->tail = G->tail->prev;
		if (G->tail != 0) {
			G->tail->next = 0;
		}
		else {
			G->head = 0;
		}
		free(temp);
		return retVal;
	}
}

int BFT(Graphp G, char start) {
	Nodep temp = G->vertices;
	ListNodep LTemp;
	for (; temp != 0; temp = temp->next) {
		if (temp->label == start) {
			break;
		}
	}

	if (temp == 0) {
		return 0;
	}

	push(G, temp);

	while (G->head != 0) {
		temp = queue_pop(G);
		//put temp into visited list
		if (!temp->visited) {
			//mark as visited
			visit(G, temp);
			
			for (LTemp = temp->adjacent; LTemp != 0; LTemp = LTemp->next) {
				if (!LTemp->datum->visited) {
					push(G, LTemp->datum);
				}
			}
		}

		//push top of vertices if queue is empty and vertices is not
		if (!G->head && G->vertices) {
			push(G,G->vertices);
		}
	}

	for (temp = G->visited; temp->next != 0; temp = temp->next);
	printf("%c", temp->label);
	for (temp = temp->prev; temp != 0; temp = temp->prev) {
		printf(", %c", temp->label);
	}
	printf("\n");

	G->vertices = G->visited;
	G->visited = NULL;

	for (temp = G->vertices; temp != 0; temp = temp->next) {
		temp->visited = 0;
	}

	return 1;
}

int DFT(Graphp G, char start) {
	Nodep temp = G->vertices;
	ListNodep LTemp;
	for (; temp != 0; temp = temp->next) {
		if (temp->label == start) {
			break;
		}
	}

	if (temp == 0) {
		return 0;
	}

	push(G, temp);

	while (G->head != 0) {
		temp = stack_pop(G);
		//put temp into visited list
		if (!temp->visited) {
			//mark as visited
			visit(G, temp);

			for (LTemp = temp->adjacent; LTemp != 0; LTemp = LTemp->next) {
				if (!LTemp->datum->visited) {
					push(G, LTemp->datum);
				}
			}
		}

		//push top of vertices if queue is empty and vertices is not
		if (!G->head && G->vertices) {
			push(G, G->vertices);
		}
	}

	for (temp = G->visited; temp->next != 0; temp = temp->next);
	printf("%c", temp->label);
	for (temp = temp->prev; temp != 0; temp = temp->prev) {
		printf(", %c", temp->label);
	}
	printf("\n");

	G->vertices = G->visited;
	G->visited = NULL;

	for (temp = G->vertices; temp != 0; temp = temp->next) {
		temp->visited = 0;
	}

	return 1;
}

void visit(Graphp G, Nodep node) {
	//remove from vertices list
	if (node->prev != 0) {
		node->prev->next = node->next;
	}
	if (node->next != 0) {
		node->next->prev = node->prev;
	}
	if (G->vertices == node) {
		G->vertices = node->next;
	}

	//add to visited list
	if (G->visited != 0) {
		G->visited->prev = node;
	}
	node->next = G->visited;
	node->prev = 0;
	G->visited = node;

	//mark as visited
	node->visited = 1;
}