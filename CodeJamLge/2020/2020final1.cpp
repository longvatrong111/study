#include <bits/stdc++.h>
using namespace std;

#define int int64_t
#define endl '\n'
#define mod 1000000007

/* global variables */
int T;

/* main function */
int32_t main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    
    cin >> T;

    while (T--) {
        int n; cin >> n;
        int x, y;
        cin >> x >> y;

        int cur;
        int vmax = 0;
        for (int i = 0; i < n - 1; ++i) {
            cin >> cur;
            vmax = max(cur, vmax);
        }

        int v; cin >> v;

        if (v > vmax) {
            cout << 0 << endl;
            continue;
        }

        int val = x*(vmax - v) + (v*vmax);
        int z = val/vmax + 1;

        if (z > y) {
            cout << -1 << endl;
        }
        else {
            cout << z << endl;
        }
    }

    return 0;
}