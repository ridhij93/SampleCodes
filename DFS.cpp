// The code is taked from GeeksforGeeks and is modified
// C++ program to print DFS traversal from
// a given vertex in a  given graph
#include <bits/stdc++.h>
using namespace std;
class Graph 
{
public:
    map<int, bool> visited; // mark visited vertices
    map<int, list<int>> graph; //adjacency list representation of a graph
  
    // function to add an edge to graph
    void createEdge(int v, int w);
  
    // DFS traversal of the vertices
    // reachable from v
    void DFS(int v);
};
  
void Graph::addEdge(int v, int w)
{
    adj[v].push_back(w); // Add w to v’s list.
}
  
void Graph::DFS(int v)
{
    // Mark the current node as visited and
    // print it
    visited[v] = true;
    cout << v << " ";
  
    // Recur for all the vertices adjacent
    // to this vertex
    list<int>::iterator i;
    for (i = adj[v].begin(); i != adj[v].end(); ++i)
        if (!visited[*i])
            DFS(*i);
}
  
// Driver code
int main()
{
    // Create a graph given in the above diagram
    Graph g;
    int n;
    cout << "Enter number of edges "<<endl;
    cin >> n;
    cout << "Enter "<< n << " edges as v1 v2:"<<endl;
   	int v1, v2;
    for (int i = 0; i < n; i++)
    {
			std::cin >> v1;
			std::cin >> v2;
			g.addEdge(v1, v2);
			g.addEdge(v2, v1);
    }
    
  	int startpoint;
    cout << "Enter starting vertex:"<< endl;
		cin >> startpoint;
    g.DFS(startpoint);
  
    return 0;
}
  

