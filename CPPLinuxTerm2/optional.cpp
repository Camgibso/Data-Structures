#include <iostream>
#include <algorithm>
#include <string>
#include <cstring>
#include "optional.h"
using namespace std;

//creates node
Node::Node() {
//this->isdir = isDir;
	this->label = label;
	this->nextN = 0;
	this->prevN = 0;
	this->visited = 0;
	this->parentN = 0;
	this->leafNode = 0;
}

Node::Node(char label, bool isDir) {
	this->isdir = isDir;
	this->label = label;
	this->nextN = NULL;
	this->prevN = NULL;
	this->parentN = NULL;
	this->leafNode = NULL;
}

Node::~Node() {
	this->destr_nodes(this->nextN);
	this->destr_nodes(this->prevN);
}

bool Node::isDir() {
	return this->isdir;
}

// deconstructor nodes for graph

void dir::destr_nodeDir(Node* node) {
	if (node == 0) {
		return;
	}

	else {
		destr_nodeDir(node->get_nextN());
		delete node;
	}
}

// deconstructor nodes for node

void Node::destr_nodes(Node* node) {
	if (node == 0) {
		return;
	}

	else {
		destr_nodes(node->get_nextN());
		destr_nodes(node->get_prevN());
		delete node;
	}
}

// deconstructor adjacent nodes for node

void Node::destr_adj(List* ln) {
	if (ln == 0) {
		return;
	}

	else {
		destr_adj(ln->get_nextList());
		delete ln;
	}
}

// set list constructor

List::List(Node* insertNode) {
	this->datum = insertNode;
	this->nextList = 0;
	this->prevList = 0;
}

//default list constructor
List::List() {
	this->datum = datum;
}

//deconstructor nodes for list
void List::destr_nodes(Node* node) {
	if (node == 0) {	//null checker
		return;
	}
	else {
		destr_nodes(node->get_nextN());
		destr_nodes(node->get_prevN());
		delete node;
	}
}

// directory const
dir::dir() {
	this->root = NULL;
	this->cwd = NULL;	//current working directory
	this->vertices = NULL;
}

// dir deconst
dir::~dir() {
	this->destr_nodeDir(this->vertices);
}

// node get fn returns int
int Node::get() {
	return this->isdir;
}

Node* Node::get_parentN() {
	return this->parentN;
}

// node get next function
Node* Node::get_nextN() {
	return this->nextN;
}

// node get previous function
Node* Node::get_prevN() {
	return this->prevN;
}

// node set function
void Node::set(int isDir) {
	this->isdir = isDir;
}

// node set adjacent function
void Node::set_parentN(Node* parentN) {
	this->parentN = parentN;
}

// node set next function
void Node::set_nextN(Node* nextN) {
	this->nextN = nextN;
}

// node set previous functiion
void Node::set_prevN(Node* prevN) {
	this->prevN = prevN;
}

// list get next fn
List* List::get_nextList() {
	return this->nextList;
}

// list get prev fn
List* List::get_prevList() {
	return this->prevList;
}

//mkdir fn
string dir::mkdir(dir* G, string name) {
	//spaces out the input so the inputs are easier to find
	for (int i = 0; i < name.length(); i++) {
		replace(name.begin(), name.end(), '/', ' ');
	}
	//iterates 
	char *first = new char[name.length() + 1];
	strcpy(first, name.c_str());
	char * p = strtok(first, " ");
	//reads through the word
	
	while (p != 0){
		cout << p << '\n';
		p = strtok(NULL, " ");
	}

	delete[] first;
	return name;
	replace(name.begin(), name.end(), '/', ' ');
	cout << name << endl;
	return name;


//unique checker
	for (Node* temp = G->vertices; temp != 0; temp = temp->get_nextN()) {
		if (temp->name == name) {
			return 0;
		}
	}

//create a new node to be inserted
	Node* newNode = new Node();
//if vert != 0, set it to prev
	if (G->vertices != 0) {
	G->vertices->set_prevN(newNode);
	}

	newNode->set_nextN(G->vertices);
	G->vertices = newNode;
	return name;
}

//touch fn
	string dir::mkfile() {
	string in;
	cout << "file: " << endl;
	cin >> in;
	return in;
}

//cd function
void dir::chDir() {
	int lower, i, j;
	string mystring;
	string strings[25];
	cout << "Enter a directory with '/' in it: " << endl;
	cin >> mystring;
	if (mystring[0] == '/') {
		i = 1;
		lower = 1;
	}

	else {
		i = 0;
		lower = 0;
	}

	j = 0;
	for (; i < mystring.length(); i++) {
		if (mystring[i] == '/') {
			strings[j] = mystring.substr(lower, lower - 1);
			j++;
		}
	}

	for (i = 0; i < j; i++) {
		cout << strings[0] << endl;
	}

	cout << strings[3] << endl;
	return;
}

void dir::showPath() {
	cout << "file 0: " << endl;
	cout << vertices << endl;
	cout << "file 1: " <<endl;
	cout << rename <<endl;
	return;
}

//set nxt fn
void List::set_nextList(List* nextList) {
	this->nextList = nextList;
}

//set prev fn
void List::set_prevList(List* prevList) {
	this->prevList = prevList;
}