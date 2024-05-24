const int INF = 1e9;

vector<int> p; // parent
vector<bool> visited;
vector<vector<int>> graph;
const int N = 1000;
int capacity[N+1][N+1];
int n;

bool dfs(int u, int t) {
    visited[u] = true;
    
    if (u == t)
        return true;
    
    for (int next : graph[u]) {
        if (!visited[next] && capacity[u][next]) {
            if (dfs(next, t)) {
                p[next] = u;
                return true;
            }
        }
    }
    
    return false;
}

int fordFulkerson(int s, int t) {
    int maxflow = 0;
    while (dfs(s, t)) {
        int increment = INF;
        for (int u = t; p[u] >= 0; u = p[u]) 
            increment = min(increment, capacity[p[u]][u]);

        for (int u = t; p[u] >= 0; u = p[u]) {
            capacity[p[u]][u] -= increment;
            capacity[u][p[u]] += increment;
        }
        maxflow += increment;
        visited.assign(N+1, false);
        p.assign(N+1, -1);
    }
    return maxflow;
}
