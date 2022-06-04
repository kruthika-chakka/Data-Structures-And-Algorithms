#include<iostream>
#include <bits/stdc++.h> 
#include <cstdlib>
#include <queue>
using namespace std; 

int vertices = 10;
bool visited_dfs[10] = {false,false,false,false,false,false,false,false,false,false};
bool visited_bfs[10]  = {false,false,false,false,false,false,false,false,false,false};

void printGraph(int Mat[10][10]){
	int i,j;
	
	for(i=0; i< vertices; i++){
		for(j=0; j< vertices; j++){
			if(Mat[i][j] == 1)
			{
				cout << "Edge from " << i << " to " << j << endl;	
			}
		}
	}
	
}

void dfs(int startv, int Mat[10][10]){
	
	int i;
	
	//Print the start node
	cout << endl << startv;
	//Set start node to visited
	visited_dfs[startv] = true;
	//Rest of the nodes
	for(i = 0; i < vertices; i++){
		if (Mat[startv][i] == 1 && (!visited_dfs[i])) {
            dfs(i, Mat);
    	}
	}
	
}

 

void bfs(int startv, int Mat[10][10]){
	
	int i;
	int visitedv;
	// create a queue of capacity 10
    queue<int> q;
    

	//Set start node to visited
	visited_bfs[startv] = true;
	q.push(startv);
	
	//Rest of the nodes
	while(!q.empty())
	{
		visitedv = q.front();
		
		cout << visitedv << endl;
		q.pop();
		
		for(i=0 ; i< vertices; i++){
			if (Mat[visitedv][i] == 1 && (!visited_bfs[i])) {
				q.push(i);
				visited_bfs[i] = true;
			}
		}
	}
}

main()
{
	int adjMat[10][10]= { {0,1,1,0,0,0,0,0,0,1}, {1,0,0,1,0,1,1,0,0,0}, {1,0,0,1,0,0,0,0,0,1}, {0,1,1,0,1,0,1,0,0,0}, {0,0,0,1,0,1,0,1,1,0}, {0,1,0,0,1,0,1,1,0,0},  {0,1,0,1,0,1,0,1,1,0}, {0,0,0,0,1,1,1,0,1,1}, {0,0,0,0,1,0,1,1,0,1}, {1,0,1,0,0,0,0,1,1,0}  };	
	printGraph(adjMat);	
	
	int startv = 0;
	//ask for start vertex
	cout << "Start vertex for dfs: ";
	cin >> startv;
	dfs(startv,adjMat);
	cout << endl;
	
	cout << "Start vertex for bfs: ";
	cin >> startv;
	bfs(startv, adjMat);
}
