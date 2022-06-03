#define int int64_t

const int mod = 1e9+7;
int N = 5000;
int fact[N];

void generateFact() {
    fact[0] = 1;
    for (int i = 1; i < N; ++i) fact[i] = (fact[i - 1] * i) % mod;
}

// int power(int a, int b) {
//     int result = 1;
//     while (b > 0) {
//         if (b % 2) result = (result * a) % mod;
//         a = (a * a) % mod;
//         b /= 2;
//     }
//     return result;
// }

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