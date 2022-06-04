#include <iostream>
#include <bits/stdc++.h>
using namespace std;

// Binary tree Node 
struct Node { 
    int val; 
    Node *left, *right; 
}; 

// Create new node
Node* newNode(int data)
{
    Node* temp = new Node;
 
    temp->val = data;
 
    temp->left = NULL;
    temp->right = NULL;
 
    return temp;
}

// Insert a new Node with given val in BST
Node* insert(Node* root, int newval)
{
    // Create a new Node containing the new element
    Node* newnode = newNode(newval);
 
    //Pointer to search where the new node should go
    Node* x = root;
 
    // Pointer y maintains the trailing  pointer of x
    Node* y = NULL;
    
    // If root isnot NULL
    while (x != NULL) {
        y = x;
        if (newval < x->val)
            x = x->left;
        else
            x = x->right;
    }
 	
	// If the root is NULL i.e the tree is empty, the new node is the root node
    if (y == NULL)
        y = newnode;
    // If the new key is less then the leaf node key assign the new node to be its left child
    else if (newval < y->val)
        y->left = newnode;
    // else assign the new node its right child
    else
        y->right = newnode;
 
    // Returns the pointer where the new node is inserted
    return y;
}
 
// Inorder traversal of BST
void Inorder_trav(Node* root)
{
    if (root == NULL)
        return;
    else {
        Inorder_trav(root->left);
        cout << root->val << " ";
        Inorder_trav(root->right);
    }
}

// Create_BST
Node* Create_BST(Node* root)
{
	bool add =  true;
	int choice= 0 , val = 0;
	Node* curr;
	
	while(add){
		cout << "1. Add to BST" << endl
		 	<< "2. Quit" << endl;
		cin >> choice;
		if(choice == 1)
		{		
			cout << "Enter node value: ";
			cin >> val;
			if(root == NULL)
				root = insert(root, val);
			else
				 insert(root, val);
			add = true;
		}
		else if(choice == 2)
		{
			cout << "Terminating inserting.\n";
			add = false;
		}
		else
		{
			cout << "Invalid response. Please enter again.";
			add= true;
		}
	}
	
	return root;
}

// Given a non-empty binary search tree, to find successor, find min value in the right tree of key node
Node* Successor(Node* node)
{
    Node* current = node;
 
    // loop down to find the leftmost leaf 
    while (current && current->left != NULL)
        current = current->left;
 
    return current;
}
 
// Delete function
Node* deleteNode(Node* temp, int key)
{
    // base case
    if (temp == NULL)
        return temp;
 
    // If the key to be deleted is smaller than the root's val, then it lies in left subtree
    if (key < temp->val)
        temp->left = deleteNode(temp->left, key);
 
    // If the key to be deleted is
    // greater than the root's
    // key, then it lies in right subtree
    else if (key > temp->val)
        temp->right = deleteNode(temp->right, key);
 
    // if key is same as root's key, then This is the node
    // to be deleted
    else {
        // node with only one child or no child
        if (temp->left == NULL) {
            Node* temp1 = temp->right;
            free(temp);
            return temp1;
        }
        else if (temp->right == NULL) {
            Node* temp1 = temp->left;
            free(temp);
            return temp1;
        }
 
        // node with two children: Get the inorder successor
        // (smallest in the right subtree)
        Node* temp1 = Successor(temp->right);
 
        // Copy the inorder successor's content to this node
        temp->val = temp1->val;
 
        // Delete the inorder successor
        temp->right = deleteNode(temp->right, temp1->val);
    }
	
    return temp;
}

// Delete nodes prompt for user
Node* Delete_from_BST(Node* root)
{
	bool del =  true;
	int choice= 0 , val = NULL;
	Node* curr;
	
	while(del){
		cout << "1. Delete from BST" << endl
		 	<< "2. Quit" << endl;
		cin >> choice;
		if(choice == 1)
		{		
			cout << "Enter key value to delete: ";
			cin >> val;
			if(root == NULL){
				cout << "Binary Search tree is empty.\n";
				return root;
			}
			else
			{
				deleteNode(root, val);
				// Inorder traversal
				cout << "Inorder Traversal:";
				Inorder_trav(root);
			}
			del = true;
		}
		else if(choice == 2)
		{
			cout << "Terminating deletion.\n";
			del = false;
		}
		else
		{
			cout << "Invalid response. Please enter again.\n";
			del= true;
		}
	}
	
	return root;
}

// main code
int main()
{
    Node* root = NULL;
    
    // Create the BST
    cout << "Create BST:\n";
    root = Create_BST(root);
    
    // Print inoder traversal of the BST
    cout << "Inorder Traversal:";
    Inorder_trav(root);
    
    cout << "Initiate Delete:\n";
    root = Delete_from_BST(root);
 
    return 0; 
}
