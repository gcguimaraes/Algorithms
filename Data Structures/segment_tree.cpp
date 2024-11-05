/*
0-indexed queries
O(n) build
O(logn) query
O(logn) update
*/

class SegmentTree {
    struct Segment {
        int l, r, val;
    };
    static const int MAXN = 1e6 + 10;
    const int NEUTRAL = 0;
    Segment t[4*MAXN];

    void build(vector<int> &a, int v, int tl, int tr) {
        t[v] = {tl, tr, 0};
        if (tl == tr)
            t[v].val = a[tl];
        else {
            int mid = (tl + tr) / 2;
            build(a, 2*v, tl, mid);
            build(a, 2*v+1, mid+1, tr);
            merge(v);
        }
    }

    void merge(int v) {
        t[v].val = t[2*v].val + t[2*v+1].val;
    }
    int merge(int a, int b) {
        return a + b;
    }

    int query(int v, int l, int r) {
        if (t[v].l > r || t[v].r < l)
            return NEUTRAL;
        if (t[v].l >= l && t[v].r <= r)
            return t[v].val;
        int left = query(2*v, l, r);
        int right = query(2*v+1, l, r);
        return merge(left, right);
    }

    void update(int v, int i, int delta) {
        if (t[v].l > i || t[v].r < i)
            return;
        if (t[v].l >= i && t[v].r <= i) {
            t[v].val += delta;
            return;
        }
        update(2*v, i, delta);
        update(2*v+1, i, delta);
        merge(v);
    }

public:
    SegmentTree(vector<int> &a) {
        build(a, 1, 0, a.size()-1);
    }
    int query(int l, int r) {
        return query(1, l, r);
    }
    void update(int i, int delta) {
        update(1, i, delta);
    }
};
