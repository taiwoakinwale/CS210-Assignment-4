#include <iostream>

using namespace std;

struct treeNode
{
	treeNode* left;
	treeNode* right;
	int data;
};

class BinarySearchTree
{
private:
	treeNode* root;
public:
	BinarySearchTree() { root = NULL; }

	bool isEmpty() const { return root == NULL; }
	
	void print_inorder();
	
	void inorder(treeNode*);
	
	void print_preorder();
	
	void preorder(treeNode*);
	
	void print_postorder();
	
	void postorder(treeNode*);
	
	void insert(int);
	
	void remove(int);
	
	void display();
	
	void displayTree(treeNode*, int);
	
	int searchTree(treeNode*, int);
	
	int search(int);
};
