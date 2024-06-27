#include <bits/stdc++.h>
using namespace std;

#define int int64_t
#define endl '\n'
#define mod 1000000007

/* global variables */
int T;

class UnionFind {
   private:
    vector<int> parent, rank, unionSize;

   public:
    UnionFind(int N) {
        rank.assign(N, 0);
        parent.assign(N, 0);
        unionSize.assign(N, 0);
        for (int i = 0; i < N; i++) {
            parent[i] = i;
            unionSize[i] = 1;
        }
    }

    int findSet(int i) {
        return (parent[i] == i) ? i : (parent[i] = findSet(parent[i]));
    }

    bool isSameSet(int i, int j) { return findSet(i) == findSet(j); }

    void unionSet(int i, int j) {
        if (!isSameSet(i, j)) {  // if from different set
            int x = findSet(i), y = findSet(j);
            if (rank[x] > rank[y]) {
                parent[y] = x;  // rank keeps the tree short
                unionSize[x] += unionSize[y];
            } else {
                parent[x] = y;
                unionSize[y] += unionSize[x];
                if (rank[x] == rank[y]) rank[y]++;
            }
        }
    }

    int getSize(int i) { return unionSize[findSet(i)]; }
};

/* main function */
int32_t main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    // cin >> T;
    T = 1;

    while (T--) {
        int n, m;
        cin >> n >> m;
        vector<vector<int>> e(m, vector<int>(3));
        for (int i = 0; i < m; ++i) cin >> e[i][1] >> e[i][2] >> e[i][0];

        std::sort(e.begin(), e.end(), greater<long>());

        vector<int> state(n, 0);
        vector<vector<int>> adj(n, vector<int>());
        UnionFind un(n);

        for (int i = 0; i < m; ++i) {
            int w = e[i][0];
            while (i + 1 < m && e[i + 1][0] == w) {
                i++;
            }
        }
    }

    return 0;
}