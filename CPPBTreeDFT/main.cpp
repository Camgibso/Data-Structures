#include <iostream>
#include <cstdlib>
using namespace std;


//.h file
// Node Dec
struct node
{
	int info; //data held in node
	struct node *left;  //left/less than node
	struct node *right; //right/greather than node
}*root;
 
 
// Class Dec
class BST
{
	public:
		void search(int, node **, node **); //searches for num, parent and location
		void insert(node *,node *); //inserts num
		void rem(int);  //deletes a value
		void dft(node *);	//depth first traverse inorder
}bst;
//end of .h file
 
 
//start of main.cpp file
int main()
{
	int choice, num;
	node *temp;
	while (1)
	{
		cout<<"Options for tree: "<<endl;
		cout<<"1. Insert Element "<<endl;
		cout<<"2. Delete Element "<<endl;
		cout<<"3. Dft"<<endl;
		//cout<<"4. Search Value"<<endl;
		cout<<"5. Quit"<<endl;
		cout<<"Enter your choice: ";
		cin>>choice;
		switch(choice)
		{
			case 1:
				temp = new node;
				cout<<"Enter the value to be inserted: ";
				cin>>temp->info;
				bst.insert(root, temp);
				break;
			case 2:
				if (root == NULL)
				{
					cout<<"nothing to delete"<<endl;
					continue;
				}
				cout<<"Enter the value to be deleted: ";
				cin>>num;
				bst.rem(num);
				break;
			case 3:
				cout<<"DFT: "<<endl;
				bst.dft(root);
				cout<<endl;
				break;
			/*case 4:
				cout<<"Enter value to search"<<endl;
				cin>>num;
				bst.search(num);
			*/
			default:
				exit(1);
		}
	}
}
//end of main.cpp file


//start of bst.cpp file
//bst search fn
void BST::search(int item, node **par, node **loc)
{
	node *ptr, *ptrsave;
	if (root == NULL)
	{
		*loc = NULL;
		*par = NULL;
		return;
	}
	if (item == root->info)
	{
		*loc = root;
		*par = NULL;
		return;
	}
	if (item < root->info)
		ptr = root->left;
	else
		ptr = root->right;
	ptrsave = root;
	while (ptr != NULL)
	{
		if (item == ptr->info)
		{
			*loc = ptr;
			*par = ptrsave;
			return;
		}
		ptrsave = ptr;
		if (item < ptr->info)
			ptr = ptr->left;
		else
			ptr = ptr->right;
	}
	*loc = NULL;
	*par = ptrsave;
}
 
 
//bst insert fn
void BST::insert(node *tree, node *newnode)
{
	if (root == NULL)
	{
		root = new node;
		root->info = newnode->info;
		root->left = NULL;
		root->right = NULL;
		cout<<"Root Node is Added"<<endl;
		return;
	}
	if (tree->info == newnode->info)
	{
		cout<<"Element already in the tree"<<endl;
		return;
	}
	if (tree->info > newnode->info)
	{
		if (tree->left != NULL)
		{
			insert(tree->left, newnode);
		}
		else
		{
			tree->left = newnode;
			(tree->left)->left = NULL;
			(tree->left)->right = NULL;
			cout<<"Node Added To Left"<<endl;
			return;
		}
	}
	else
	{
		if (tree->right != NULL)
		{
			insert(tree->right, newnode);
		}
		else
		{
			tree->right = newnode;
			(tree->right)->left = NULL;
			(tree->right)->right = NULL;
			cout<<"Node Added To Right"<<endl;
			return;
		}
	}
}
 
 
//bst delete fn
void BST::rem(int item)
{
	node *parent, *location;
	
	if (root == NULL){
		cout<<"bst is empty"<<endl;
		return;
	}
	search(item, &parent, &location);
	
	if (location == NULL){
		cout<<"bst is empty"<<endl;
		return;
	}
	
	if(location->left == NULL && location->right == NULL){	//if left and right = null
		if (parent == NULL)    //if parent is null, root is null
		{
			root = NULL;
		}
		else{
			if (location == parent->left)   //if location is at parents left
				parent->left = NULL;   //set parents left to null
			else
			parent->right = NULL;  //if loc is at parents right
		} 
	} 
	
	if(location->left != NULL && location->right == NULL){ /*if left is not null and right is*/
		node *leaf;
		if (location->left != NULL)	//checks the left of the value
			leaf = location->left;	//if it is not null, set the value to the leaf
		else
			leaf = location->right;	//if left is null, set leaf to right value
		if (parent == NULL){		//if parent is null, set root to leaf
			root = leaf;
		}
		else{
			if (location == parent->left) //if val == to parents left or right, it is the leaf
				parent->left = leaf;
			else
				parent->right = leaf;
			}
	}

	if(location->left == NULL && location->right != NULL){	//if right is null and left isnt
		node *leaf;
		if (location->left != NULL)	//checks the left of the value
			leaf = location->left;	//if it is not null, set the value to the leaf
		else
			leaf = location->right;	//if left is null, set leaf to right value
		if (parent == NULL){		//if parent is null, set root to leaf
			root = leaf;
		}
		else{
			if (location == parent->left) //if val == to parents left or right, it is the leaf
				parent->left = leaf;
			else
				parent->right = leaf;
			}
	}
	
	if(location->left != NULL && location->right != NULL){ //if left and right are both filled
		node *ptr, *ptrsave, *locTwo, *parentTwo;	//temps
		ptrsave = location;	//save location
		ptr = location->right;	//set to right
		while (ptr->left != NULL)
		{
			ptrsave = ptr;
			ptr = ptr->left;
		}
		locTwo = ptr;
		parentTwo = ptrsave;
		if (locTwo->left == NULL && locTwo->right == NULL)
			if (parentTwo == NULL)    //if parent is null, root is null
			{
				root = NULL;
			}
			else{
				if (locTwo == parentTwo->left)   //if location is at parents left
					parentTwo->left = NULL;   //set parents left to null
				else
				parentTwo->right = NULL;  //if loc is at parents right
			} 


		else{
			node *leaf;
			if (locTwo->left != NULL)	//checks the left of the value
				leaf = locTwo->left;	//if it is not null, set the value to the leaf
			else
				leaf = locTwo->right;	//if left is null, set leaf to right value
			if (parentTwo == NULL){		//if parent is null, set root to leaf
				root = leaf;
			}
			else{
				if (locTwo == parentTwo->left) //if val == to parents left or right, it is the leaf
					parentTwo->left = leaf;
				else
					parentTwo->right = leaf;
			}
		}

		if (parent == NULL)
		{
			root = locTwo;
		}
		else
		{
			if (location == parent->left)
				parent->left = locTwo;
			else
				parent->right = locTwo;
		}
		locTwo->left = location->left;
		locTwo->right = location->right;

	}

	free(location);
}

// bst in order
void BST::dft(node *ptr)
{
	if (root == NULL)
	{
		cout<<"no values in tree"<<endl;
		return;
	}
	if (ptr != NULL)
	{
		dft(ptr->left);
		cout<<ptr->info<<"  ";
		dft(ptr->right);
	}
}
 