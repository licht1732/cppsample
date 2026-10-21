#include <bits/stdc++.h>
using namespace std;

int main() {
    int n,m;
    cin >> n >> m;

    vector<vector<int>> g(n),rg(n);
    for (int i=0;i<m;i++){
        int u, v;
        cin >> u >> v;
        u--, v--;

        g[u].push_back(v);
        rg[v].push_back(u);
    }

    vector<int> visited(n);
    stack<int> s;

    auto dfs = [&](auto&& dfs,int idx) -> void {
        visited[idx] = 1;
        for (int nxt : g[idx]) {
            if (visited[nxt]) continue;
            dfs(dfs, nxt);
        }
        s.push(idx);
    };

    for (int i=0;i<n;i++) {
        if (!visited[i]) dfs(dfs, i);
    }

    vector<int> tmp(n,-1);
    int cnt=0;

    auto dfs2 = [&](auto&& dfs2,int idx) -> void {
        tmp[idx]=cnt;
        for (int nxt : rg[idx]) {
            if (tmp[nxt]!=-1) continue;
            dfs2(dfs2,nxt);
        }
    };

    while (!s.empty()) {
        int idx=s.top();
        s.pop();

        if (tmp[idx]==-1) {
            dfs2(dfs2,idx);
            cnt++;
        }
    }

    vector<set<int>> ng(cnt);

    for (int i=0;i<n;i++){
        for (int x : g[i]) {
            if (tmp[i]==tmp[x]) continue;
            ng[tmp[i]].insert(tmp[x]);
        }
    }
}