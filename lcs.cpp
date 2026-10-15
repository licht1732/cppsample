#include <bits/stdc++.h>
using namespace std;

const long long INF=1e18;

int main() {
    string s,t;
    cin >> s >> t;
    vector<vector<int>> dp(s.size()+1,vector<int>(t.size()+1));
    

    //LCS
    for(int i=0;i<s.size();i++){
      for(int j=0;j<t.size();j++){
        if(s[i]==t[j]){
          dp[i+1][j+1]=max(dp[i+1][j+1],dp[i][j]+1);
        }
        dp[i+1][j+1]=max(dp[i+1][j+1],dp[i+1][j]);
        dp[i+1][j+1]=max(dp[i+1][j+1],dp[i][j+1]);
      }
    }
    
    //一致文字復元
    string ans="";
    int i=s.size(),j=t.size();
    while(i>0 && j>0){
      if(dp[i][j]==dp[i-1][j]){
        i--;
      }
      else if(dp[i][j]==dp[i][j-1]){
        j--;
      }
      else{
        ans=s[i-1]+ans;
        i--,j--;
      }
    }
    
    cout << ans << endl;
}