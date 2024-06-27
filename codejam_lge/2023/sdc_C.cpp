#include <bits/stdc++.h>
using namespace std;

#define int int64_t
#define endl '\n'
#define mod 1000000007

/* global variables */
int T;

class MedianFinder {
   public:
    multiset<int> S;
    std::set<int>::iterator it;
    double sumLeft = 0;
    double sumRight = 0;

    MedianFinder() { it = S.end(); }

    void addNum(int num) {
        int n = S.size();
        S.insert(num);

        if (it == S.end()) {
            it = S.begin();
            return;
        }

        int val = *it;
        if (n % 2) {
            if (num >= val) {
                sumLeft += val;
                sumRight += num;
            } else {
                it = prev(it);
                sumLeft += num;
                sumRight += val;
            }
        } else {
            if (num >= val) {
                it = next(it);
                sumRight += num;
                sumRight -= *it;
            } else {
                sumLeft += num;
                sumLeft -= *it;
            }
        }
    }

    double findMedian() {
        if (S.size() == 0) return 0;

        if (S.size() % 2) {
            return *it;
        } else {
            return (double(*it) + *next(it)) / 2;
        }
    }
};

/**
 * Your MedianFinder object will be instantiated and called as such:
 * MedianFinder* obj = new MedianFinder();
 * obj->addNum(num);
 * double param_2 = obj->findMedian();
 */

/* main function */
int32_t main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    // cin >> T;
    T = 1;

    while (T--) {
        int n;
        cin >> n;
        int k;
        cin >> k;
        vector<vector<int>> arr(n, vector<int>(2));
        for (int i = 0; i < n; ++i) cin >> arr[i][0] >> arr[i][1];
        std::sort(arr.begin(), arr.end());
        vector<int> nums(n);
        for (int i = 0; i < n; ++i) nums[i] = arr[i][1];

        vector<vector<double>> score(n, vector<double>(n, 0));
        for (int i = 0; i < n; ++i) {
            MedianFinder mf;
            for (int j = i; j < n; ++j) {
                mf.addNum(nums[j]);
                double med = mf.findMedian();
                double sumLeft = mf.sumLeft;
                double sumRight = mf.sumRight;
                int count = mf.S.size();
                score[i][j] = (med * (count / 2) - sumLeft) +
                              (sumRight - med * (count / 2));
            }
        }

        // for (int i = 0; i < n; ++i) {
        //     for (int j = 0; j < n; ++j) {
        //         cout << score[i][j] << " ";
        //     }
        //     cout << endl;
        // }
        // cout << endl;

        vector<vector<double>> dp(k + 1, vector<double>(n, LONG_MAX));
        for (int i = 0; i < n; ++i) dp[1][i] = score[0][i];

        for (int count = 2; count <= k; ++count) {
            for (int i = count - 1; i < n; ++i) {
                for (int j = count - 2; j < i; ++j) {
                    if (count != k) {
                        dp[count][i] = std::min(
                            dp[count][i], dp[count - 1][j] + score[j + 1][i]);
                    } else {
                        dp[count][i] =
                            std::min(dp[count][i],
                                     dp[count - 1][j] + score[j + 1][n - 1]);
                    }
                }
            }
        }

        // double ans = LONG_MAX;
        // for (int i = 0; i < n; ++i) {
        //     ans = std::min(ans, dp[k][i]);
        // }
        cout << dp[k][n - 1] << endl;
    }

    return 0;
}