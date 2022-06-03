int mod = 1e9+7;
int N = 5000;
long fact[N];

void generateFact() {
    fact[0] = 1;
    for (int i = 1; i < N; ++i) fact[i] = (fact[i - 1] * i) % mod;
}

long power(long a, long b) {
    long result = 1;
    while (b > 0) {
        if (b % 2) result = (result * a) % mod;
        a = (a * a) % mod;
        b /= 2;
    }
    return result;
}
long nCr(int n, int r) {
    long num = fact[n];
    long den = (fact[r] * fact[n - r]) % mod;
    long ans = (num * power(den, mod - 2)) % mod;
    return ans;
}