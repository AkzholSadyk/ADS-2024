#include <iostream>
#include <vector>

using namespace std;

void DFS(int vertex, const vector<vector<int>>& adjList, vector<bool>& visited) {
    visited[vertex] = true;
    cout << vertex << " ";
    for (int neighbor : adjList[vertex]) {
        if (!visited[neighbor]) {
            DFS(neighbor, adjList, visited);
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
    vector<bool> visited(adjList.size(), false);

    cout << "DFS traversal starting from vertex " << startVertex << ": ";
    DFS(startVertex, adjList, visited);

    return 0;
}
