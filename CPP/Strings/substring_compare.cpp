// DISCLAIMER: CODE NEVER TESTED

class SubstringCompare {
private:
    const long long p = 31;
    const long long m = 1e9 + 9;
    string s;
    vector<long long> p_pows, prefixHashes;

    inline long long id(char c) {
        return c - 'a' + 1;
    }

    long long hash(int l, int r) { // returns the hash multiplied by p_pows[l]
        int lh = 0;
        if (l > 0) lh = prefixHashes[l-1];
        int rh = prefixHashes[r];
        int h = rh - lh;
        if (h < 0) h += m;
        return h;
    }

public:
    // O(n) build
    SubstringCompare(string &s) : s(s) {
        int n = s.length();
        p_pows.assign(n, 1);
        for (int i = 1; i < n; i++)
            p_pows[i] = (p_pows[i-1] * p) % m;

        prefixHashes.resize(n);
        prefixHashes[0] = id(s[0]);
        for (int i = 1; i < n; i++)
            prefixHashes[i] = (prefixHashes[i-1] + id(s[i]) * p_pows[i]) % m;
    }

    // O(1)
    bool query(int l1, int r1, int l2, int r2) {
        if (l1 > l2) {
            swap(l1, l2);
            swap(r1, r2);
        }
        long long h1 = hash(l1, r1); // this one is the actual hash multiplied by p^l1
        long long h2 = hash(l2, r2); // and this one by p^l2
        h1 = (h1 * p_pows[l2-l1]) % m;
        return h1 == h2;
    }
};
