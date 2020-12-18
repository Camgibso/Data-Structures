typedef struct Node {
	int datum;
	struct Node* left;
	struct Node* right;
	struct Node* parent;
}Node, *Nodep;

typedef struct BST {
	Nodep root;
	//may also have other members such as depth and count
}BST, *BSTp;

Nodep node_constr(int);
BSTp bst_constr();
void bst_destr(BSTp);
void destr_helper(Nodep);
void insert(BSTp, int);
int rem(BSTp, int);
int search(BSTp, int);
void DFT(Nodep);