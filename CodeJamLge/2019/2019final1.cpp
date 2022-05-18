#include<bits/stdc++.h>
using namespace std;
int T, N;

int main () {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cin >> T;
    while (T--) {
        cin >> N;
        set<int> setX, setY;
        int x, y;
        for (int i = 0; i < N; ++i) {
            cin >> x >> y;
            setX.insert(x);
            setY.insert(y);
        }

        if (setX.size()*setY.size() == N) cout << "BALANCED" << endl;
        else cout << "NOT BALANCED" << endl;
    }
    return 0;
}