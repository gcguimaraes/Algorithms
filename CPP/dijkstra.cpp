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
        ii dv = pq.top(); pq.pop();
       
        int dist = dv.first;
        int v = dv.second;
        
        if (dist != d[v])
            continue;
            
        for (ii dv : graph[v]) {
            int newDist = dist + dv.first;
            int next = dv.second;
            if (newDist < d[next]) {
                d[next] = newDist;
                pq.push({newDist, next});
            }
        }
    }
    return d;
}
