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

struct UnionFind2D {
    int H, W;
    vector<int> par, rnk;

    UnionFind2D(int h, int w) : H(h), W(w), par(h * w), rnk(h * w, 0) {
        iota(par.begin(), par.end(), 0);
    }

    // (i, j) → 1次元
    int id(int i, int j) {
        return i * W + j;
    }

    int root(int x) {
        return par[x] == x ? x : par[x] = root(par[x]);
    }

    int unite(int i1, int j1, int i2, int j2) {
        int x = root(id(i1, j1));
        int y = root(id(i2, j2));
        if (x == y) return x;

        if (rnk[x] < rnk[y]) swap(x, y);
        par[y] = x;
        if (rnk[x] == rnk[y]) rnk[x]++;
        return x;
    }

    bool same(int i1, int j1, int i2, int j2) {
        return root(id(i1, j1)) == root(id(i2, j2));
    }
};

//重み付きUnionFind
struct WeightedUF {
    vector<int> par;
    vector<long long> diff; // 親との差分

    WeightedUF(int n): par(n, -1), diff(n, 0) {}

    int root(int x){
        if(par[x] < 0) return x;
        int r = root(par[x]);
        diff[x] += diff[par[x]];
        return par[x] = r;
    }

    long long weight(int x){
        root(x);
        return diff[x];
    }

    bool unite(int x, int y, long long w){
        // weight[y] - weight[x] = w にしたい
        w += weight(x);
        w -= weight(y);

        x = root(x);
        y = root(y);

        if(x == y) return false;

        if(par[x] > par[y]){
            swap(x,y);
            w = -w;
        }

        par[x] += par[y];
        par[y] = x;
        diff[y] = w;

        return true;
    }

    bool same(int x, int y){
        return root(x) == root(y);
    }

    long long diff_xy(int x, int y){
        return weight(y) - weight(x);
    }
};

struct WeightedUF2D {
    vector<int> par;
    vector<pair<long long,long long>> diff;

    WeightedUF2D(int n): par(n, -1), diff(n, {0,0}) {}

    int root(int x){
        if(par[x] < 0) return x;
        int r = root(par[x]);
        diff[x].first += diff[par[x]].first;
        diff[x].second += diff[par[x]].second;
        return par[x] = r;
    }

    pair<long long,long long> weight(int x){
        root(x);
        return diff[x];
    }

    bool unite(int x, int y, pair<long long,long long> w){
        // weight[y] - weight[x] = w
        auto wx = weight(x);
        auto wy = weight(y);

        w.first += wx.first - wy.first;
        w.second += wx.second - wy.second;

        x = root(x);
        y = root(y);

        if(x == y) return false;

        if(par[x] > par[y]){
            swap(x,y);
            w.first = -w.first;
            w.second = -w.second;
        }

        par[x] += par[y];
        par[y] = x;
        diff[y] = w;

        return true;
    }

    bool same(int x, int y){
        return root(x) == root(y);
    }

    pair<long long,long long> diff_xy(int x, int y){
        auto wx = weight(x);
        auto wy = weight(y);
        return {wy.first - wx.first, wy.second - wx.second};
    }
};

int main() {
    int n,m;
    cin >> n >> m;
    UnionFind uf(n);
    vector<pair<int,int>> r(m);
    for(int i=0;i<m;i++){
        int a,b;
        cin >> a >> b;
        a--,b--;
        r[i]={a,b};
    }
    int Q;
    cin >> Q;
    vector<vector<int>> qu(Q,vector<int>(3));
    vector<bool> rmv(m);
    for(int i=0;i<Q;i++){
        int q;
        cin >> q;
        if(q==1){
            int x;
            cin >> x;
            x--;
            qu[i][0]=1;
            qu[i][1]=x;
            rmv[x]=false;
        }
        else{
            int u,v;
            cin >> u >> v;
            u--,v--;
            qu[i][0]=2;
            qu[i][1]=u;
            qu[i][2]=v;
        }
    }
    for(int i=0;i<m;i++){
        if(rmv[i]){
            uf.unite(r[i].first,r[i].second);
        }
    }
    vector<bool> ans;
    for(int i=Q-1;i>=0;i--){
        if(qu[i][0]==1){
            uf.unite(r[qu[i][1]].first,r[qu[i][1]].second);
        }
        else{
            if(same(qu[i][1],qu[i][2])) ans.push_back(true);
            else ans.push_back(false);
        }
    }
    reverse(ans.begin(),ans.end());
    for(int i=0;i<ans.size();i++){
        if(ans[i]) cout << "Yes" << endl;
        else cout << "No" << endl;
    }
}