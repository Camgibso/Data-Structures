typedef struct ListNode* ListNodep;
typedef struct Node* Nodep;
typedef struct Graph* Graphp;

typedef struct Node {
	int visited, distance;
	char label;
	Nodep prev;
	Nodep next;
	ListNodep adjacent;
}Node;

typedef struct ListNode {
	Nodep datum;
	int weight;
	ListNodep next;
	ListNodep prev;
}ListNode;

typedef struct Graph {
	Nodep vertices, visited;
	ListNodep head, tail;
}Graph;

Nodep node_constr(char);
ListNodep list_node_constr(Nodep, int);
Graphp graph_constr();
void graph_destr(Graphp);
void destr_nodes(Nodep);
void destr_adj(ListNodep);
int add_node(Graphp, char);
int add_edge(Graphp, char, char, int);
void push(Graphp, Nodep);
Nodep stack_pop(Graphp);
Nodep queue_pop(Graphp);
int BFT(Graphp, char);
int DFT(Graphp, char);
void visit(Graphp, Nodep);