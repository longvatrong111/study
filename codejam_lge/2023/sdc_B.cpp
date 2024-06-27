#include <bits/stdc++.h>
using namespace std;

#define int int64_t
#define endl '\n'
#define mod 1000000007

/* global variables */
int T;

/* main function */
int32_t main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    // cin >> T;
    T = 1;

    while (T--) {
        int n, m, k;
        cin >> n >> m >> k;

        vector<string> arr(n);
        for (int i = 0; i < n; ++i) cin >> arr[i];

        vector<vector<int>> count1(n + 1, vector<int>(m + 1, 0));
        vector<vector<int>> count2(n + 1, vector<int>(m + 1, 0));
        for (int i = 1; i <= n; ++i) {
            for (int j = 1; j <= m; ++j) {
                if (arr[i - 1][j - 1] == '1') {
                    count1[i][j] = 1 + count1[i - 1][j] + count1[i][j - 1] -
                                   count1[i - 1][j - 1];
                    count2[i][j] = count2[i - 1][j] + count2[i][j - 1] -
                                   count2[i - 1][j - 1];
                } else if (arr[i - 1][j - 1] == '2') {
                    count1[i][j] = count1[i - 1][j] + count1[i][j - 1] -
                                   count1[i - 1][j - 1];
                    count2[i][j] = 1 + count2[i - 1][j] + count2[i][j - 1] -
                                   count2[i - 1][j - 1];
                } else {
                    count1[i][j] = count1[i - 1][j] + count1[i][j - 1] -
                                   count1[i - 1][j - 1];
                    count2[i][j] = count2[i - 1][j] + count2[i][j - 1] -
                                   count2[i - 1][j - 1];
                }
            }
        }

        vector<vector<int>> count_re1(n + 2, vector<int>(m + 2, 0));
        vector<vector<int>> count_re2(n + 2, vector<int>(m + 2, 0));
        for (int i = n; i; --i) {
            for (int j = m; j; --j) {
                if (arr[i - 1][j - 1] == '1') {
                    count_re1[i][j] = 1 + count_re1[i + 1][j] +
                                      count_re1[i][j + 1] -
                                      count_re1[i + 1][j + 1];
                    count_re2[i][j] = count_re2[i + 1][j] +
                                      count_re2[i][j + 1] -
                                      count_re2[i + 1][j + 1];
                } else if (arr[i - 1][j - 1] == '2') {
                    count_re1[i][j] = count_re1[i + 1][j] +
                                      count_re1[i][j + 1] -
                                      count_re1[i + 1][j + 1];
                    count_re2[i][j] = 1 + count_re2[i + 1][j] +
                                      count_re2[i][j + 1] -
                                      count_re2[i + 1][j + 1];
                } else {
                    count_re1[i][j] = count_re1[i + 1][j] +
                                      count_re1[i][j + 1] -
                                      count_re1[i + 1][j + 1];
                    count_re2[i][j] = count_re2[i + 1][j] +
                                      count_re2[i][j + 1] -
                                      count_re2[i + 1][j + 1];
                }
            }
        }

        vector<vector<int>> dis_x1(n + 1, vector<int>(m + 1, 0));
        vector<vector<int>> dis_x2(n + 1, vector<int>(m + 1, 0));
        vector<vector<int>> dis_y1(n + 1, vector<int>(m + 1, 0));
        vector<vector<int>> dis_y2(n + 1, vector<int>(m + 1, 0));
        for (int i = 1; i <= n; ++i) {
            for (int j = 1; j <= m; ++j) {
                dis_x1[i][j] = dis_x1[i - 1][j] + count1[i - 1][j];
                dis_x2[i][j] = dis_x2[i - 1][j] + count2[i - 1][j];
                dis_y1[i][j] = dis_y1[i][j - 1] + count1[i][j - 1];
                dis_y2[i][j] = dis_y2[i][j - 1] + count2[i][j - 1];
            }
        }

        vector<vector<int>> dis_x_re1(n + 2, vector<int>(m + 2, 0));
        vector<vector<int>> dis_x_re2(n + 2, vector<int>(m + 2, 0));
        vector<vector<int>> dis_y_re1(n + 2, vector<int>(m + 2, 0));
        vector<vector<int>> dis_y_re2(n + 2, vector<int>(m + 2, 0));
        for (int i = n; i; --i) {
            for (int j = m; j; --j) {
                dis_x_re1[i][j] = dis_x_re1[i + 1][j] + count_re1[i + 1][j];
                dis_x_re2[i][j] = dis_x_re2[i + 1][j] + count_re2[i + 1][j];
                dis_y_re1[i][j] = dis_y_re1[i][j + 1] + count_re1[i][j + 1];
                dis_y_re2[i][j] = dis_y_re2[i][j + 1] + count_re2[i][j + 1];
            }
        }

        // for (int i = 1; i <= n; ++i) {
        //     for (int j = 1; j <= m; ++j) {
        //         cout << count1[i][j] << " ";
        //     }
        //     cout << endl;
        // }
        // cout << endl;
        // for (int i = 1; i <= n; ++i) {
        //     for (int j = 1; j <= m; ++j) {
        //         cout << count2[i][j] << " ";
        //     }
        //     cout << endl;
        // }
        // cout << endl;

        // for (int i = 1; i <= n; ++i) {
        //     for (int j = 1; j <= m; ++j) {
        //         cout << count_re1[i][j] << " ";
        //     }
        //     cout << endl;
        // }
        // cout << endl;
        // for (int i = 1; i <= n; ++i) {
        //     for (int j = 1; j <= m; ++j) {
        //         cout << count_re2[i][j] << " ";
        //     }
        //     cout << endl;
        // }
        // cout << endl;

        // for (int i = 1; i <= n; ++i) {
        //     for (int j = 1; j <= m; ++j) {
        //         cout << dis_x1[i][j] << " ";
        //     }
        //     cout << endl;
        // }
        // cout << endl;
        // for (int i = 1; i <= n; ++i) {
        //     for (int j = 1; j <= m; ++j) {
        //         cout << dis_x_re1[i][j] << " ";
        //     }
        //     cout << endl;
        // }
        // cout << endl;

        // for (int i = 1; i <= n; ++i) {
        //     for (int j = 1; j <= m; ++j) {
        //         cout << dis_y1[i][j] << " ";
        //     }
        //     cout << endl;
        // }
        // cout << endl;
        // for (int i = 1; i <= n; ++i) {
        //     for (int j = 1; j <= m; ++j) {
        //         cout << dis_y_re1[i][j] << " ";
        //     }
        //     cout << endl;
        // }
        // cout << endl;

        // for (int i = 1; i <= n; ++i) {
        //     for (int j = 1; j <= m; ++j) {
        //         cout << dis_x2[i][j] << " ";
        //     }
        //     cout << endl;
        // }
        // cout << endl;
        // for (int i = 1; i <= n; ++i) {
        //     for (int j = 1; j <= m; ++j) {
        //         cout << dis_x_re2[i][j] << " ";
        //     }
        //     cout << endl;
        // }
        // cout << endl;

        // for (int i = 1; i <= n; ++i) {
        //     for (int j = 1; j <= m; ++j) {
        //         cout << dis_y2[i][j] << " ";
        //     }
        //     cout << endl;
        // }
        // cout << endl;
        // for (int i = 1; i <= n; ++i) {
        //     for (int j = 1; j <= m; ++j) {
        //         cout << dis_y_re2[i][j] << " ";
        //     }
        //     cout << endl;
        // }
        // cout << endl;

        int ans = LONG_MAX;
        for (int i = 1; i <= n; ++i) {
            for (int j = 1; j <= m; ++j) {
                if (i > k / 2 && i + k / 2 <= n && j > k / 2 &&
                    j + k / 2 <= m) {
                    int total_dis_x1 =
                        dis_x1[i][j + k / 2] - dis_x1[i][j - k / 2 - 1] -
                        (dis_x1[i - k / 2 - 1][j + k / 2] +
                         count1[i - k / 2 - 1][j + k / 2] * (k / 2 + 1)) +
                        (dis_x1[i - k / 2 - 1][j - k / 2 - 1] +
                         count1[i - k / 2 - 1][j - k / 2 - 1] * (k / 2 + 1));

                    int total_dis_x_re1 =
                        dis_x_re1[i][j - k / 2] - dis_x_re1[i][j + k / 2 + 1] -
                        (dis_x_re1[i + k / 2 + 1][j - k / 2] +
                         count_re1[i + k / 2 + 1][j - k / 2] * (k / 2 + 1)) +
                        (dis_x_re1[i + k / 2 + 1][j + k / 2 + 1] +
                         count_re1[i + k / 2 + 1][j + k / 2 + 1] * (k / 2 + 1));

                    int total_dis_y1 =
                        dis_y1[i + k / 2][j] - dis_y1[i - k / 2 - 1][j] -
                        (dis_y1[i + k / 2][j - k / 2 - 1] +
                         count1[i + k / 2][j - k / 2 - 1] * (k / 2 + 1)) +
                        (dis_y1[i - k / 2 - 1][j - k / 2 - 1] +
                         count1[i - k / 2 - 1][j - k / 2 - 1] * (k / 2 + 1));

                    int total_dis_y_re1 =
                        dis_y_re1[i - k / 2][j] - dis_y_re1[i + k / 2 + 1][j] -
                        (dis_y_re1[i - k / 2][j + k / 2 + 1] +
                         count_re1[i - k / 2][j + k / 2 + 1] * (k / 2 + 1)) +
                        (dis_y_re1[i + k / 2 + 1][j + k / 2 + 1] +
                         count_re1[i + k / 2 + 1][j + k / 2 + 1] * (k / 2 + 1));

                    int total_dis_x2 =
                        dis_x2[i][j + k / 2] - dis_x2[i][j - k / 2 - 1] -
                        (dis_x2[i - k / 2 - 1][j + k / 2] +
                         count2[i - k / 2 - 1][j + k / 2] * (k / 2 + 1)) +
                        (dis_x2[i - k / 2 - 1][j - k / 2 - 1] +
                         count2[i - k / 2 - 1][j - k / 2 - 1] * (k / 2 + 1));

                    int total_dis_x_re2 =
                        dis_x_re2[i][j - k / 2] - dis_x_re2[i][j + k / 2 + 1] -
                        (dis_x_re2[i + k / 2 + 1][j - k / 2] +
                         count_re2[i + k / 2 + 1][j - k / 2] * (k / 2 + 1)) +
                        (dis_x_re2[i + k / 2 + 1][j + k / 2 + 1] +
                         count_re2[i + k / 2 + 1][j + k / 2 + 1] * (k / 2 + 1));

                    int total_dis_y2 =
                        dis_y2[i + k / 2][j] - dis_y2[i - k / 2 - 1][j] -
                        (dis_y2[i + k / 2][j - k / 2 - 1] +
                         count2[i + k / 2][j - k / 2 - 1] * (k / 2 + 1)) +
                        (dis_y2[i - k / 2 - 1][j - k / 2 - 1] +
                         count2[i - k / 2 - 1][j - k / 2 - 1] * (k / 2 + 1));

                    int total_dis_y_re2 =
                        dis_y_re2[i - k / 2][j] - dis_y_re2[i + k / 2 + 1][j] -
                        (dis_y_re2[i - k / 2][j + k / 2 + 1] +
                         count_re2[i - k / 2][j + k / 2 + 1] * (k / 2 + 1)) +
                        (dis_y_re2[i + k / 2 + 1][j + k / 2 + 1] +
                         count_re2[i + k / 2 + 1][j + k / 2 + 1] * (k / 2 + 1));

                    // if (i == 3 && j == 2) {
                    //     cout << total_dis_x1 << " " << total_dis_x_re1 <<
                    //     endl; cout << total_dis_y1 << " " << total_dis_y_re1
                    //     << endl;
                    // }

                    ans = std::min(ans, abs(total_dis_x1 + total_dis_x_re1 +
                                            total_dis_y1 + total_dis_y_re1 -
                                            total_dis_x2 - total_dis_x_re2 -
                                            total_dis_y2 - total_dis_y_re2));
                }
            }
        }

        cout << ans << endl;
    }

    return 0;
}
