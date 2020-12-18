
class Node{
public:
	int val; 		//stores a value
	Node *next; 	//pointer to the next element
};

class stack{
private:
	int nofnodes; 		//number of elements in the stack
	int nodelimit;		//node limit
	Node *head; 		//the top element of the stack

public:
  
	stack(); 				//default constructor
	~stack(){}; 			//destructor
	bool isEmpty(); 		//checks if the stack is empty
	void push(int num);		//inserts an element to the top of stack
	void empty();			//empty the stack
	void peek();			//to display top element of the stack
	void pop(); 			//removes top element from the stack
	void print(); 			//prints the stack of elements
	
};