#include <bits/stdc++.h>
using namespace std;

const int INF=1e9+7;

int main(){
    int n;
    string s,t="atcoder";
    cin >> n >> s;

    vector<vector<int>> dp(n+1,vector<int>((int)t.size()+1));

    dp[0][0]=1;

    for(int i=0;i<n;i++){
        for(int j=0;j<=(int)t.size();j++){
            if(j<t.size() && s[i]==t[j]){
                dp[i+1][j+1]+=dp[i][j];
                dp[i+1][j+1]%=INF;
            }
            dp[i+1][j]+=dp[i][j];
            dp[i+1][j]%=INF;
        }
    }

    cout << dp[n][(int)t.size()] << endl;
}
