#include <bits/stdc++.h>
using namespace std;

#define int int64_t
#define endl '\n'
#define mod 1000000007

/* global variables */
int T;

class UnionFind
{
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

    bool isSameSet(int i, int j) {
        return findSet(i) == findSet(j);
    }

    void unionSet(int i, int j) {
        if (!isSameSet(i, j)) { // if from different set
            int x = findSet(i), y = findSet(j);
            if (rank[x] > rank[y]) {
                parent[y] = x; // rank keeps the tree short
                unionSize[x] += unionSize[y];
            }
            else {
                parent[x] = y;
                unionSize[y] += unionSize[x];
                if (rank[x] == rank[y])
                    rank[y]++;
            }
        }
    }

    int getSize(int i) {
        return unionSize[findSet(i)];
    }
};

/* main function */
int32_t main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    
    T = 1;

    while (T--) {
        int N, M, K;
        cin >> N >> M >> K;

        vector<pair<int, int>> edges(M);
        vector<int> ans(K);
        int x, y;
        for (int i = 0; i < M; ++i) {
            cin >> x >> y;
            edges[i] = {x, y};
        }

        for (int i = 0; i < K; ++i) {
            UnionFind UN(N);
            int cost = 0;

            for (int j = i; j < M; ++j) {
                if (!UN.isSameSet(edges[j].first - 1, edges[j].second - 1)) {
                    cost += j + 1;
                    UN.unionSet(edges[j].first - 1, edges[j].second - 1);
                }
            }

            bool check = true;
            for (int i = 0; i < N - 1; ++i) {
                if (!UN.isSameSet(i, i + 1)) {
                    check = false;
                    break;
                }
            }

            ans[i] = check ? cost : 0;
        }

        for (int i = 0; i < K; ++i) {
            cout << ans[i] << " ";
        }
        cout << endl;
    }

    return 0;
}