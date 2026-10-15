#include <bits/stdc++.h>
using namespace std;

const int LOG = 30;

int main(){
    int n, Q;
    cin >> n >> Q;

    vector<int> a(n);
    for(int i=0;i<n;i++){
        cin >> a[i];
        a[i]--;
    }

    vector<vector<int>> dp(LOG, vector<int>(n));

    //行先指定
    for(int i=0;i<n;i++){
        dp[0][i]=a[i];
    }

    //ダブリング
    for(int k=1;k<LOG;k++){
        for(int i=0;i<n;i++){
            dp[k][i]=dp[k-1][dp[k-1][i]];
        }
    }

    //Xは初期位置、Yは何回後か
    while(Q--){
        int X;
        long long Y;
        cin >> X >> Y;
        X--;

        int cur=X;
        for(int k=0;k<LOG;k++){
            if(Y & (1LL << k)){
                cur=dp[k][cur];
            }
        }

        cout << cur+1 << "\n";
    }
}
