#include <bits/stdc++.h>
using namespace std;

const int INF = 1e9;
vector<int> bfs(vector<vector<int>> &graph, int start){
   
    vector<int> dist(graph.size(), INF);
    queue<int> q;

    dist[start] = 0;
    q.push(start);

    while(!q.empty()){
        int v = q.front();
        q.pop();


        for(int to : graph[v]){
            if(dist[to] > dist[v] + 1){
                dist[to] = dist[v] +1;
                q.push(to);
            }
        }
    }
    return dist;
}

int main(){
    int vectexConut, edgeCount; cin >> vectexConut >> edgeCount;

    vector<vector<int>>  graph(vectexConut);

    for(int i=0;i<edgeCount ;i++){
        int a,b;cin >> a >> b;
        graph[a].push_back(b);
        graph[a].push_back(a);
    }

    int start;cin >> start;

    vector<int> dist = bfs(graph, start);

    for(int d: dist){
        if(d != INF){
            cout << d << " ";
        }
        else{
            cout << "X ";
        }
    }
}