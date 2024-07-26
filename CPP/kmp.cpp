vector<int> buildLps(string &s) {
    int n = s.length();
    vector<int> lps(n);
    for (int i = 1; i < n; i++) {
        int j = lps[i-1];
        while (j > 0 && s[i] != s[j])
            j = lps[j-1];
        if (s[i] == s[j])
            j++;
        lps[i] = j;
    }
    return lps;
}

int main() {
    // every time a pattern matches, the lcs value of that position will be 'n' (the pat size)
    // example:
    // aaaa#zzaaaa
    // lps[i=10] = 4 (pat size)
    // if you subtract (pat size - 1), you will get the index the pattern starts on the merged string
    // but since you want the index on the original string, you still gotta subtract (pat + 1)
    // (because of the pattern and '#' from the start)
    // simplifying, the index is (i - 2*n)

    string text, pat;
    string patThenText = pat + '#' + text; // '#' should not appear on any of the strings
    vector<int> lps = buildLps(patThenText);
    int n = pat.length();
    int m = text.length();
    vector<int> indices;
    // n+1 points to the char next to the '#'
    // n + m + 1 is the size of the merged string
    for (int i = n+1; i < n+m+1; i++)
        if (lps[i] == n)
            indices.push_back(i - 2*n);
}
