#include <bits/stdc++.h>
using namespace std;

vector<bool> visited;

//サイクル検出と探索頂点の印付け
vector<int> functional_cycle(const vector<int> &g,int x){
    unordered_map<int,int> pos;
    vector<int> path;

    int v=x;
    while(true){
        if(pos.count(v)){
            vector<int> cycle;
            for(int i=pos[v];i<(int)path.size();i++){
                cycle.push_back(path[i]);
            }
            for(auto u:path) visited[u]=true;
            return cycle;
        }

        if(visited[v]){
            for(auto u:path) visited[u]=true;
            return {};
        }

        pos[v]=path.size();
        path.push_back(v);
        v=g[v];
    }
}

int main() {
    int n;
    cin >> n;
    visited.resize(n);
    vector<int> a(n),cnt(n);
    vector<vector<int>> g(n);
    queue<int> q;
    for(int i=0;i<n;i++){
        cin >> a[i];
        a[i]--;
        g[a[i]].push_back(i);
    }

    for(int i=0;i<n;i++){
        if(visited[i]) continue;
        const auto &cycle=functional_cycle(a,i);
        for(auto v : cycle){
            cnt[v]=cycle.size();
            q.push(v);
        }
    }

    while(!q.empty()){
        auto now=q.front();
        q.pop();
        int d=cnt[now];

        for(auto nxt : g[now]){
            if(cnt[nxt]!=0) continue;
            cnt[nxt]=d+1;
            q.push(nxt);
        }
    }

    long long ans=0;
    for(int i=0;i<n;i++) ans+=cnt[i];
    cout << ans << endl;
}