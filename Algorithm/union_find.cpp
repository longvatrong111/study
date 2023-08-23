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