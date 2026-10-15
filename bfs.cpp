#include <bits/stdc++.h>
using namespace std;

const int INF = 1e9;

int main() {
    int h,w,d,ans=0;
    cin >> h >> w >> d;
    vector<vector<char>> v(h,vector<char>(w));
    vector<vector<int>> dist(h,vector<int>(w,INF));
    queue<pair<int,int>> q;
    for(int i=0;i<h;i++){
      for(int j=0;j<w;j++){
        cin >> v[i][j];
        if(v[i][j]=='H'){
          q.push({i,j});
          dist[i][j]=0;
        }
      }
    }
    
    int dy[4]={1,-1,0,0};
    int dx[4]={0,0,1,-1};
    
    while(!q.empty()){
      auto [y,x]=q.front();
      q.pop();
      int nowd=dist[y][x];
      if(nowd>=d){
        continue;
      }
      for(int i=0;i<4;i++){
        int nextx=x+dx[i],nexty=y+dy[i];
        if(nextx<0 || nextx>=w || nexty<0 || nexty>=h){
          continue;
        }
        else if(v[nexty][nextx]=='#'){
          continue;
        }
        else if(dist[nexty][nextx]>d+1){
          q.push({nexty,nextx});
          dist[nexty][nextx]=nowd+1;
        }
      }
    }
    
    for(int i=0;i<h;i++){
      for(int j=0;j<w;j++){
        if(dist[i][j]<=d){
          ans++;
        }
      }
    }
    
    cout << ans << endl;
    
}