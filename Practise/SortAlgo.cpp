#include <bitset>    // compact STL for Sieve, better than vector<bool>!
long sieveSize;      // ll is defined as: typedef long long ll;
bitset<10000010> bs; // 10^7 should be enough for most cases
vector<int> primes;  // compact list of primes in form of vector<int>

void sieve(long upperbound)
{                               // create list of primes in [0..upperbound]
    sieveSize = upperbound + 1; // add 1 to include upperbound
    bs.set();                   // set all bits to 1
    bs[0] = bs[1] = 0;          // except index 0 and 1
    for (long i = 2; i <= sieveSize; ++i)
        if (bs[i])
        {
            // cross out multiples of i starting from i * i!
            for (long j = i * i; j <= sieveSize; j += i)
                bs[j] = 0;
            primes.push_back((int)i); // add this prime to the list of primes
        }
} // call this method in main method

bool isPrime(long N)
{ // a good enough deterministic prime tester
    if (N <= sieveSize)
        return bs[N]; // O(1) for small primes
    for (int i = 0; i < (int)primes.size(); ++i)
        if (N % primes[i] == 0)
            return false;
    return true; // it takes longer time if N is a large prime!
} // note: only work for N <= (last prime in vi "primes")^2

int gcd(int a, int b) { return b == 0 ? a : gcd(b, a % b); }
int lcm(int a, int b) { return a * (b / gcd(a, b)); }