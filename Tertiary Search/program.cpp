#include <bits/stdc++.h> 
#include <iostream>
using namespace std; 

int rTertiarysearch(int a[], int l, int h, int val)
{
    int diff, p, q;
    if (l>h) return -1;
	// find division points
    diff = (h-l)/3;
   
	p = l + diff; 
    q = h - diff;
	
    // Start end cases
    
    if (a[p] == val) return p;
    if (a[q] == val) return q;
    
    // Recursion
    if (val < a[p]) h = p-1;
    else{
        l = p+1;
        if (val < a[q])
            h= q-1;
        else
            l= q+1;
		}
    return rTertiarysearch(a,l,h,val);
}


int main()
{
    // Create tertiary search array 
    int n,i;
    int v, pos;
    cout << "Enter the number of elements in tertiary search array: ";
    cin >> n;
	
	int a[n];
    while(i <= n-1)
    {
        cout << "Enter element number " << i << " : ";
        cin >> a[i];
        i = i+1;
    }

    // Get the element to be searched
    cout << "Enter the element to be searched: ";
    cin >> v;
    pos = rTertiarysearch(a,0,n-1,v);

    // If element is found, print element position in array. If element not found, return message
    if(pos == -1)
        cout << "Element not found.";
    else
        cout << "Element found at index " << pos << " in array.";
}
