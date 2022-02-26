#include "Binary.h"

int main()
{
	BinarySearchTree b;
	int choice;
	char temp1, temp2;
	while (1)
	{
		cout << endl << endl;
		cout << " Binary Search Tree Operations " << endl;
		cout << " ----------------------------- " << endl;
		cout << " 1. Insertion/Creation " << endl;
		cout << " 2. In-Order Traversal " << endl;
		cout << " 3. Pre-Order Traversal " << endl;
		cout << " 4. Post-Order Traversal " << endl;
		cout << " 5. Removal " << endl;
		cout << " 6. Display " << endl;
		cout << " 7. Search " << endl;
		cout << " 8. Exit " << endl;
		cout << " Enter your choice : ";
		cin >> choice;
		switch (choice)
		{
		case 1: cout << " Enter Number to be inserted : ";
			cin >> temp1;
			b.insert(temp1);
			break;
		case 2: cout << endl;
			cout << " In-Order Traversal " << endl;
			cout << " -------------------" << endl;
			b.print_inorder();
			break;
		case 3: cout << endl;
			cout << " Pre-Order Traversal " << endl;
			cout << " -------------------" << endl;
			b.print_preorder();
			break;
		case 4: cout << endl;
			cout << " Post-Order Traversal " << endl;
			cout << " --------------------" << endl;
			b.print_postorder();
			break;
		case 5: cout << " Enter data to be deleted : ";
			cin >> temp2;
			b.remove(temp2);
			break;
		case 6: cout << "Display BST:" << endl;
			b.display();
			cout << endl;
			break;
		case 7: cout << " Enter data to be searched : ";
			cin >> temp2;
			if (b.search(temp2))
				cout << "Data is found" << endl;
			else
				cout << "Data Not found" << endl;

			break;
		case 8:
			return 0;
		}
		cin.ignore();
	}
}