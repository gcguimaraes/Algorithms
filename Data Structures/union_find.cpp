/*
  Constructor receives an integer n that is the amount of sets to be initially created.
  0-indexed.
*/

struct UnionFind {
    vector<int> parent, size;
    
    UnionFind(int n) {
        parent.reserve(n);
        size.assign(n, 1);
        
        for (int i = 0; i < n; i++)
            parent.push_back(i);
    }
    
    int find(int v) {
        if (v == parent[v])
            return v;
        return parent[v] = find(parent[v]);
    }
    
    void unionSets(int a, int b) {
        a = find(a);
        b = find(b);
        if (a != b) {
            if (size[a] < size[b])
                swap(a, b);
            parent[b] = a; // subordinate b to a (smaller to bigger)
            size[a] += size[b];
        }
    }
};
