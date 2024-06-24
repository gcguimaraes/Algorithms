const int MAXN = 1e5;

struct SegmentTree {
    struct Segment {
        int b, e, sum;
    };

    int n;
    Segment *t;
    int *lazy;
    
    SegmentTree(vector<int> &a) {
        n = a.size();
        t = new Segment[3*MAXN];
        lazy = new int[3*MAXN];
        build(a, 1, 0, n-1);
    }

    void build(vector<int> &a, int node, int l, int r) {
        t[node].b = l;
        t[node].e = r;
        if (l == r)
            t[node].sum = a[l];
        else {
            int mid = (l + r) / 2;
            build(a, 2*node, l, mid);
            build(a, 2*node+1, mid+1, r);
            t[node].sum = t[2*node].sum + t[2*node+1].sum;
        }
    }

    int query(int node, int l, int r) {
        if (t[node].b > r || t[node].e < l)
            return 0; // neutral
        
        if (lazy[node] != 0) {
            t[node].sum += (t[node].e - t[node].b + 1) * lazy[node];
            if (t[node].b != t[node].e) { // if leaf
                lazy[2*node] += lazy[node];
                lazy[2*node+1] += lazy[node];
            }
            lazy[node] = 0;
        }

        if (t[node].b >= l && t[node].e <= r)
            return t[node].sum;
        
        int s1 = query(2*node, l, r);
        int s2 = query(2*node+1, l, r);
        return s1 + s2;
    }
    int query(int l, int r) { return query(1, l, r); }

    void update(int node, int l, int r, int val) {
        if (lazy[node] != 0) {
            t[node].sum += (t[node].e - t[node].b + 1) * lazy[node];
            if (t[node].b != t[node].e) { // if leaf
                lazy[2*node] += lazy[node];
                lazy[2*node+1] += lazy[node];
            }
            lazy[node] = 0;
        }

        if (t[node].b > r || t[node].e < l)
            return;
        
        if (t[node].b >= l && t[node].e <= r) { // if this segment is within updated segment
            t[node].sum += (t[node].e - t[node].b + 1) * val;
            if (t[node].b != t[node].e) { // if leaf
                lazy[2*node] += val;
                lazy[2*node+1] += val;
            }
            return;
        }
        
        update(2*node, l, r, val);
        update(2*node+1, l, r, val);
        t[node].sum = t[2*node].sum + t[2*node+1].sum;
    }
    void update(int l, int r, int val) { update(1, l, r, val); }
};
