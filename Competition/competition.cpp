#include <bits/stdc++.h>
using namespace std;

#define int int64_t
#define endl '\n'
#define mod 1000000007

/* global variables */
int T;

long long matrixSumQueries(int n, vector<vector<int>> &quer)
{
    long long ans = 0;
    set<int> row;
    set<int> col;
    int nRow = n, nCol = n;

    int q = quer.size();
    int type, idx;
    long long val;
    for (int i = q - 1; i >= 0; --i)
    {
        type = quer[i][0];
        idx = quer[i][1];
        val = quer[i][2];

        if (type == 0)
        {
            if (row.count(idx))
                continue;
            row.insert(idx);

            ans += val * nCol;

            nRow--;
        }
        else
        {
            if (col.count(idx))
                continue;
            col.insert(idx);

            ans += val * nRow;

            nCol--;
        }
    }

    return ans;
}

/* main function */
int32_t main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    // cin >> T;
    T = 1;

    while (T--)
    {
        int n, q;
        cin >> n >> q;
        vector<vector<int>> query;
        for (int i = 0; i < q; ++i)
        {
            int x, y, z;
            cin >> x >> y >> z;
            query.push_back({x, y, z});
        }

        cout << matrixSumQueries(n, query) << endl;
    }

    return 0;
}