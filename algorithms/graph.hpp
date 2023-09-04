/* Topological sort */

vector<int> ts;     // global vector to store the toposort in reverse order
void dfs2(int u) {  // different function name compared to the original dfs
    dfs_num[u] = VISITED;
    for (int j = 0; j < (int)AdjList[u].size(); j++) {
        pair<int, int> v = AdjList[u][j];
        if (dfs_num[v.first] == UNVISITED) dfs2(v.first);
    }
    ts.push_back(u);
}

int main() {
    ts.clear();
    memset(dfs_num, UNVISITED, sizeof dfs_num);

    for (int i = 0; i < V; i++)  // this part is the same as finding CCs
        if (dfs_num[i] == UNVISITED) dfs2(i);
    // alternative, call: reverse(ts.begin(), ts.end()); first
    for (int i = (int)ts.size() - 1; i >= 0; i--)  // read backwards
        printf(" %d", ts[i]);
    printf("\n");

    return 0;
}

/* Bipartite graph check */
// inside int main()
void check(int s) {
    queue<int> q;
    q.push(s);
    vector<int> color(V, INF);
    color[s] = 0;
    bool isBipartite = true;  // addition of one boolean flag, initially true
    while (!q.empty() & isBipartite) {  // similar to the original BFS routine
        int u = q.front();
        q.pop();
        for (int j = 0; j < (int)AdjList[u].size(); j++) {
            pair<int, int> v = AdjList[u][j];
            if (color[v.first] == INF) {  // but, instead of recording distance,
                color[v.first] =
                    1 - color[u];  // we just record two colors {0, 1}
                q.push(v.first);
            } else if (color[v.first] ==
                       color[u]) {  // u & v.first has same color
                isBipartite = false;
                break;
            }
        }
    }  // we have a coloring conflict
}
