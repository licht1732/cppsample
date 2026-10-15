#include <bits/stdc++.h>
using namespace std;

const long long INF = 1e18;

int main() {
    int n,m;
    cin >> n >> m;
    vector<vector<pair<long long,long long>>> g(n);
    vector<long long> weight(n,INF);
    vector<long long> a(n);
    for(int i=0;i<n;i++){
      cin >> a[i];
    }
    priority_queue<pair<long long,long long>, vector<pair<long long, long long>>, greater<>> q;
    for(int i=0;i<m;i++){
      long long u,v,b;
      cin >> u >> v >> b;
      g[u-1].push_back({v-1,b});
      g[v-1].push_back({u-1,b});//無向グラフの時に必要
    }
    //ノードに重みついてるから使うとき注意、ノードに重みがついてないなら重みの初期値を0にする
    weight[0]=a[0];
    q.push({a[0],0});
    
    while(!q.empty()){
      auto [cost,u]=q.top();
      q.pop();
      if(cost>weight[u]){
        continue;
      }
      else{
        for(auto [v,edge_cost] : g[u]){
          long long ncost=cost+edge_cost+a[v];
          if(ncost<weight[v]){
            weight[v]=ncost;
            q.push({ncost,v});
          }
        }
      }
    }
    for(int i=1;i<n;i++){
      cout << weight[i] << " ";
    }
}