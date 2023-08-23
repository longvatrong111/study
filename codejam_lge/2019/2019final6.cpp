#include <bits/stdc++.h>
using namespace std;

#define TESTMOD true;

/* global variables */
int T;
const int verylarge = 99999999;

int cal(int& n1, int& n2) {
    if (n1 == 1) return n2;
    if (n1 == n2) return verylarge;
    if (n2%n1 == 0) return verylarge;

    int d = n2/n1;
    n2 %= n1;
    return d + cal(n2, n1);
}

void calString(int& n1, int& n2, string& ans, bool isRed) {
    if (n1 == 1) {
        if (isRed) for (int i = 0; i < n2; ++i) ans += 'R';
        else for (int i = 0; i < n2; ++i) ans += 'B';
        return;
    }

    int d = n2/n1;
    if (isRed) for (int i = 0; i < d; ++i) ans += 'R';
    else for (int i = 0; i < d; ++i) ans += 'B';
    n2 %= n1;
    calString(n2, n1, ans, !isRed);
}

int main () {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> T;
    while (T--) {
        int x; cin >> x;
        int n1, n2;
        int minval = INT_MAX;
        string ans;
        int idx = 1;
        
        for (int i = 1; i <= x/2; ++i) {
            n1 = i;
            n2 = x - i;
            int temp = cal(n1, n2);
            if (temp < minval) {
                minval = temp;
                idx = i;
            }
        }
        
        n1 = idx;
        n2 = x - idx;
        calString(n1, n2, ans, true);

        cout << ans << endl;
    }

    return 0;
}