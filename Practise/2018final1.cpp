#include <bits/stdc++.h>
using namespace std;

#define TESTMOD true;

/* global variables */
int T, n1, n2, n3, n4, n5;

/* main function */
int main () {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    T = 1;

    while (T--) {
        cin >> n1 >> n2 >> n3 >> n4 >> n5;
        int count = 0;;

        count += n3 + n4 + n5;
        n1 -= n4;
        if (n1 < 0) n1 = 0;
        
        if (n2 >= n3) {
            n2 -= n3;
            count += n2/2;
            n1 -= n2/2;
            if (n1 < 0) n1 = 0;
            if (n2%2 == 1) {
                count += 1;
                n1 -= 3;
                if (n1 < 0) n1 = 0;
            }
            count += n1%5 == 0? n1/5 : n1/5 + 1;
        }
        else {
            n3 -= n2;
            n1 -= n3*2;
            if (n1 < 0) n1 = 0;
            count += n1%5 == 0? n1/5 : n1/5 + 1;
        }

        cout << count << endl;
    }

    return 0;
}