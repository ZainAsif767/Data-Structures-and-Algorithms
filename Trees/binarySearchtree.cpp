#include <iostream>
using namespace std;
struct Node
{
	int data;
	struct Node *left;
	struct Node *right;
};
Node *FindMin(Node *root)
{
	while (root->left != NULL)
		root = root->left;
	return root;
}
struct Node *Delete(Node *root, int data)
{
	if (root == NULL)
		return root;
	else if (data < root->data)
		root->left = Delete(root->left, data);
	else if (data > root->data)
		root->right = Delete(root->right, data);
	else
	{
		// Case 1:  No child
		if (root->left == NULL && root->right == NULL)
		{
			delete root;
			root = NULL;
		}
		// Case 2: One child
		else if (root->left == NULL)
		{
			struct Node *temp = root;
			root = root->right;
			delete temp;
		}
		else if (root->right == NULL)
		{
			struct Node *temp = root;
			root = root->left;
			delete temp;
		}
		// case 3: 2 children
		else
		{
			struct Node *temp = FindMin(root->right);
			root->data = temp->data;
			root->right = Delete(root->right, temp->data);
		}
	}
	return root;
}

// Function to visit nodes in Inorder
void Asscending(Node *root) /*Asscending Order*/
{
	if (root == NULL)
		return;

	Asscending(root->left);	   // Visit left subtree
	cout << root->data << " "; // Print data
	Asscending(root->right);   // Visit right subtree
}
void Descending(Node *root) /*Descending order*/
{
	if (root == NULL)
		return;
	Descending(root->right);
	cout << root->data << " ";
	Descending(root->left);
}

// minimun value using iteration
void minval(Node *root)
{
	Node *current = root;
	while (current->left != NULL)
		current = current->left;
	cout << "Min Value :" << current->data;
	return;
}

// maximum value using iteration
void maxval(Node *root)
{
	Node *current = root;
	while (current->right != NULL)
		current = current->right;
	cout << "Max Value :" << current->data;
	return;
}

// Function to Insert Node in a Binary Search Tree
Node *Insert(Node *root, int data)
{
	if (root == NULL)
	{
		root = new Node();
		root->data = data;
		root->left = root->right = NULL;
	}
	else if (data <= root->data)
		root->left = Insert(root->left, data);
	else
		root->right = Insert(root->right, data);
	return root;
}

int main()
{
	/*Code To Test the logic
	  Creating an example tree
				5
			   / \
			  3   10
			 / \   \
			1   4   11
	*/
	Node *root = NULL;
	root = Insert(root, 99);
	root = Insert(root, 10);
	root = Insert(root, 3);
	root = Insert(root, 4);
	root = Insert(root, 1);
	root = Insert(root, 11);
	root = Insert(root, 2);
	// Deleting node with value 4, change this value to test other cases
	// root = Delete(root, 4);

	// Print Nodes in Inorder
	cout << "Asscendign order: ";
	Asscending(root);
	cout << "\n";
	// Print nodes in Postorder
	cout << "Descending order: ";
	Descending(root);
	cout << "\n";
	minval(root);
	cout << "\n";
	maxval(root);
}
