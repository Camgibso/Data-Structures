#include <stdio.h>
#include <stdlib.h>
#include <iostream>
using namespace std;

class Node{ //a queue element.
public:
	int val; //stores a value
	Node *next; //pointer to the next element
};

class queue{
private:
	Node *front=NULL; //the first element of the queue
	Node *rear = NULL; //the last element of the queue
	Node *temp = NULL;

public:  
	queue(); //default constructor
	~queue(){}; //destructor
	bool isEmpty(); //checks if the queue is empty
	void push(int num);//inserts an element to the top of queue
	void empty();//empty the queue
	void peek();//to display top element of the queue
	void pop(); //removes element from the queue
	void print(); //prints the queue of elements
};


int main(int argc, char** argv) {
	int choice;			//ui
	int number;
  
	//shortcut name for queue
	queue que;
	
	do{
	//ui menu
	cout << endl << "Options for the Queue: " << endl;
	cout << "1. Push" << endl;
	cout << "2. Pop" << endl;
	cout << "3. Print" << endl;
	cout << "4. Check if empty" << endl;
	cout << "5. Peek" << endl;
	cout << "6. Exit Program" << endl;
	//take in the ui
	cout << "\n Enter your choice:" << endl;
	cin >> choice;
  
	//switch
	switch(choice){
		case 1:
			// ui for number to push for queue
			cout << "Enter the number to be inserted: ";
			cin>>number;
			que.push(number);
			break;

		case 2:
			//pops from the queue
			que.pop();
			break;
		
		case 3:
			//prints the values in the queue
			que.print();
			break;

		case 4:
			//clears queue
			que.isEmpty();
			break;

		case 5:
			//Peeks in the queue
			que.peek();
			break;
	}
  }
	while(choice != 6);
	return 0;
}

//default constructor
queue::queue(){
	front = 0; 		//sets front of queue to 0
}

void queue::empty(){
	Node *current;
	if(!isEmpty()){ //if queue is not empty
		do{ //if queue is not empty
			Node *tmp; //temporary node pointer
			tmp=front->next;//stores the next element of front
			//prints the number to be removed;
			delete front; //frees the memory allocated to front
			front=tmp; //the next element of front, becomes front
		} 
		while(!isEmpty());
	}
	cout << "Queue emptied";
}


void queue::peek(){  
	if(isEmpty()){ //if queue is not empty
		cout << "No values in queue" << endl;
	}
	
	else{
	cout<<"Front of queue: " << front -> val << endl;
	}
}

//checks if the queue is empty
bool queue::isEmpty(){
	if(front == NULL) return true;
	else return false;
}

void queue::push(int num){
	//inserts an element at top of the queue
	if(!front){ 
		temp = new Node; 	//memory allocation to temp
		temp -> val = num;	//stores the value to
		temp -> next = NULL;
		
		if(front == NULL){ 	//if head is empty or first element in queue
			front = rear = temp;
			rear -> next = NULL;
		}
		
		else{
			rear->next = temp;
			rear = temp;
			rear->next = NULL;
		}
		//prints the value pushed into the queue
		cout<<"Push'd "<< num << endl;  
	} 
}


void queue::pop(){ //removes front/first element in the queue

	if(!isEmpty()){ 		//if queue is not empty
		Node *tmp; 			//temporary node pointer
		tmp = front;
		//prints the number to be removed;
		cout<<"Pop'd "<< front->val <<endl;
		
		if(front==rear){
			front = rear = NULL;
		}
		
		else{
			front = front->next; //next front becomes the front elemt
			delete tmp; 		 //frees the memory allocated to front
		}
	}

	//if queue is empty
	else cout << "No values in queue" << endl;
}


void queue::print(){
	Node *current;
	if(isEmpty()){	//if stack is empty
		//prints that queue is empty
		cout << "No elements in stack" << endl;  
		return;
	}
	else
		cout<<"Stack: "<<endl;
		//prints the stack
		for(current = front; current; current = current -> next){
		cout << current -> val <<" \t";
  	}
	cout<<" \n";  
}
