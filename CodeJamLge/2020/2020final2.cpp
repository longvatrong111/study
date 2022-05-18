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

using namespace std;

struct p
{
    int h;
    int d;
};

bool com(p a, p b)
{
    return a.d < b.d;
}

int maxx(int a, int b)
{
    return a > b ? a : b;
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
        struct p hd[n];
        int rd[n];
        int max1[n];
        int maxp[n];

        int smallestmax = 2147483647;

        for (int i = 0; i < n; ++i)
        {
            cin >> hd[i].h;
        }
        for (int i = 0; i < n; ++i)
        {
            cin >> hd[i].d;
        }

        std::sort(hd, hd + n, com);

        for (int i = 0; i < n; ++i)
        {
            if (i == 0)
                rd[i] = hd[i].h;
            else
                rd[i] = rd[i - 1] + hd[i].h;
            max1[i] = rd[i] - hd[i].d + 1;
            //if (max1[i] < 0)
            //   max1[i] = 0;
        }

        int curmax1[n];
        int cur_max1 = 0;
        for (int i = n-1; i >= 0; --i) {
            if(max1[i] > cur_max1) cur_max1 = max1[i];
            curmax1[i] = cur_max1;
        }

        // cout << "h[i] ";
        // for (int i = 0; i < n; ++i) {
        //     cout << hd[i].h << " ";
        // }
        // cout << endl;

        // cout << "d[i] ";
        // for (int i = 0; i < n; ++i) {
        //     cout << hd[i].d << " ";
        // }
        // cout << endl;

        // cout << "rd[i] ";
        // for (int i = 0; i < n; ++i) {
        //     cout << rd[i] << " ";
        // }
        // cout << endl;

        // cout << "max1[i] ";
        // for (int i = 0; i < n; ++i) {
        //     cout << max1[i] << " ";
        // }
        // cout << endl;

        // cout << "maxp[i] ";
        // for (int i = 0; i < n; ++i) {
        //     cout << maxp[i] << " ";
        // }
        // cout << endl;

        //cout << "maxp[i] ";
        int cur_max = 0;
        for (int i = 0; i < n; ++i)
        {
            if (i != 0)
            {
                if (cur_max < max1[i - 1] - 1)
                    cur_max = max1[i - 1] - 1;
            }

            //int max_in_loop = 0;
            //maxp[i] = maxx(cur_max, *std::max_element(max1 + i, max1 + n) - hd[i].h);
            maxp[i] = maxx(cur_max, curmax1[i] - hd[i].h);
            //cout << maxp[i] << " ";
            if (smallestmax > maxp[i])
                smallestmax = maxp[i];
            if (smallestmax < 0)
                smallestmax = 0;
        }
        //cout << endl;

        if (smallestmax != 2147483647)
            cout << smallestmax << endl;
        else
            cout << 0 << endl;
    }
    return 0;
}