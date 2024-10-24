// ax + by = gcd(a, b)
// returns [gcd, x, y]
tuple<int, int, int> extendedGcd(int a, int b) {
    if (b == 0) return make_tuple(a, 1, 0);
    auto[q, w, e] = extendedGcd(b, a%b);
    return make_tuple(q, e, w-e*(a/b));
}
