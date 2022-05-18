#include <bits/stdc++.h>
using namespace std;

#define TESTMOD true;

/* global variables */
int T, N;

/* main function */
int main () {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    T = 1;

    while (T--) {
        cin >> N;
        vector<int> arr(N);
        for (int i = 0; i < N; ++i) cin >> arr[i];
        std::sort(arr.begin(), arr.end());
        vector<int> sticks;
        for (int  i = N-1; i >= 1; --i) {
            if (arr[i] == arr[i-1]) {
                sticks.push_back(arr[i]);
                --i;
            }
            else if (arr[i] == arr[i-1] + 1) {
                sticks.push_back(arr[i-1]);
                --i;
            }
        }

        int n = sticks.size();
        long ans = 0;
        for (int i = 0; i < n-1; i += 2) {
            ans += (long)sticks[i]*sticks[i+1];
        }
        cout << ans << endl;
    }

    return 0;
}