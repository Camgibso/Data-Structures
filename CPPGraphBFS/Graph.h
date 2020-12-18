//.h file
//set max # of nodes to 50
#define max_node 50
using namespace std;
 
 //create node
struct node{
 int vertex;
 node* next;
};

 
void q_insert (int item);
int q_delete ();
int is_q_empty();
void createGraph();
void BFS_traversal();
