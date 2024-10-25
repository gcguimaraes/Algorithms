class SuffixArray {
public:
    string T; // the input string
    vector<int> SA;         // Suffix Array
    SuffixArray(string& s) : T(s) {
        n = T.size();
        constructSA(); // O(n log n)
    }

private:
    vector<int> RA;// rank array
    int n;                           
    void countingSort(int k) {          
        int maxi = max(300ll, n);          
        vector<int> c(maxi, 0);                    
        for (int i = 0; i < n; ++i)
            ++c[i + k < n ? RA[i + k] : 0];
        for (int i = 0, sum = 0; i < maxi; ++i) {
            int t = c[i];
            c[i] = sum;
            sum += t;
        }
        vector<int> tempSA(n);
        for (int i = 0; i < n; ++i) // sort SA
            tempSA[c[SA[i] + k < n ? RA[SA[i] + k] : 0]++] = SA[i];
        swap(SA, tempSA); // update SA
    }
    void constructSA() { // can go up to 400K chars
        SA.resize(n);
        iota(SA.begin(), SA.end(), 0); // the initial SA
        RA.resize(n);
        for (int i = 0; i < n; ++i)
            RA[i] = T[i];                   // initial rankings
        for (int k = 1; k < n; k <<= 1) {   // repeat log_2 n times
            // this is actually radix sort
            countingSort(k); // sort by 2nd item
            countingSort(0); // stable-sort by 1st item
            vector<int> tempRA(n);
            int r = 0;
            tempRA[SA[0]] = r;          // re-ranking process
            for (int i = 1; i < n; ++i) // compare adj suffixes
                tempRA[SA[i]] = // same pair => same rank r; otherwise, increase r
                    ((RA[SA[i]] == RA[SA[i - 1]])
                    && (RA[SA[i] + k] == RA[SA[i - 1] + k]))
                    ? r : ++r;
            swap(RA, tempRA); // update RA
            if (RA[SA[n - 1]] == n - 1)
                break; // nice optimization
        }
    }
};
