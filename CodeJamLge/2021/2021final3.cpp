#include <bits/stdc++.h>
using namespace std;

int T, N;
long S;

bool com(pair<long,long>& a, pair<long,long>& b) {
    if (a.first == b.first) return a.second > b.second;
    return a.first < b.first;
}

struct myCom {
    constexpr bool operator()(
        pair<long, long> const& a,
        pair<long, long> const& b)
        const noexcept
    {
        return a.second < b.second;
    }
};

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cin >> T;

    while (T--) {
        cin >> N;
        cin >> S;
        vector<pair<long,long>> V(N, pair<long,long>());

        for (int i = 0; i < N; ++i) cin >> V[i].first;
        for (int i = 0; i < N; ++i) cin >> V[i].second;

        std::sort(V.begin(), V.end(), com);
        // priority_queue<pi, vector<pi>, greater<pi> > pq;
        priority_queue<pair<long,long>, vector<pair<long,long>>, myCom> Q; // max heap by 2nd value of pair
        long ans = 0;
        for (int i = 0; i < N; ++i) {            
            while (!Q.empty() && S < V[i].first) {
                ans += (S - Q.top().first)*Q.top().second;
                S = max(S + 1, Q.top().first+1);
                Q.pop();
            }
            
            if (S >= V[i].first) {
                Q.push(V[i]);
                continue;
            }

            S = V[i].first + 1;
        }

        while (!Q.empty()) {
            ans += (S - Q.top().first)*Q.top().second;
            S = max(S + 1, Q.top().first+1);
            Q.pop(); 
        }

        cout << ans << endl;
    }

    return 0;
}