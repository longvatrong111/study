#include <bits/stdc++.h>
using namespace std;
 
int const INF = int(1e9 + 7);
int const OFFSET = 100;
bool mem[152][152][300] = {};
int N;
string const alice = "ALICE";
string const albert = "ALBERT";
 
void recurse(string const& S, int low, int high, int diff, bool turnAlbert, int& ans) {
    if (mem[low][high][diff]) return;
 
    int curDiff = diff;
    if (low == high) {
        if (diff>OFFSET) {
            ans = min(ans, diff-OFFSET);
        }
        mem[low][high][diff] = true;
        return;
    }
 
    if (turnAlbert) {
        if (albert.find(S[low]) != std::string::npos) {
            recurse(S, low + 1, high, diff + 2, false, ans);
        } else {
            curDiff = diff;
            if (albert.find(S[high-1]) != std::string::npos) curDiff += 2;
            recurse(S, low, high - 1, curDiff, false, ans);
        }
    } else {
        curDiff = diff;
        if (alice.find(S[low]) != std::string::npos) curDiff -= 1;
        recurse(S, low + 1, high, curDiff, true, ans);
 
        curDiff = diff;
        if (alice.find(S[high-1]) != std::string::npos) curDiff -= 1;
        recurse(S, low, high - 1, curDiff, true, ans);
    }
 
    mem[low][high][diff] = true;
}
 
void solve(int tc) {
    int ans = INF;
 
    string S;
    cin >> S;
 
    N = S.size();
 
    fill(&(mem[0][0][0]), &(mem[0][0][0]) + 152 * 152 * 300, false);
    recurse(S, 0, N, OFFSET, true, ans);
 
    if (ans == INF) {
        cout << -1 << '\n';
    } else {
        cout << ans << '\n';
    }
}
 
int main(int argc, char* argv[]) {
    ifstream inFile("P5-data-15.txt");
	ofstream outFile("P5-data-15-out.txt");
 
    int tcs = 1;
    inFile >> tcs;
    int tc = 1;
    while (tc <= tcs) {
    	tc++;
		int ans = INF;
	 
	    string S;
	    inFile >> S;
	 
	    N = S.size();
	 
	    fill(&(mem[0][0][0]), &(mem[0][0][0]) + 152 * 152 * 300, false);
	    recurse(S, 0, N, OFFSET, true, ans);
	 
	    if (ans == INF) {
	        outFile << -1 << '\n';
	    } else {
	        outFile << ans << '\n';
    }
	};
}


