#include <bits/stdc++.h>
using namespace std;

struct UnionFind {
    vector<int> par, rnk;
    UnionFind(int n): par(n), rnk(n, 0) {
        iota(par.begin(), par.end(), 0);
    }
    int root(int x) {
        return par[x] == x ? x : par[x] = root(par[x]);
    }
    // unite: 結合し、新しい代表元を返す
    int unite(int x, int y) {
        x = root(x);
        y = root(y);
        if (x == y) return x;
        if (rnk[x] < rnk[y]) swap(x, y);
        par[y] = x;
        if (rnk[x] == rnk[y]) rnk[x]++;
        return x; // 新しい代表元
    }

    bool same(int x, int y) {
        return root(x) == root(y);
    }
};

int main(){
    int n;
    cin >> n;
    vector<vector<int>> a(n,vector<int>(n));
    for(int i=0;i<n;i++){
        for(int j=i+1;j<n;j++){
            cin >> a[i][j];
            a[j][i]=a[i][j];
        }
    }

    UnionFind uf(n);

    vector<tuple<int,int,int>> edges;
    for(int i=0;i<n;i++){
        for(int j=i+1;j<n;j++){
            edges.push_back({a[i][j],i,j});
        }
    }

    sort(edges.begin(), edges.end());

    vector<vector<pair<int,int>>> g(n);

    for(auto [w,u,v] : edges){
        if(!uf.same(u,v)){
            uf.unite(u,v);
            g[u].push_back({v,w});
            g[v].push_back({u,w});
        }
    }

    vector<vector<int>> dist(n,vector<int>(n,-1));

    for(int i=0;i<n;i++){
        queue<int> q;
        q.push(i);
        dist[i][i]=0;

        while(!q.empty()){
            int v=q.front(); q.pop();
            for(auto [to,w]:g[v]){
                if(dist[i][to]==-1){
                    dist[i][to]=dist[i][v]+w;
                    q.push(to);
                }
            }
        }
    }

    for(int i=0;i<n;i++){
        for(int j=i+1;j<n;j++){
            if(dist[i][j] != a[i][j]){
                cout << "No\n";
                return 0;
            }
        }
    }
    cout << "Yes\n";
}