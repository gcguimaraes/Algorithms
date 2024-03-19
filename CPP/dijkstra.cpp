// The graph's pair<int, int> should be {distance, vertex}

#include <bits/stdc++.h>

using namespace std;

#define INF 1e9
#define ii pair<int, int>

vector<vector<ii>> graph;

vector<int> dijkstra(int s, int n) {
    vector<int> d(n, INF);
    d[s] = 0;
    
    priority_queue<ii, vector<ii>, greater<ii>> pq;
    pq.push({0, s});
    
    while (!pq.empty()) {
        auto [dist, v] = pq.top(); pq.pop();
        
        if (dist != d[v])
            continue;
            
        for (auto [len, next] : graph[v]) {
            int newDist = dist + len;
            if (newDist < d[next]) {
                d[next] = newDist;
                pq.push({newDist, next});
            }
        }
    }
    return d;
}
