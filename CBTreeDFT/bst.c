#include "bst.h"
#include <stdio.h>
#include <stdlib.h>

Nodep node_constr(int num) {
	Nodep newNode = (Nodep)malloc(sizeof(Node));
	newNode->datum = num;
	newNode->left = NULL;
	newNode->right = NULL;
	newNode->parent = NULL;
	return newNode;
}

BSTp bst_constr() {
	BSTp newBST = (BSTp)malloc(sizeof(BST));
	newBST->root = NULL;
	return newBST;
}

void bst_destr(BSTp bst) {
	destr_helper(bst->root);
	free(bst);
}

void destr_helper(Nodep node) {
	if (node == NULL) {
		return;
	}
	else {
		destr_helper(node->left);
		destr_helper(node->right);
		free(node);
	}
}

void insert(BSTp bst, int num) {
	Nodep newNode = node_constr(num);

	if (bst->root == NULL) {
		bst->root = newNode;
	}
	else {
		Nodep temp = bst->root;
		while (1) {
			if (num <= temp->datum) {
				if (temp->left == NULL) {
					temp->left = newNode;
					newNode->parent = temp;
					break;
				}
				else {
					temp = temp->left;
				}
			}
			else {
				if (temp->right == NULL) {
					temp->right = newNode;
					newNode->parent = temp;
					break;
				}
				else {
					temp = temp->right;
				}
			}
		}
	}
}

int rem(BSTp tree, int num) {
	Nodep temp = tree->root;

	//search the tree for the number
	while (temp) {
		if (temp->datum == num) {
			break;
		}
		else {
			if (num < temp->datum) {
				temp = temp->left;
			}
			else {
				temp = temp->right;
			}
		}
	}

	//return if the number is not found
	if (temp == NULL) {
		return 0;
	}
	//remove the number if it is found
	else {
		//check the right 
		if (temp->right == NULL) {
			//if the left is also null set the appropriate
			//parent pointer to null 
			if (temp->left == NULL) {
				if (temp->parent == NULL) {
					tree->root = NULL;
				}
				else if (temp == temp->parent->left) {
					temp->parent->left = NULL;
				}
				else {
					temp->parent->right = NULL;
				}

			}
			//if the left is set instead then move temp's
			//left to the appropriate subnode; 
			else {
				if (temp->parent != NULL) {
					if (temp == temp->parent->left) {
						temp->parent->left = temp->left;
					}
					else {
						temp->parent->right = temp->left;
					}
				}
				temp->left->parent = temp->parent;
			}
			free(temp);
		}
		//if the right is not null
		else {
			//if the left is null move the right up
			if (temp->left = NULL) {
				if (temp->parent != NULL) {
					if (temp == temp->parent->left) {
						temp->parent->left = temp->right;
					}
					else {
						temp->parent->right = temp->right;
					}
				}
				temp->right->parent = temp->parent;
				free(temp);
			}
			//shit just got real
			else {
				//start at the top of the right subtree
				Nodep temp2 = temp->right;
				//iterate to the bottom left of the right 
				//subtree
				while (temp2->left != NULL) {
					temp2 = temp2->left;
				}
				//put temp2's dataum into temp
				temp->datum = temp2->datum;
				//if we didn't move when we traversed left
				if (temp2 == temp->right) {
					//set temp's right
					temp->right = temp2->right;
				}
				else {
					//set temp2's parent's left
					temp2->parent->left = temp2->right;
				}
				//set the right subnode's parent
				if (temp2->right != NULL) {
					temp2->right->parent = temp2->parent;
				}
				free(temp2);
			}
		}
	}
	return 1;
}

int search(BSTp tree, int num) {
	Nodep temp = tree->root;

	while (temp != NULL) {
		if (temp->datum == num) {
			return 1;
		}
		else if (num <= temp->datum) {
			temp = temp->left;
		}
		else {
			temp = temp->right;
		}
	}

	return 0;
}

void DFT(Nodep node) {
	if (node == NULL) {
		return;
	}
	else {
		DFT(node->left);
		printf("%d\n", node->datum);
		DFT(node->right);
	}
}