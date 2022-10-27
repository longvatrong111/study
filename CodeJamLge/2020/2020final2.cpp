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
    
    cin >> T;

    while (T--) {
        int N, seed, A, B;
        cin >> N >> seed >> A >> B;

        int E, X, Y;
        E = seed % (N * N);
        int M = 0;
        UnionFind UN(N);
        unordered_set<int> S;
        S.insert(E);
        bool res = true;

        while (UN.getSize(0) != N) {
            M++;
            X = E/N;
            Y = E%N;
            UN.unionSet(X, Y);
            if (UN.getSize(0) == N) break;

            E = (E * A + B) % (N * N);
            if (S.count(E)) {
                res = false;
                break;
            }

            S.insert(E);
        }
        
        if (res) cout << M << endl;
        else cout << 0 << endl;
    }

    return 0;
}