#include <bits/stdc++.h>
#include <iostream>
#include <vector>
using namespace std;

enum Color {White, Gray, Black}; // Status of vertices



class Graph
{
    int vertices; // No. of vertices
    list<int>* adj_list; // adjacency lists
  
    // DFS traversal of the vertices from v
    bool DFSUtil(int v, int color[]);
    void topovertex(int v, bool visited[], stack<int>& Stack);
    
public:
    Graph(int vertices);  
  
    //add an edge to graph
    void addEdge(int v, int w);
  
    bool isCyclic();
    void DFSTopo();
    void BFSTopo();
};

//Graph constructor
Graph::Graph(int vertices)
{
    this->vertices = vertices;
    adj_list = new list<int>[vertices];
}

// Add edge function
void Graph::addEdge(int v, int w)
{
    adj_list[v].push_back(w); // Add w to v's list.
}

// Function to find if there is a loop 
bool Graph::DFSUtil(int u, int color[])
{
    color[u] = Gray; // vertex is visited
  
    list<int>::iterator i;
    for (i = adj_list[u].begin(); i != adj_list[u].end(); ++i)
    {
        int v = *i;  
  
        // If adjacent vertex is already visited, return 
        if (color[v] == Gray)
          return true;
  		
  		//If adjacent vertex is not visited and not done
        if (color[v] == White && DFSUtil(v, color))
          return true;
    }
  
    // Mark this vertex as done
    color[u] = Black;
  
    return false;
}
  
//Check if cycle exists
bool Graph::isCyclic()
{
    // In the beginning color of all vertices are White
    int *color = new int[vertices];
    for (int i = 0; i < vertices; i++)
        color[i] = White;
  
    // Do a DFS traversal for all white nodes
    for (int i = 0; i < vertices; i++)
        if (color[i] == White)
           if (DFSUtil(i, color) == true)
              return true;
  
    return false;
}

// Recursion for topo sort dfs
void Graph::topovertex(int v, bool visited[], stack<int>& Stack)
{
    // current node should be visited.
    visited[v] = true;
 
    //topo sort for all adjacent vertices
    list<int>::iterator i;
    for (i = adj_list[v].begin(); i != adj_list[v].end(); ++i)
        if (!visited[*i])
            topovertex(*i, visited, Stack);
 
    // Push current vertex to stack
    Stack.push(v);
}

// DFS Topoligical sort
void Graph::DFSTopo()
{
    stack<int> Stack;
 
    // Mark all the vertices as not visited
    bool* visited = new bool[vertices];
    for (int i = 0; i < vertices; i++)
        visited[i] = false;
 
    for (int i = 0; i < vertices; i++)
        if (visited[i] == false)
            topovertex(i, visited, Stack);
 
    // Print DFS topo sort order
    while (Stack.empty() == false) {
        cout << Stack.top() << " ";
        Stack.pop();
    }
}
 
  
// BFS topological sort
void Graph::BFSTopo()
{
    // Vector to store indegrees of all vertices. All indegrees in the beginning are 0.
    vector<int> in_degree(vertices, 0);
  
    // Go through the adjacency lists to fill indegrees of all vertices.  
    for (int i = 0; i < vertices; i++) {
        list<int>::iterator j;
        for (j = adj_list[i].begin(); j != adj_list[i].end(); j++)
            in_degree[*j]++;
    }
  
    // Queue to enqueue all vertices with indegree 0
    queue<int> q;
    for (int i = 0; i < vertices; i++)
        if (in_degree[i] == 0)
            q.push(i);
  
    // Initialize count of visited vertices
    int count = 0;
  
    // Vector to store BFS topo order
    vector<int> BFSTopo_order;
  
    // dequeue from queue and enqueue adjacents if its indegree becomes 0
    while (!q.empty()) {
		
		// add to BFSTopo_order
        int u = q.front();
        q.pop();
        BFSTopo_order.push_back(u);
  
        // decrease adjacent nodes' indegree by 1 
        list<int>::iterator j;
        for (j = adj_list[u].begin(); j != adj_list[u].end(); j++)
  
            //Add all indegree 0 vertices to queue
            if (--in_degree[*j] == 0)
                q.push(*j);
  
        count++;
    }
  
    // Print topological order
    for (int i = 0; i < BFSTopo_order.size(); i++)
        cout << BFSTopo_order[i] << " ";
    cout << endl;
}
 
int main()
{
	int choice=1, x, y, u, v;
	//Build graph
	cout << "Enter number of vertices: ";
	cin >> x;
	
	cout << "Enter number of Edges: ";
	cin >> y;
	
	
	// Take graph as input from user
	Graph g(x);
	
	for(int i=0; i < y; i++){
		cout << "Enter edge from u to v as u [space] v: ";
        cin >> u;
        cin >> v;
        g.addEdge(u, v);
		
	}
	
	if(g.isCyclic()){
			cout << "Cycle in graph." << endl
				<< "Program terminated."
				<< endl << "Run the program again an input a valid graph.";
			return 0;
		}
	else{
		cout << "Graph does not have a cycle." << endl;
		cout<< "Choose which topological sort to be done: " << endl
			<< "1. DSF" << endl 
			<< "2. BSF" << endl;
		cin >> choice;
		if (choice == 1){
			cout << "The DFS topological sort of the given graph is: " << endl;
			g.DFSTopo();
		}
		else if(choice == 2){
			cout << "The BFS topological sort of the given graph is: " << endl;
			g.BFSTopo();
		}
    }
		
	
	
	
	/*insert edges
	add_edge(0,11); 
	add_edge(0,4);
	add_edge(0,5);
	add_edge(1,4);	
	add_edge(1,8);
	add_edge(1,2);
	add_edge(2,5);
	add_edge(2,9);
	add_edge(2,6);
	add_edge(3,2);
	add_edge(3,6);
	add_edge(3,13);
	add_edge(4,7);
	add_edge(5,8);
	add_edge(5,12);
	add_edge(6,5);
	add_edge(8,7);
	add_edge(9,11);
	add_edge(9,10);
	add_edge(10,13);
	add_edge(12,9);*/
	
	
}
 
