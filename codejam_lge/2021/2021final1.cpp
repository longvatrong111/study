#include <bits/stdc++.h>
using namespace std;

#define TESTMOD true;

/* global variables */
int T, N;

string str1(vector<string> matrix) {
    int state[4] = {0,1,2,3}; // right, down, left, up
    int cur_state = 0; // state[cur_state%4]
    
    int m = matrix.size(), n = matrix[0].size(); 
    int x = 0, y = 0;
    string ans; ans.push_back(matrix[x][y]);
    matrix[x][y] = 'a';
    
    while (true) {
        if ((x == 0 || matrix[x-1][y] == 'a') &&
            (x == m-1 || matrix[x+1][y] == 'a') &&
            (y == 0 || matrix[x][y-1] == 'a') &&
            (y == n-1 || matrix[x][y+1] == 'a')) {
            break;
        }
        
        switch (state[cur_state%4]) {
            case 1:
                while (x < m-1 && matrix[x+1][y] != 'a') {
                    x++;
                    ans.push_back(matrix[x][y]);
                    matrix[x][y] = 'a';
                }
                cur_state++;
                break;
            case 0:
                while (y < n-1 && matrix[x][y+1] != 'a') {
                    y++;
                    ans.push_back(matrix[x][y]);
                    matrix[x][y] = 'a';
                }
                cur_state++;
                break;
            case 3:
                while (x > 0 && matrix[x-1][y] != 'a') {
                    x--;
                    ans.push_back(matrix[x][y]);
                    matrix[x][y] = 'a';
                }
                cur_state++;
                break;
            case 2:
                while (y > 0 && matrix[x][y-1] != 'a') {
                    y--;
                    ans.push_back(matrix[x][y]);
                    matrix[x][y] = 'a';
                }
                cur_state++;
                break;
        }
    }
    
    return ans;
}

string str2(vector<string> matrix) {
    int state[4] = {0,1,2,3}; // right, down, left, up
    int cur_state = 1; // state[cur_state%4]
    
    int m = matrix.size(), n = matrix[0].size(); 
    int x = 0, y = n-1;
    string ans; ans.push_back(matrix[x][y]);
    matrix[x][y] = 'a';
    
    while (true) {
        if ((x == 0 || matrix[x-1][y] == 'a') &&
            (x == m-1 || matrix[x+1][y] == 'a') &&
            (y == 0 || matrix[x][y-1] == 'a') &&
            (y == n-1 || matrix[x][y+1] == 'a')) {
            break;
        }
        
        switch (state[cur_state%4]) {
            case 1:
                while (x < m-1 && matrix[x+1][y] != 'a') {
                    x++;
                    ans.push_back(matrix[x][y]);
                    matrix[x][y] = 'a';
                }
                cur_state++;
                break;
            case 0:
                while (y < n-1 && matrix[x][y+1] != 'a') {
                    y++;
                    ans.push_back(matrix[x][y]);
                    matrix[x][y] = 'a';
                }
                cur_state++;
                break;
            case 3:
                while (x > 0 && matrix[x-1][y] != 'a') {
                    x--;
                    ans.push_back(matrix[x][y]);
                    matrix[x][y] = 'a';
                }
                cur_state++;
                break;
            case 2:
                while (y > 0 && matrix[x][y-1] != 'a') {
                    y--;
                    ans.push_back(matrix[x][y]);
                    matrix[x][y] = 'a';
                }
                cur_state++;
                break;
        }
    }
    
    return ans;
}

string str3(vector<string> matrix) {
    int state[4] = {0,1,2,3}; // right, down, left, up
    int cur_state = 2; // state[cur_state%4]
    
    int m = matrix.size(), n = matrix[0].size(); 
    int x = m-1, y = n-1;
    string ans; ans.push_back(matrix[x][y]);
    matrix[x][y] = 'a';
    
    while (true) {
        if ((x == 0 || matrix[x-1][y] == 'a') &&
            (x == m-1 || matrix[x+1][y] == 'a') &&
            (y == 0 || matrix[x][y-1] == 'a') &&
            (y == n-1 || matrix[x][y+1] == 'a')) {
            break;
        }
        
        switch (state[cur_state%4]) {
            case 1:
                while (x < m-1 && matrix[x+1][y] != 'a') {
                    x++;
                    ans.push_back(matrix[x][y]);
                    matrix[x][y] = 'a';
                }
                cur_state++;
                break;
            case 0:
                while (y < n-1 && matrix[x][y+1] != 'a') {
                    y++;
                    ans.push_back(matrix[x][y]);
                    matrix[x][y] = 'a';
                }
                cur_state++;
                break;
            case 3:
                while (x > 0 && matrix[x-1][y] != 'a') {
                    x--;
                    ans.push_back(matrix[x][y]);
                    matrix[x][y] = 'a';
                }
                cur_state++;
                break;
            case 2:
                while (y > 0 && matrix[x][y-1] != 'a') {
                    y--;
                    ans.push_back(matrix[x][y]);
                    matrix[x][y] = 'a';
                }
                cur_state++;
                break;
        }
    }
    
    return ans;
}

string str4(vector<string> matrix) {
    int state[4] = {0,1,2,3}; // right, down, left, up
    int cur_state = 3; // state[cur_state%4]
    
    int m = matrix.size(), n = matrix[0].size(); 
    int x = m-1, y = 0;
    string ans; ans.push_back(matrix[x][y]);
    matrix[x][y] = 'a';
    
    while (true) {
        if ((x == 0 || matrix[x-1][y] == 'a') &&
            (x == m-1 || matrix[x+1][y] == 'a') &&
            (y == 0 || matrix[x][y-1] == 'a') &&
            (y == n-1 || matrix[x][y+1] == 'a')) {
            break;
        }
        
        switch (state[cur_state%4]) {
            case 1:
                while (x < m-1 && matrix[x+1][y] != 'a') {
                    x++;
                    ans.push_back(matrix[x][y]);
                    matrix[x][y] = 'a';
                }
                cur_state++;
                break;
            case 0:
                while (y < n-1 && matrix[x][y+1] != 'a') {
                    y++;
                    ans.push_back(matrix[x][y]);
                    matrix[x][y] = 'a';
                }
                cur_state++;
                break;
            case 3:
                while (x > 0 && matrix[x-1][y] != 'a') {
                    x--;
                    ans.push_back(matrix[x][y]);
                    matrix[x][y] = 'a';
                }
                cur_state++;
                break;
            case 2:
                while (y > 0 && matrix[x][y-1] != 'a') {
                    y--;
                    ans.push_back(matrix[x][y]);
                    matrix[x][y] = 'a';
                }
                cur_state++;
                break;
        }
    }
    
    return ans;
}

void getMinStr (vector<string>& ans2, string& str) {
    int n = N;
    int start = 0;
    while ((n-1)*4 > 0) {
        string temp1 = str.substr(start+1, (n-1)*4-1);
        string temp2 = temp1;
        reverse(temp2.begin(), temp2.end());
        if (temp2 < temp1) {
            for (int i = 0; i < (n-1)*4-1; ++i) {
                str[start+1+i] = temp2[i];
            }
        }

        start += (n-1)*4;
        n = n-2;
    }

    ans2.push_back(str);
}

void getMaxStr (vector<string>& ans2, string& str) {
    int n = N;
    int start = 0;
    while ((n-1)*4 > 0) {
        string temp1 = str.substr(start+1, (n-1)*4-1);
        string temp2 = temp1;
        reverse(temp2.begin(), temp2.end());
        if (temp2 > temp1) {
            for (int i = 0; i < (n-1)*4-1; ++i) {
                str[start+1+i] = temp2[i];
            }
        }

        start += (n-1)*4;
        n = n-2;
    }

    ans2.push_back(str);
}



/* main function */
int main () {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> T;

    while (T--) {
        cin >> N;
        vector<string> input(N);
        for (int i = 0; i < N; ++i) cin >> input[i];
        
        // vector<string> input2;
        // for (int i = 0; i < N; ++i) {
        //     string temp = "";
        //     for (int j = 0; j < N; ++j) {
        //         temp += input[j][i];
        //     }
        //     input2.push_back(temp);
        // }
        vector<string> ans;
        ans.push_back(str1(input));
        ans.push_back(str2(input));
        ans.push_back(str3(input));
        ans.push_back(str4(input));
        // ans.push_back(str1(input2));
        // ans.push_back(str2(input2));
        // ans.push_back(str3(input2));
        // ans.push_back(str4(input2));

        vector<string> ans2;
        for (int i = 0; i < ans.size(); ++i) {
            getMinStr(ans2, ans[i]);
            getMaxStr(ans2, ans[i]);
        }

        std::sort(ans2.begin(), ans2.end());
        cout << ans2[ans2.size()-1] << " " << ans2[0] << endl;
        // cout << endl;
        // for (int i = 0; i < N; ++i) cout << input[i] << endl;
        // cout << endl;
        // for (int i = 0; i < N; ++i) cout << input2[i] << endl;
        // cout << endl;
        // cout << ans[0] << " " << ans[1] << " " << ans[2] << " " << ans[3] << " " << ans[4] << " " << ans[5] << " " << ans[6] << " " << ans[7] << endl;
    }

    return 0;
}