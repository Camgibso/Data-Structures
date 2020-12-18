
#include "Graph.h"
#include <iostream>

//declarations from .h to make it a non repeating declaration
int totalNodes;
int queue[max_node]; 
int f = -1; //front queue pointer
int r = -1; //rear queue pointer
node *adj[max_node];

//function to insert in the queue
void q_insert (int item){
 r = r + 1;
 queue[r] = item;
 if(f == -1)
  f = 0;
}
 
//function to delete in the queue
int q_delete (){
 int delitem = queue[f];
 if(f == r)
  f = r = -1;
 else
  f = f + 1;
 return(delitem);
}
 
// to check if the queue is empty
int is_q_empty(){
    if(f==-1)
      return(1);
    else return(0);
}
// creat the adjascency list of the graph
 
void createGraph(){
    node *newl,*last;
    int neighbours,neighbour_value;
    cout<<endl<<"Create Graph "<<endl;
    cout<<"Enter total number of nodes in the graph: ";
    cin>>totalNodes;
    for(int i=1;i<=totalNodes;i++){
        last=NULL;
        cout<<endl<<"Enter no. of nodes in the adjacency list of node "<<i<<endl;
        cout<<"--> That is Total Neighbours of "<<i<<": ";
        cin>>neighbours;
        for(int j=1;j<=neighbours;j++){
            cout<<"Enter neighbour #"<<j<<": ";
            cin>>neighbour_value;
            newl=new node;
            newl->vertex=neighbour_value;
            newl->next=NULL;
            if(adj[i]==NULL)
                adj[i]=last=newl;
            else{
                last->next = newl;
                last = newl;
            }
        }
    }
}
 
void BFS_traversal(){
    node *tmp;
    int N,v,start_node,stat[max_node];//stat arr for maintaing status.
		const int go=1,wait=2,can_push=3; //stat of node to not overload 
 
    cout<<"Enter starting node: ";
    cin>>start_node;
 
    //step 1 : Initialize all nodes to go state.
		for(int i=1;i<=totalNodes;i++)
        stat[i]=go;
 
    //step 2 : put the start node in queue and change stat.
    q_insert(start_node); //Put starting node into queue.
    stat[start_node]=wait; //change it stat to wait state.//step 3 : Repeat until queue is empty.
		while(is_q_empty()!=1){
 
        //step 4 : Remove the front node N of queue
        //push N and change the stat of N to
        //be can_push state.
        N = q_delete(); //remove front node of queue.
        stat[N]=can_push; //stat of N to can_push.
				cout<<"   "<<N; //displaying can_push node.
				//step 5 : Add to rear of queue all the neighbours of N,
				//that are in go state and change their stat to//wait state.
        tmp = adj[N];  //for stat updation.while(tmp!=NULL){
            v = tmp->vertex;
            if(stat[v]==go){//check stat of N's neighbour.
                q_insert(v); //insert N's neighbour who are in go state.
                stat[v]=wait; //and make their stat to wait state.
            }
		}
}