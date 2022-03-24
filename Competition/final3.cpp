#include <bits/stdc++.h>
using namespace std;

#define TESTMOD true;

/* global variables */
int T, N;
long S;

bool com (pair<long,long>& a, pair<long,long>& b) {
    if (a.second == b.second) return a.first < b.first;
    return a.second > b.second;
}

// bool cmp (const pair<long, long> &a, const pair<long, long> &b) {
//     if (a.first == b.first) return a.second > b.second;
//     return a.first < b.first;
// };

/* main function */
int main () {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> T;

    while (T--) {
        cin >> N;
        cin >> S;
        vector<pair<long,long>> vt(N, pair<long,long>()); // pair: <time, pen>
        // int temp;
        for (int i = 0; i < N; ++i) cin >> vt[i].first;
        for (int i = 0; i < N; ++i) cin >> vt[i].second;

        std::sort(vt.begin(), vt.end(), com);
        set<pair<long,long>> dq;
        long ans = 0;
        long temp = 0;

        for (int i = 0; i < N; ++i) {
            if (S < vt[i].first) {
                dq.insert(vt[i]);
                if (dq.size() >= 2 && dq.rbegin()->first - dq.begin()->first < dq.size()-1) {
                    S = dq.rbegin()->first+1;
                    dq.clear();
                }
                continue;
            }

            while (dq.size() && S >= dq.begin()->first) {
                // ans += (S - dq.begin()->first)*dq.begin()->second;
                S = max(dq.begin()->first+1, S+1);
                dq.erase(dq.begin());
            }

            while (dq.size() && max(vt[i].first + 1, S + 1) > dq.begin()->first) {
                // temp = S - dq.begin()->first;
                // if (temp < 0) temp = 0;
                // ans += temp*dq.begin()->second;
                S = max(dq.begin()->first+1, S+1);
                dq.erase(dq.begin());
            }

            ans += (S - vt[i].first)*vt[i].second;
            S = max(vt[i].first + 1, S + 1);
        }

        cout << ans << endl;
    }

    return 0;
}