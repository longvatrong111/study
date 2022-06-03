#include <bits/stdc++.h>
using namespace std;

#define TESTMOD true;

#define int int64_t

/* global variables */
const int mod = 1e9+7;

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

/* main function */
int32_t main () {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int R, C, K; cin >> R >> C >> K;
    unordered_map<int, vector<int>> M;

    int x, y;
    for (int i = 0; i < K; ++i) {
        cin >> x >> y;
        if (!M.count(x)) {
            M[x] = vector<int>();
            M[x].push_back(0);
        }
        M[x].push_back(y);
    }

    int count = 0;
    int way = 1;
    for (auto& p:M) {
        p.second.push_back(C + 1);
        std::sort(p.second.begin(), p.second.end());

        int n = p.second.size();
        int dif;
        for (int i = 1; i < n; ++i) {
            dif = p.second[i] - p.second[i-1] - 1;
            count += dif/2;
            if (dif > 1 && dif%2) way *= dif/2 + 1;
            way %= mod;
        }
    }

    count += (int)(R - M.size())*(C/2);
    if (C%2 && C > 1) {
        int val = C/2 + 1;
        
        way *= powerLogN(val, R - M.size());
        way %= mod;
    }

    cout << count << " " << way << endl;
    
    return 0;
}