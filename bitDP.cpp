#include <bits/stdc++.h>
using namespace std;

const int INF=1e9;

int main() {
    int n,m;
    cin >> n >> m;

    vector<int> c(m);

    for(int i=0;i<m;i++){
        int ci=0;
        for(int j=0;j<n;j++){
            int x;
            cin >> x;
            if(x) ci |= (1<<j);
        }
        c[i]=ci;
    }

    vector<int> dp(1<<n,INF);
    dp[0]=0;

    for(int bit=0;bit<(1<<n);bit++){
        if(dp[bit]==INF) continue;
        for(int j=0;j<m;j++){
            int nxt= c[j] | bit;

            dp[nxt]=min(dp[bit]+1,dp[nxt]);
        }
    }

    if(dp[(1<<n)-1]==INF) cout << -1 << endl;
    else cout << dp[(1<<n)-1] << endl;
}