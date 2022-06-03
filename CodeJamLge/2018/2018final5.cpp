#include <bits/stdc++.h>
using namespace std;

#define TESTMOD true;

/* global variables */
int N;

/* main function */
int main () {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> N;
    vector<int> nums(N);
    for (int i = 0; i < N; ++i) cin >> nums[i];

    std::sort(nums.begin(), nums.end());
    int index = -1;
    for (int i = 0; i < N; ++i) {
        if (nums[i] >= N-i) {
            index = i;
            break;
        }
    }

    if (index == -1) {
        cout << 0 << endl;
    }
    else {
        int ans = 0;
        for (int i = index; i < N; ++i) {
            ans += nums[i] - (i - index);
        }

        cout << ans << endl;
    }

    return 0;
}