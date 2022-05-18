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
        int n, l, mb, e;
        cin >> n >> l >> mb;
        vector<int> arr;
        int max = -1;
        int per = -1;
        for (int i = 0; i < n - 1; ++i)
        {
            cin >> e;
            arr.push_back(e);
            if (arr[i] > max)
                max = arr[i];
        }
        cin >> arr[n - 1];
        //cout << "arr[n-1]: " << arr[n-1] << endl;

        if (arr[n - 1] > max)
        {
            cout << 0 << endl;
            continue;
        }
        
        if (mb <= max)
        {
            cout << -1 << endl;
            continue;
        }

        if (max >= l)
        {
            if (mb <= max)
            {
                cout << -1 << endl;
                continue;
            }
            else
            {
                cout << max + 1 << endl;
                continue;
            }
        }
        
        //if (mb < arr[n-1]) mb = arr[n-1];

        int z = (l * (max - arr[n - 1]) + max*arr[n-1]) / max;
        //cout << "z: " << z << endl;

        if (z >= mb)
            cout << -1 << endl;
        else
            cout << z + 1 << endl;

        // if (l / max <= (l - mb) / arr[n - 1] + 1)
        //     cout << -1 << endl;
        // else
        //     cout << (int)z + 1 << endl;
    }
    return 0;
}