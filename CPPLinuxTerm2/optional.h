
#ifndef header
#define header
using namespace std;

class List;

// class n
class Node {
//variable declaration
Node *nextN, *prevN, *parentN;
List *leafNode;
public:
//variable names
	string name;
	char label;
	int visited;
	bool isdir;
//fns
	Node();
	Node(char, bool);
	~Node();
	void destr_nodes(Node*);
	void destr_adj(List*);
	bool isDir();
	int get();
	void set(int);
	Node* get_nextN();
	void set_nextN(Node*);
	Node* get_prevN();
	void set_prevN(Node*);
	Node* get_parentN();
	void set_parentN(Node*);
};

// class list
class List {
// list node pointer - next, prev, and adjacent list
	List* nextList, *prevList, *leafList, *parentList;
public:
// public variables
	Node * datum;
// constructors / deconstructors
	List();
	List(Node*);
	void destr_nodes(Node*);
// next / prev list
	List* get_nextList();
	void set_nextList(List*);
	List* get_prevList();
	void set_prevList(List*);
};

// class dir
class dir {
	Node *root, *cwd, *visited, *vertices;
	List *head, *tail;
public:
// constructors and deconstructors
	dir();
	~dir();

// public variables
	void destr_nodeDir(Node*);
	string mkdir(dir*, string);
	string mkfile();
	void chDir();
	void showPath();
};

#endif