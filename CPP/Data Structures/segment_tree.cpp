/*
0-indexed queries
O(n) build
O(logn) query
O(logn) update
Don't forget to update the merge function according to your needs.
*/

const int MAXN = 1e5;

struct SegmentTree {
    int n, t[4*MAXN];
    
    SegmentTree(vector<int> &a) {
        n = a.size();
        build(a, 1, 0, n-1);
    }
    
    int merge(int a, int b) {
        return a * b;
    }
    
    void build(vector<int> &a, int v, int tl, int tr) {
        if (tl == tr) {
            t[v] = a[tl];
        } else {
            int tm = (tl + tr) / 2;
            build(a, v*2, tl, tm);
            build(a, v*2+1, tm+1, tr);
            t[v] = merge(t[v*2], t[v*2+1]);
        }
    }
    
    int query(int l, int r) {
        return query(l, r, 1, 0, n-1);
    }
    
    int query(int l, int r, int v, int tl, int tr) {
        if (l > r)
            return 1;
        if (l == tl && r == tr)
            return t[v];
        int tm = (tl + tr) / 2;
        return merge(
            query(l, min(r, tm), v*2, tl, tm),
            query(max(l, tm+1), r, v*2+1, tm+1, tr)
        );
    }
    
    void update(int pos, int new_val) {
        update(pos, new_val, 1, 0, n-1);
    }
    
    void update(int pos, int new_val, int v, int tl, int tr) {
        if (tl == tr) {
            t[v] = new_val;
        } 
        else {
            int tm = (tl + tr) / 2;
            if (pos <= tm)
                update(pos, new_val, v*2, tl, tm);
            else
                update(pos, new_val, v*2+1, tm+1, tr);
            t[v] = merge(t[v*2], t[v*2+1]);
        }
    }
};
