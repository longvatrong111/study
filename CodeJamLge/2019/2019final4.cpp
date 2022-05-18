#include <bits/stdc++.h>
using namespace std;

#define TESTMOD true;

/* global variables */
int T;
int arr[1<<26] = {0};

/* main function */
int main () {
    
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> T;

    while (T--) {
        string s;
        cin >> s;
        
        memset(arr, 0, sizeof arr);
        list<char> curChar;
        int temp;

        for (int i = 0; i < s.size(); ++i) {
            for (auto it = curChar.begin(); it != curChar.end(); ++it) {
                if (*it == s[i]) {
                    curChar.erase(it);
                    break;
                }
            }
            
            curChar.push_back(s[i]);
            temp = 0;
            for (auto it = curChar.rbegin(); it != curChar.rend(); ++it) {
                temp = temp | (1 << (*it-'A'));
                arr[temp] = 1;
            }
        }

        int count = 0;
        for (int i = 0; i < (1<<26); ++i) {
            if (arr[i]) count++;
        }
        cout << count << endl;
    }

    return 0;
}