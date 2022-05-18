#include <bits/stdc++.h>
using namespace std;

#define TESTMOD true;

/* global variables */
int T, N, M;

int main () {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> T;
    while (T--) {
        cin >> N >> M;

        int count = 0;
        int turn = 0;

        /*
        count is the number of swaps
        turn is the number of elements that are brought into the end
        */
        while (turn < N && count + (N-1-turn) <= M) {
            count += N-1-turn;
            turn++;
        }

        int remainCount = M - count; /* the number of swaps of the last turn */

        /* elements that are not moved */
        for (int i = turn + 2; i <= N; ++i) {
            if (i - turn - 2 == remainCount) cout << turn + 1 << " "; /* the element is moved in the last turn */
            cout << i << " ";
        }

        /* elements that are brought into the end */
        for (int i = turn; i >= 1; --i) cout << i << " ";
        cout << endl;
    }

    return 0;
}