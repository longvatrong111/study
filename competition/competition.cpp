#include <bits/stdc++.h>
using namespace std;

#define int int64_t
#define endl '\n'
#define mod 1000000007

/* global variables */
int T;

int maximumLength(vector<int>& nums, int k) {
    int n = nums.size();
    int ans = 1;

    unordered_map<int, vector<int>> mp;
    mp[nums[0]] = vector<int>(k + 1, 0);
    mp[nums[0]][0] = 1;

    for (int i = 1; i < n; ++i) {
        vector<int> temp =
            mp.count(nums[i]) ? mp[nums[i]] : vector<int>(k + 1, 0);
        for (auto& p : mp) {
            if (nums[i] == p.first) {
                for (int count = 0; count <= k; ++count) {
                    temp[count] = std::max(temp[count], 1 + p.second[count]);
                }
            } else {
                for (int count = 0; count < k; ++count) {
                    temp[count + 1] =
                        std::max(temp[count + 1], 1 + p.second[count]);
                }
            }
        }

        mp[nums[i]] = temp;
        mp[nums[i]][0] = std::max(mp[nums[i]][0], 1ll);
    }

    for (auto& p : mp) {
        for (int i = 0; i <= k; ++i) ans = std::max(ans, p.second[i]);
    }
    return ans;
}

/* main function */
int32_t main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> T;

    while (T--) {
        vector<int> arr = {1, 2, 1, 1, 3};
        int k = 2;
        cout << maximumLength(arr, k) << endl;
    }

    return 0;
}