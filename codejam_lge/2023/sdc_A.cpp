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

    // cin >> T;
    T = 1;

    while (T--) {
        int n;
        cin >> n;
        int k;
        cin >> k;
        vector<int> arr(n);
        vector<int> pos;
        vector<int> neg;
        int x;
        for (int i = 0; i < n; ++i) {
            cin >> x;
            if (x > 0)
                pos.push_back(x);
            else if (x < 0)
                neg.push_back(abs(x));
        }
        int ans = 0;
        std::sort(pos.begin(), pos.end());
        std::sort(neg.begin(), neg.end());
        for (int i = pos.size() - 1; i >= 0; i -= k) {
            ans += pos[i] * 2;
        }
        // if (pos.size() % k && pos.size() > k)
        //     ans += pos[(pos.size() % k) - 1] * 2;
        for (int i = neg.size() - 1; i >= 0; i -= k) {
            ans += neg[i] * 2;
        }
        // if (neg.size() % k && neg.size() > k)
        //     ans += neg[(neg.size() % k) - 1] * 2;

        cout << ans << endl;
    }

    return 0;
}