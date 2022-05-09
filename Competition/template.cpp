#include <bits/stdc++.h>
using namespace std;

#define TESTMOD true;

/* global variables */
int T;

/* main function */
int main () {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> T;

    while (T--) {
        int n, m;
        cin >> n >> m;
        vector<int> v(n);
        vector<int> x(m);
        vector<int> y(m);
        vector<int> z(m);
        for (int i = 0; i < n; ++i) cin >> v[i];
        for (int i = 0; i < m; ++i) cin >> x[i];
        for (int i = 0; i < m; ++i) cin >> y[i];
        for (int i = 0; i < m; ++i) cin >> z[i];
        
        for (int i = 0; i < m; ++i) {
            v[x[i]] -= z[i];
            v[y[i]] += z[i]; 
        }

        long ans = 0;
        for (int i = 0; i < n; ++i) {
            if (v[i] > 0) ans += v[i];
        }
        cout << ans << endl;
    }

    return 0;
}