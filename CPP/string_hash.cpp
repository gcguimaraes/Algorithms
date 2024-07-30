long long compute_hash(string const& s) {
    const int p = 31; // should be roughly the size of input alphabet. For lower and upper, use 53.
    const int m = 1e9 + 9;
    long long hash_value = 0;
    long long p_pow = 1;
    for (char c : s) {
        hash_value = (hash_value + (c - 'a' + 1) * p_pow) % m;
        p_pow = (p_pow * p) % m;
    }
    return hash_value;
}
// precomputing the powers of p might give a performance boost
