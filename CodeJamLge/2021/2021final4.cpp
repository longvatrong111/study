#include <bits/stdc++.h>
using namespace std;

#define TESTMOD true;

/* global variables */
int T;
vector<int> primes;

// vector<int> values;

void SieveOfEratosthenes(int n) {
    // Create a boolean array "prime[0..n]" and initialize
    // all entries it as true. A value in prime[i] will
    // finally be false if i is Not a prime, else true.
    bool prime[n + 1];
    memset(prime, true, sizeof(prime));
 
    for (int p = 2; p * p <= n; p++) {
        // If prime[p] is not changed, then it is a prime
        if (prime[p] == true) {
            // Update all multiples of p greater than or
            // equal to the square of it numbers which are
            // multiple of p and are less than p^2 are
            // already been marked.
            for (int i = p * p; i <= n; i += p) prime[i] = false;
        }
    }
 
    // Print all prime numbers
    for (int p = 2; p <= n; p++) if (prime[p]) primes.push_back(p);

    // // get values
    // values = vector<int>(6e6 + 5);
    // values[1] = 1;
    // values[2] = 1;
    // values[3] = 1;

    // for (int i = 1; i < primes.size() - 1; i++) {
    //     values[primes[i]] = min(primes[i] - primes[i - 1], primes[i + 1] - primes[i]);
    //     for (int mid = primes[i] + 1; mid < primes[i + 1]; mid++) {
    //         values[mid] = min(primes[i + 1] - mid, mid - primes[i]);
    //     }
    // }
}

int getScore(int n) {
    return values[n];
    if (n == 0) return 2;
    if (n == 1) return 1;
    if (n == 2) return 1;
    auto it = std::lower_bound(primes.begin(), primes.end(), n);
    if (*it == n) return std::min(n - *prev(it), *next(it) - n);
    return std::min(n - *prev(it), *it - n);
}

void calScore(vector<int>& nums, vector<int>& scores, int bit, int sum) {
    if (scores[bit] != -1) return;

    scores[bit] = getScore(sum);
    
    for (int i = 0; i < nums.size(); ++i) {
        if (!(bit & (1 << i))) {
            calScore(nums, scores, (bit | (1 << i)), sum + nums[i]);
        }
    }
}

int findDp(vector<int>& scores, vector<vector<int>>& dp, int m, int bit) {
    if (dp[m-1][bit] != -1) return dp[m-1][bit];

    int ans = INT_MAX;
    for (int i = (bit - 1) & bit; i > 0; i = (i - 1) & bit) {
        ans = std::min(ans, std::max(findDp(scores, dp, m - 1, i), scores[bit^i]));
    }

    return dp[m-1][bit] = ans;
}

int main () {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    SieveOfEratosthenes(5000000+100000);

    cin >> T;
    while (T--) {
        int n; cin >> n;
        int m; cin >> m;
        vector<int> nums(n);
        for (int i = 0; i < n; ++i) cin >> nums[i];

        vector<int> scores(1 << n, -1);
        int bit = 0;
        int sum = 0;
        calScore(nums, scores, bit, sum);
        
        vector<vector<int>> dp(m, vector<int>(1 << n, -1));
        for (int i = 0; i < (1 << n); ++i) dp[0][i] = scores[i];
        bit = (1 << n) - 1;
        cout << findDp(scores, dp, m, bit) << endl;
    }

    return 0;
}