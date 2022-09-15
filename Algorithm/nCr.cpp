#define int int64_t
#define mod 1000000007
#define N 5000

int fact[N];

void generateFact() {
    fact[0] = 1;
    for (int i = 1; i < N; ++i) fact[i] = (fact[i - 1] * i) % mod;
}

int powerLogN(int a, int n) {
    if (n == 0) return 1;
    if (n == 1) return a;
    if (n%2) {
        int sub = powerLogN(a, n/2);
        return (((sub*sub)%mod)*a)%mod;
    }

    int sub = powerLogN(a, n/2);
    return (sub*sub)%mod;
}

int nCr(int n, int r) {
    int num = fact[n];
    int den = (fact[r] * fact[n - r]) % mod;
    int ans = (num * powerLogN(den, mod - 2)) % mod;
    return ans;
}

int nAr(int n, int r) {
    int num = fact[n];
    int den = fact[n - r];
    int ans = (num * powerLogN(den, mod - 2)) % mod;
    return ans;
}

int gcd(int a, int b) { return b == 0 ? a : gcd(b, a % b); }
int lcm(int a, int b) { return a * (b / gcd(a, b)); }