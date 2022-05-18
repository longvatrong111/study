#include <bits/stdc++.h>
using namespace std;

#define TESTMOD true;

/* global variables */
int T;

int findMinHeightTrees(int n, vector<vector<int>>& edges, vector<vector<pair<int, int>>>& adj) {
    if(n==1) return 0;
    vector<int> deg(n+1);
    for(auto& edge:edges){
        deg[edge[1]]++;
        deg[edge[0]]++;
    }

    queue<int> q;
    vector<int> ans;
    for(int i=1;i<=n;i++){
        if(deg[i]==1){ // start with leaves
            deg[i]--;
            q.push(i);
        }
    }

    while(!q.empty()){
        int sz = q.size();
        ans.clear();
        while(sz--){
            int v = q.front();
            q.pop();

            ans.push_back(v);
            for(auto& u:adj[v]){
                if(--deg[u.first]==1) // when the current node becomes a leaf push it into queue
                    q.push(u.first);
            }
        }
    }

    return ans[0];
}

int calsizeTree(vector<int>& sizeTree, int root, int parent, vector<vector<pair<int, int>>>& adject, vector<int>& parents, vector<int>& lenToParent, vector<int>& height, int h) {
    int ans = 0;
    parents[root] = parent;
    height[root] = h;
    for (auto& child:adject[root]) {
        if (child.first != parent) {
            ans += calsizeTree(sizeTree, child.first, root, adject, parents, lenToParent, height, h+1);
        }
        else {
            lenToParent[root] = child.second;
        }
    }

    return sizeTree[root] = ans + 1;
}

int main () {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> T;
    while (T--) {
        int n; cin >> n;
        int m; cin >> m;
        
        vector<vector<pair<int, int>>> adject(n+1, vector<pair<int, int>>());
        vector<vector<int>> E(n-1, vector<int>(3));
        for (int i = 0; i < n-1; ++i) {
            cin >> E[i][0] >> E[i][1] >> E[i][2];
            adject[E[i][0]].push_back({E[i][1], E[i][2]});
            adject[E[i][1]].push_back({E[i][0], E[i][2]});
        }
        
        vector<int> sizeTree(n+1, 0); // 1 -> n
        vector<int> parents(n+1, 0);
        vector<int> lenToParent(n+1, 0);
        vector<int> height(n+1, 0);
        int root = findMinHeightTrees(n, E, adject);
        // int root = 1;

        calsizeTree(sizeTree, root, -1, adject, parents, lenToParent, height, 0);
        
        long sumPath = 0, minans = LONG_MAX, maxans = LONG_MIN, cursum = 0;
        int nm;
        for (int j = 0; j < n-1; ++j) {
            nm = std::min(sizeTree[E[j][0]], sizeTree[E[j][1]]);
            sumPath += (long)nm*(n-nm)*E[j][2];
        }
        
        // for (int i = 1; i <= n; ++i) cout << sizeTree[i] << " ";
        // cout << endl;
        // for (int i = 1; i <= n; ++i) cout << lenToParent[i] << " ";
        // cout << endl;
        
        int A, x, y, z, n1, n2, n3, n4, remain, cur, cur2;
        for (int i = 0; i < m; ++i) {
            cin >> A >> x >> y >> z;
            A--;
            
            cursum = sumPath;
            
            if (sizeTree[E[A][0]] > sizeTree[E[A][1]]) {
                n1 = E[A][0];
                n2 = E[A][1];
            }
            else {
                n1 = E[A][1];
                n2 = E[A][0];
            }
            // cout << n1 << " " << n2 << endl;

            cur = x;
            while (true) {
                if (cur == root) {
                    n3 = x;
                    n4 = y;
                    break;
                }

                if (cur == n2) {
                    n4 = x;
                    n3 = y;
                    break;
                }

                cur = parents[cur];
            }
            // cout << n3 << " " << n4 << endl;

                        
            cursum -= (long)sizeTree[n2]*(n-sizeTree[n2])*lenToParent[n2];
            cursum += (long)sizeTree[n2]*(n-sizeTree[n2])*z;
            // cout << cursum << endl;
            
            // int lca = lowestCommonAscentor(n1, n3);
            cur = n1;
            cur2 = n3;

            while (cur != -1 && cur2 != -1) {
                if (cur == cur2) break;

                if (height[cur] > height[cur2]) {
                    cursum -= (long)sizeTree[cur]*(n-sizeTree[cur])*lenToParent[cur];
                    cursum += (long)(sizeTree[cur]-sizeTree[n2])*(n-sizeTree[cur]+sizeTree[n2])*lenToParent[cur];
                    
                    cur = parents[cur];
                }
                else {
                    cursum -= (long)sizeTree[cur2]*(n-sizeTree[cur2])*lenToParent[cur2];
                    cursum += (long)(sizeTree[cur2]+sizeTree[n2])*(n-sizeTree[cur2]-sizeTree[n2])*lenToParent[cur2];

                    cur2 = parents[cur2];
                }
            }

            // while (cur != lca) {
            //     if (parents[cur] != -1) {
            //         cursum -= (long)sizeTree[cur]*(n-sizeTree[cur])*lenToParent[cur];
            //         cursum += (long)(sizeTree[cur]-sizeTree[n2])*(n-sizeTree[cur]+sizeTree[n2])*lenToParent[cur];
            //     }
            //     cur = parents[cur];
            // }
            // // cout << cursum << endl;

            // while (cur != lca) {
            //     if (parents[cur] != -1) {
            //         cursum -= (long)sizeTree[cur]*(n-sizeTree[cur])*lenToParent[cur];
            //         cursum += (long)(sizeTree[cur]+sizeTree[n2])*(n-sizeTree[cur]-sizeTree[n2])*lenToParent[cur];
            //     }
            //     cur = parents[cur];
            // }
            // // cout << cursum << endl;

            cur = n4;
            while (true) {
                if (cur == n2) break;

                remain = sizeTree[n2] - sizeTree[cur]; // size tree of parent, now is a child

                cursum -= (long)sizeTree[cur]*(n-sizeTree[cur])*lenToParent[cur];
                cursum += (long)remain*(n-remain)*lenToParent[cur];
                
                cur = parents[cur];
            }
            // cout << cursum << endl;

            minans = min(minans, cursum);
            maxans = max(maxans, cursum);
        }

        cout << sumPath << " " << minans << " " << maxans << endl;
    }

    return 0;
}