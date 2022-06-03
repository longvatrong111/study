#include <bits/stdc++.h>
using namespace std;

#define TESTMOD true;

/* global variables */

/* main function */
int main () {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int N; cin >> N;
    map<int, int> M;
    int num;
    for (int i = 0; i < N; ++i) {
        cin >> num;
        M[num]++;
    }
    
    int count = 0;
    int need = 0, remain;
    for (auto it = M.begin(); it != M.end(); ++it) {
        if (it->second >= need) {
            it->second -= need;
            need = 0;
        }
        else {
            need -= it->second;
            continue;
        }
        
        count += it->second/it->first;
        remain = it->second%it->first;
        
        if (remain == 0) continue;
        else {
            need = it->first - remain;
            count++;
        }
    }
    
    cout << count << endl;
    
    return 0;
}