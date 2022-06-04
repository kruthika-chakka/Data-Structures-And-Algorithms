#include<iostream> 
using namespace std; 

// To heap a subtree 
void heap_subT(int arr[], int n, int i) 
{ 
	int smallest = i; // Initialize smallest as root 
	int l = 2 * i; // left = 2*i 
	int r = 2 * i + 1; // right = 2*i + 1 

	// If left child is smaller than root 
	if (l < n && arr[l] < arr[smallest]) 
		smallest = l; 

	// If right child is smaller than all 
	if (r < n && arr[r] < arr[smallest]) 
		smallest = r; 

	// If smallest is not root 
	if (smallest != i) { 
		swap(arr[i], arr[smallest]); 

		// Recursively heapify the affected sub-tree 
		heap_subT(arr, n, smallest); 
	} 
} 

// Function to build a Min-Heap from the given array 
void buildHeap(int arr[], int n) 
{ 
	// Index of last parent node 
	int startIdx = (n / 2); 

	// Start from last parent and go till index 1. Since index 0 has the number of array elements 
	for (int i = startIdx; i > 0; i--) { 
		heap_subT(arr, n, i); 
	} 
} 

void print_heap(int arr[], int n)
{
	for (int i = 0; i<=n; i++){
		cout << arr[i] << " ";
	}
}


void heap_sort(int arr[], int n)
{
	int i;
	for(i = n; i >= 1 ; i--){
		swap(arr[i], arr[1]); // Move root to the end of the array
		heap_subT(arr, i, 1);
	}

}
 
int main() 
{ 

    // Assumed Array 
	int arr[] ={15, 10, 30, 68, 5, 9, 12, 73, 8, 4, 2, 19, 35, 16, 23, 55}; 

	int n = arr[0]; 
	// Build the heap using floyd's algorithm
	buildHeap(arr, n); 

	//Print heap 
	cout << "Array after conerting it into heap using floyd's algorithm is:\n";
	print_heap(arr,n);
	
	// Sorting array using heap sort
	heap_sort(arr,n);
	
	//Print heap 
	cout << endl << "Array after heap sort is:\n";
	print_heap(arr,n);
	
	return 0; 
} 
