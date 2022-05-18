#include<bits/stdc++.h>
using namespace std;

int T, N;

int main () {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> T;
    while (T--) {
        cin >> N;
        int arr[N];
        for (int i = 0; i < N; ++i) cin >> arr[i];
        std::sort(arr, arr+N);

        if (arr[0] == arr[N-1]) {
            cout << "INFINITY" << endl;
            continue;    
        }

        int arr2[N-1];
        for (int i = 1; i < N; ++i) arr2[i-1] = arr[i] - arr[i-1];
        
        std::sort(arr2, arr2+N-1);
        
        int index = 0;
        while (index < N-1 && arr2[index] == 0) index++;

        cout << arr2[index] << endl;
    }

    return 0;
}