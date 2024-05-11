const int K = 10; //2^10 >= 1000
const int MAXN = 1000;

int log2_floor(int i) {
    return i ? __builtin_clzll(1) - __builtin_clzll(i) : -1;
}

struct SparseTable {
    int st[K+1][MAXN];
    
    SparseTable(int (&array)[MAXN]) {
        std::copy(array, array + MAXN, st[0]);

        for (int i = 1; i <= K; i++)
            for (int j = 0; j + (1 << i) <= MAXN; j++)
                st[i][j] = min(st[i - 1][j], st[i - 1][j + (1 << (i - 1))]);
    }
    
    int query(int l, int r) {
        int i = log2_floor(r - l + 1);
        return min(st[i][l], st[i][r - (1 << i) + 1]);
    }
};
