#include <bitset>  // compact STL for Sieve, better than vector<bool>!
#define int int64_t

int sieveSize;
bitset<10000010> bs;
vector<int> primes;

void sieve(int upperbound) {     // create list of primes in [0..upperbound]
    sieveSize = upperbound + 1;  // add 1 to include upperbound
    bs.set();                    // set all bits to 1
    bs[0] = bs[1] = 0;           // except index 0 and 1
    for (int i = 2; i <= sieveSize; ++i)
        if (bs[i]) {
            // cross out multiples of i starting from i * i!
            for (int j = i * i; j <= sieveSize; j += i) bs[j] = 0;
            primes.push_back(i);  // add this prime to the list of primes
        }
}  // call this method in main method

bool isPrime(int N) {  // a good enough deterministic prime tester
    if (N <= sieveSize) return bs[N];  // O(1) for small primes
    for (int i = 0; i < (int)primes.size(); ++i)
        if (N % primes[i] == 0) return false;
    return true;  // it takes longer time if N is a large prime!
}  // note: only work for N <= (last prime in vi "primes")^2

vector<int> factor;

// this function generate minimum prime divisor for each number from 1 to n
void generateMinFactor(int n) {
    if (factor.size()) return;
    for (int i = 0; i < n; ++i) factor.push_back(i);

    for (int i = 2; i < n; ++i) {
        for (int j = i; j < n; j += i) {
            if (factor[j] != j) continue;
            factor[j] = i;
        }
    }
}

int gcd(int a, int b) { return b == 0 ? a : gcd(b, a % b); }
int lcm(int a, int b) { return a * (b / gcd(a, b)); }