const ll MOD = 1e9 + 7;

struct Matrix2x2 {
    ll a11, a12, a21, a22;
    Matrix2x2 operator* (Matrix2x2 &o) {
        return {
            (a11*o.a11 + a12*o.a21) % MOD,
            (a11*o.a12 + a12*o.a22) % MOD,
            (a21*o.a11 + a22*o.a21) % MOD,
            (a21*o.a12 + a22*o.a22) % MOD
        };
    }
};

Matrix2x2 fastPow(Matrix2x2 &m, ll e) {
    if (e == 1) return m;
    Matrix2x2 squared = m*m;
    if (e % 2 == 0) return fastPow(squared, e/2);
    return fastPow(squared, e/2) * m;
}
