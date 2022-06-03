#include <bits/stdc++.h> 
#include <iostream>
using namespace std; 

// Linked List Node 
struct Node { 
    int data; 
    Node* next; 
}; 

// function to create a new Linked List Node 
Node* newNode(int val) 
{ 
    Node* temp = new Node; 
  
    temp->data = val; 
  
    temp->next = NULL; 
  
    return temp; 
} 

Node* createlist(Node* head, Node* tail)
{
	bool add =  true;
	int choice, val;
	Node* curr;
	
	while(add){
		cout << "1. Add to list" << endl
		 	<< "2. Quit" << endl;
		cin >> choice;
		if(choice == 1)
		{		
			cout << "Enter node value: ";
			cin >> val;
			curr = newNode(val);
			
			// if the new node is the head
			if(head == NULL)
			{
				head = curr;
				tail = curr;
			}
			else
			{
				tail->next = curr;
				tail = tail->next;
			}
			add = true;
		}
        else
        {
        	cout << "Ending programn" << endl;
        	add = false;
		}
	}
	return head;
}
// Function to traverse the list 
void trav(Node* head) 
{ 
   	cout << "Traversal:" << endl;
    while (head) { 
        cout << head->data << " "; 
        head = head->next; 
    } 
    cout <<  endl;
} 


//selection sort
Node* sSort(Node* head) 
{ 
    Node *prev_1, *prev_2, *curr_1, *curr_2, *r; 
  
    prev_1 = prev_2 = head; 
  	
  	cout << "Sorted list" << endl;
    // While prev_2 is not the last node 
    while (prev_2->next) { 
         curr_1 = curr_2 = prev_2->next; 
  
        // While curr_2 is pointing to a valid node 
        while (curr_2) { 
  
            if (prev_2->data > curr_2->data) { 
                // Case 1: prev_2 is the head of the linked list 
                if (prev_2 == head) { 
  
                    // Swap prev_2->next and curr_2->next 
                    r = prev_2->next; 
                    prev_2->next = curr_2->next; 
                    curr_2->next = r; 
                    curr_1->next = prev_2; 
  
                    // Swap prev_2 and curr_2 pointers 
                    r = prev_2; 
                    prev_2 = curr_2; 
                    curr_2 = r; 
                    curr_1 = curr_2; 
  
                    // Skip to the next element 
                    // as it is already in order 
                    curr_2 = curr_2->next; 
  
                    // Update the head 
                    head = prev_2; 
                } 
  
                // Case 2: prev_2 is not the head of the linked list 
                else { 
  
                    // Swap prev_2->next and curr_2->next 
                    r = prev_2->next; 
                    prev_2->next = curr_2->next; 
                    curr_2->next = r; 
                    curr_1->next = prev_2; 
                    prev_1->next = curr_2; 
  
                    // Swap prev_2 and curr_2 pointers 
                    r = prev_2; 
                    prev_2 = curr_2; 
                    curr_2 = r; 
  
                    curr_1 = curr_2; 
  
                    // Skip to the next element 
                    // as it is already in order 
                    curr_2 = curr_2->next; 
                } 
            }
            else { 
  
                // Update curr_1 and skip to the next element 
                // as it is already in order 
                curr_1 = curr_2; 
                curr_2 = curr_2->next; 
            } 
        }
    prev_1 = prev_2; 
    prev_2 = prev_2->next; 
    } 
  
    return head; 
}


// main code 
int main() 
{ 
    // Make the list
    Node* head = NULL;
	Node* tail = NULL; 
       
    head = createlist(head, tail);
    
    // first print the list
    trav(head);

    // selection sort
    head = sSort(head); 
    
    // print list after sort
    trav(head); 
  
    return 0; 
} 

