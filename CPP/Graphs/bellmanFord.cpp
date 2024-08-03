/*
DANGER: I DIDN'T TEST THIS CODE (NOT SURE IF IT WORKS)
This version checks for negative cycles. You can easily disable that feature by deleting
the lastRelaxedVertex variable and making the main loop run until n-1 (inclusive).
It also has some pretty strange checking in the end, you can delete that too.
You can make it abort earlier by checking if the current vertex is t instead of generating
all the shortest distances.
*/

const int INF = 1e9;
using ii = pair<int, int>;

/*
GRAPH'S PAIR IS {LENGTH, VERTEX}
*/

vector<vector<ii>> graph;
int n;

vector<int> bellmanFord(int s, int t) {
    vector<int> d(n, INF);
    d[s] = 0;
    int lastRelaxedVertex;
    
    for (int i = 0; i < n; i++) {
        bool any = false;
        lastRelaxedVertex = -1;
        
        for (int v = 0; v < n; v++) {
            if (d[v] != INF) {
                for (auto[len, next] : graph[v]) {
                    if (d[v] + len < d[next]) {
                        d[next] = d[v] + len;
                        lastRelaxedVertex = next;
                        any = true;
                    }
                }
            }
        }
        
        if (!any)
            break;
    }
    
    if (lastRelaxedVertex != -1)
        d[t] = -1;
    return d;
}
