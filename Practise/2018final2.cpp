#include <bits/stdc++.h>
using namespace std;

#define TESTMOD true;

/* global variables */
int T, N, C;

bool com (int& a, int& b) {
    if (a%10 == 0 && b%10 ==0) return a < b;
    if (a%10 == 0) return true;
    if (b%10 == 0) return false;
    return a < b;
}

/* main function */
int main () {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    T = 1;

    while (T--) {
        cin >> N >> C;
        vector<int> cakes(N);
        for (int i = 0; i < N; ++i) cin >> cakes[i];

        std::sort(cakes.begin(), cakes.end(), com);
        // for (int i = 0; i < N; ++i) cout << cakes[i] << " ";
        // cout << endl;
        int temp, ans = 0;
        for (int i = 0; i < N; ++i) {
            if (cakes[i] == 10) {
                ans++;
                continue;
            }

            if (cakes[i] < 10) continue;
            
            if (cakes[i]%10 == 0) {
                temp = cakes[i]/10;
                if (C >= temp - 1) {
                    ans += temp;
                    C -= temp - 1;
                }
                else {
                    ans += C;
                    C = 0;
                }
            }
            else {
                temp = cakes[i]/10;
                if (C >= temp) {
                    ans += temp;
                    C -= temp;
                }
                else {
                    ans += C;
                    C = 0;
                }
            }

            if (C == 0) break;
        }

        cout << ans << endl;
    }

    return 0;
}