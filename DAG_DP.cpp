#include <bits/stdc++.h>
using namespace std;

int main() {
    int n,m;
    cin >> n >> m;
    vector<vector<int>> g(n);
    vector<int> dp(n,-1);
    for(int i=0;i<m;i++){
        int x,y;
        cin >> x >> y;
        x--,y--;
        g[x].push_back(y);
    }

    auto dfs = [&](auto&& dfs, int node) -> int {
        if(dp[node]!=-1) return dp[node];

        int tmp=0;
        for(auto nn : g[node]){
            tmp=max(tmp,dfs(dfs,nn)+1);
        }
        return dp[node]=tmp;
    };

    int ans=0;
    for(int i=0;i<n;i++){
        ans=max(ans,dfs(dfs,i));
    }
    cout << ans << endl;
}
