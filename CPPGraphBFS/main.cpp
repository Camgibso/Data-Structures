
#include "Graph.h"
#include <iostream>
using namespace std;

int main(){
    
    cout<<"Breadth First Search Traversal\n";
    createGraph();
    cout<<"\nBFS traversal:\n";
    BFS_traversal();
    int n;
    cin>>n;
}

//1)	Implement a graph using an edge list, adjacency matrix, or adjacency list structure. The graph much contain an add_edge(), and add_node() function. You may construct your graph in your main function. Once you have constructed your graph you must implement a Breadth first search and execute the breadth on your constructed graph. Display the nodes in the order that they are visited by your breadth first search. 