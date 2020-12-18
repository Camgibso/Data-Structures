#include "bst.h"
#include <stdlib.h>

int main() {
	BSTp myTree = bst_constr();

	insert(myTree, 10);
	insert(myTree, 5);
	insert(myTree, 2);
	insert(myTree, 7);
	insert(myTree, 15);
	insert(myTree, 12);
	insert(myTree, 17);
	DFT(myTree->root);

	bst_destr(myTree);
	return 0;
}