#include <bits/stdc++.h>
using namespace std;


void BFS(int start, const vector<vector<int>>& adjList) {
    vector<bool> visited(adjList.size(), false); 
    queue<int> q;

    visited[start] = true; 
    q.push(start); 

    while (!q.empty()) {
        int vertex = q.front(); 
        q.pop(); 

        cout << vertex << " "; 

    
        for (int neighbor : adjList[vertex]) {
            if (!visited[neighbor]) { 
                visited[neighbor] = true; 
                q.push(neighbor); 
            }
        }
    }
}

int main() {
    
    vector<vector<int>> adjList = {
        {1, 2},   
        {0, 3, 4}, 
        {0, 4},    
        {1, 4, 5}, 
        {1, 2, 3}, 
        {3}       
    };

    int startVertex = 0;
    cout << "BFS traversal starting from vertex " << startVertex << ": ";
    BFS(startVertex, adjList); 

    return 0;
}
