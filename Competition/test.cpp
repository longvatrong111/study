#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef pair<int, int> pii;
typedef vector<int> vi;
typedef vector<ll> vl;
typedef vector<bool> vb;

const int INF = 1e9;

struct edge
{
    int u, v, w;
    edge(int u, int v, int w) : u(u), v(v), w(w) {}
};

void updateDistances(vector<edge> &edges, vector<vi> &adj, vi &d, int u, int v, int w0)
{
    // check if edge update reduces distance between u and v
    if (w0 >= d[u] + d[v])
    {
        return;
    }

    int n = adj.size();
    vector<vb> vis(n, vb(n, false)); // visited matrix
    vector<set<int>> S(n);           // affected sources
    vector<vi> P(n);                 // parents

    d[u] = w0;

    queue<int> q;
    for (int i = 0; i < n; i++)
    {
        P[i].resize(n, -1);
    }

    // initialize queue and sets
    q.push(v);
    vis[v][v] = true;
    S[v].insert(v);
    P[v][v] = v;

    while (!q.empty())
    {
        int y = q.front();
        q.pop();

        // update distances for source nodes
        for (int x : S[P[y][u]])
        {
            if (d[x] > d[u] + w0 + d[v])
            {
                d[x] = d[u] + w0 + d[v];
            }
            if (y != v)
            {
                S[y].insert(x);
            }
        }

        // enqueue all neighbors that get closer to u
        for (int w : adj[y])
        {
            if (!vis[u][w] && d[u] + w0 + d[w] < d[u][w] && d[v][w] == d[v][y] + w)
            {
                q.push(w);
                vis[u][w] = true;
                P[w] = y;
            }
        }
    }
}

int main()
{
    int n, m;
    cin >> n >> m;

    vector<edge> edges;
    vector<vi> adj(n);
    vi d(n, INF);

    // read graph
    for (int i = 0; i < m; i++)
    {
        int u, v, w;
        cin >> u >> v >> w;
        edges.emplace_back(u, v, w);
        adj[u].push_back(v);
    }

    // read edge update
    int u, v, w0;
    cin >> u >> v >> w0;

    // update distances
    updateDistances(edges, adj, d, u, v, w0);

    // print updated distances
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            if (d[i][j] == INF)
            {
                cout << "INF ";
            }
            else
            {
                cout << d[i][j] << " ";
            }
        }
        cout << endl;
    }

    return 0;
}
