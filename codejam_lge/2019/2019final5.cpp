#include <bits/stdc++.h>
using namespace std;

#define TESTMOD true;

/* global variables */
int T;

void eulerCycle() {

}

int main () {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> T;
    while (T--) {
        int n; cin >> n;
        int m; cin >> m;

        vector<int> degree(n+1, 0);
        vector<vector<int>> edges(m, vector<int>(2));

        for (int i = 0; i < m; ++i) {
            cin >> edges[i][0];
            degree[edges[i][0]]++;
        }

        for (int i = 0; i < m; ++i) {
            cin >> edges[i][1];
            degree[edges[i][1]]++;
        }

        vector<vector<pair<int, int>>> adjection(n+1, vector<pair<int, int>>());
        for (int i = 0; i < m; ++i) {
            adjection[edges[i][0]].push_back({i+1, edges[i][1]});
            adjection[edges[i][1]].push_back({-i-1, edges[i][0]});
        }

        vector<int> numOdd;
        for (int i = 1; i <= n; ++i) if (degree[i]%2 == 1) numOdd.push_back(i); 

        if (numOdd.size() == 0) eulerCycle();
        else if (numOdd.size() == 2) eulerPath();
        else if (numOdd.size() == 4) semiEulerPath();
        else {
            cout << 0 << endl;
            cout << 0 << endl;
        }
    }

    return 0;
}