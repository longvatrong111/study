#include <cstring>
#include <string.h>
#include <map>
#include <deque>
#include <queue>
#include <stack>
#include <sstream>
#include <iostream>
#include <iomanip>
#include <cstdio>
#include <cmath>
#include <cstdlib>
#include <ctime>
#include <algorithm>
#include <vector>
#include <set>
#include <complex>
#include <list>
#define N 1000
using namespace std;

void traverse(int n, int u, bool visited[], bool **graph)
{
    visited[u] = true; //mark v as visited
    for (int v = 0; v < n; v++)
    {
        if (graph[u][v])
        {
            if (!visited[v])
                traverse(n, v, visited, graph);
        }
    }
}

bool isConnected(int n, bool **gr)
{
    bool *vis = new bool[n];
    //for all vertex u as start point, check whether all ns are visible or not
    for (int u; u < n; u++)
    {
        for (int i = 0; i < n; i++)
            vis[i] = false; //initialize as no n is visited
        traverse(n, u, vis, gr);
        for (int i = 0; i < n; i++)
        {
            if (!vis[i]) //if there is a n, not visited by traversal, graph is not connected
                return false;
        }
    }
    return true;
}

int main()
{
    // freopen("input.txt", "r", stdin);
    // freopen("output.txt", "w", stdout);
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int T;
    cin >> T;
    while (T--)
    {
        int n;
        cin >> n;
        long s, a, b;
        cin >> s >> a >> b;

        bool **gr = (bool **)malloc(n * sizeof(bool *));
        for (int i = 0; i < n; ++i)
        {
            *(gr + i) = (bool *)malloc(n * sizeof(bool));
            for (int j = 0; j < n; ++j)
                gr[i][j] = false;
        }

        long e = 1123214129, x = 876867, y = 43543534;

        if (s % (n * n) == 0 && b % (n * n) == 0)
        {
            cout << 0 << endl;
            continue;
        }

        if (a == 1 && b%(n*n) == 0)
        {
            cout << 0 << endl;
            continue;
        }

        int m = 1;
        while (1)
        {
            if (m == 1)
            {
                e = s % (n * n);
                x = e / n;
                y = e % n;
            }
            else
            {
                e = (e * a + b) % (n * n);
                x = e / n;
                y = e % n;
            }

            //cout << "day m: " << m << " x: " << x << " y: " << y << endl;

            if (x != y)
            {
                gr[x][y] = true;
                gr[y][x] = true;
            }

            if (isConnected(n, gr))
            {
                cout << m << endl;
                break;
            }

            m++;
            if (m == 900)
            {
                cout << 0 << endl;
                break;
            }
        }
    }
    return 0;
}