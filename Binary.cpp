#include "Binary.h"


void BinarySearchTree::insert(int d) // smaller items to the left bigger to right
{
	treeNode* t = new treeNode;
	treeNode* parent;
	t->data = d;
	t->left = NULL;
	t->right = NULL;
	parent = NULL;

	// check to see if there is already a tree started
	if (isEmpty()) root = t;
	else
	{
		// incert the node as a leaf
		treeNode* curr;
		curr = root;
		// Find parent node
		while (curr)
		{
			parent = curr;
			if (t->data > curr->data) curr = curr->right;
			else curr = curr->left;
		}

		if (t->data < parent->data)
			parent->left = t;
		else
			parent->right = t;
	}
}
void BinarySearchTree::remove(int d)
{
	bool found = false;
	// check to see if the tree is empty
	if (isEmpty())
	{
		cout << " This Tree is empty! " << endl;
		return;
	}
	
	treeNode* curr;
	treeNode* parent;
	curr = root;
	parent = curr;

	// start searching for the element
	while (curr != NULL)
	{
		if (curr->data == d)
		{
			found = true;
			break;
		}
		else
		{
			parent = curr;
			if (d > curr->data) curr = curr->right;
			else curr = curr->left;
		}
	}

	if (!found) // if it goes through the whole tree and there are no matching elements found then the coresponding information will print
	{
		cout << " Data not found! " << endl;
		return;
	}

	// look for a node then check to see if there are children nodes and how many and where
	if ((curr->left == NULL && curr->right != NULL) || (curr->left != NULL && curr->right == NULL))
	{

		if (curr->left == NULL && curr->right != NULL)
		{
			if (parent->left == curr)
			{
				parent->left = curr->right;
				delete curr;
			}
			else
			{
				parent->right = curr->right;
				delete curr;
			}
		}

		else // no right child but ther is a left
		{
			if (parent->left == curr)
			{
				parent->left = curr->left;
				delete curr;
			}
			else
			{
				parent->right = curr->left;
				delete curr;
			}
		}
		return;
	}

	// looking at a leaf node
	if (curr->left == NULL && curr->right == NULL)
	{
		if (parent->left == curr) parent->left = NULL;
		else parent->right = NULL;
		delete curr;
		return;
	}

	// Node with 2 children
	// replace node with smallest value in right subtree
	if (curr->left != NULL && curr->right != NULL)
	{
		treeNode* chkr;
		chkr = curr->right;
		if ((chkr->left == NULL) && (chkr->right == NULL))
		{
			curr = chkr;
			delete chkr;
			curr->right = NULL;
		}
		else // right child has children
		{
			//if the node's right child has a left child
			// Move all the way down left to locate smallest element
			if ((curr->right)->left != NULL)
			{
				treeNode* lcurr;
				treeNode* lcurrp;
				lcurrp = curr->right;
				lcurr = (curr->right)->left;
				while (lcurr->left != NULL)
				{
					lcurrp = lcurr;
					lcurr = lcurr->left;
				}
				curr->data = lcurr->data;
				delete lcurr;
				lcurrp->left = NULL;
			}
			else
			{
				treeNode* tmp;
				tmp = curr->right;
				curr->data = tmp->data;
				curr->right = tmp->right;
				delete tmp;
			}
		}
		return;
	}
}

// prints the tree in order
void BinarySearchTree::print_inorder()
{
	inorder(root);
}
void BinarySearchTree::inorder(treeNode* p)
{
	if (p != NULL)
	{
		if (p->left) inorder(p->left);
		printf(" %c ", p->data);
		if (p->right) inorder(p->right);
	}
	else return;
}
void BinarySearchTree::print_preorder()
{
	preorder(root);
}
void BinarySearchTree::preorder(treeNode* p)
{
	if (p != NULL)
	{
		printf(" %c ", p->data);
		if (p->left) preorder(p->left);
		if (p->right) preorder(p->right);
	}
	else return;
}
void BinarySearchTree::print_postorder()
{
	postorder(root);
}
void BinarySearchTree::postorder(treeNode* p)
{
	if (p != NULL)
	{
		if (p->left) postorder(p->left);
		if (p->right) postorder(p->right);
		printf("%c ", p->data);
	}
	else return;
}
void BinarySearchTree::displayTree(treeNode* ptr, int level)
{
	int i;
	if (ptr != NULL)
	{
		displayTree(ptr->right, level + 1);
		cout << endl;
		if (ptr == root)
			cout << "Root->: ";
		else
		{
			for (i = 0; i < level; i++)
				cout << " ";
		}
		printf("%c ", ptr->data);
		displayTree(ptr->left, level + 1);
	}
}
void BinarySearchTree::display()
{
	displayTree(root, 1);
}

int BinarySearchTree::searchTree(treeNode* ptr, int item)
{
	if (ptr == NULL)
		return 0;
	if (ptr->data == item) {
		return 1;
	}
	if (ptr->data < item)
		return searchTree(ptr->right, item);

	return searchTree(ptr->left, item);
}
int BinarySearchTree::search(int item)
{
	return searchTree(root, item);
}
