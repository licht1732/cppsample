#include <bits/stdc++.h>
using namespace std;

// --- 転倒数ライブラリ ---
struct Fenwick {
    int n;
    vector<long long> bit;
    Fenwick(int n=0):n(n),bit(n+1,0){}
    void init(int m){
        n=m;
        bit.assign(n+1,0);
    }
    void add(int i,long long x){
        for(i++; i<=n; i+=i&-i) bit[i]+=x;
    }
    long long sum(int i){
        long long s=0;
        for(i++; i>0; i-=i&-i) s+=bit[i];
        return s;
    }
    long long sum(int l,int r){
        if(r<l) return 0;
        return sum(r)-sum(l-1);
    }
};

long long inversion_count(vector<long long> a){
    int n=a.size();

    // 座標圧縮
    vector<long long> b=a;
    sort(b.begin(),b.end());
    b.erase(unique(b.begin(),b.end()),b.end());

    for(int i=0;i<n;i++){
        a[i]=lower_bound(b.begin(),b.end(),a[i])-b.begin();
    }

    Fenwick fw(b.size());

    long long inv=0;
    for(int i=n-1;i>=0;i--){
        inv += fw.sum(a[i]-1);
        fw.add(a[i],1);
    }
    return inv;
}

//指定区間の種類数を求める
struct Query{
    int l,r,id;
};

vector<int> distinct_query(vector<long long> a, vector<Query> qs){
    int n=a.size();
    int q=qs.size();

    sort(qs.begin(),qs.end(),[](auto &x,auto &y){
        return x.r < y.r;
    });

    Fenwick fw(n);

    unordered_map<int,int> last;
    vector<int> ans(q);

    int cur=0;

    for(auto qu:qs){

        while(cur<=qu.r){

            if(last.count(a[cur]))
                fw.add(last[a[cur]],-1);

            fw.add(cur,1);
            last[a[cur]]=cur;

            cur++;
        }

        ans[qu.id] = fw.sum(qu.l,qu.r);
    }

    return ans;
}

int main(){
    int n;
    cin >> n;
    vector<long long> a(n);
    for(int i=0;i<n;i++) cin >> a[i];

    cout << inversion_count(a) << endl;

    int q;
    cin >> q;

    vector<Query> qs(q);

    for(int i=0;i<q;i++){
        cin >> qs[i].l >> qs[i].r;
        qs[i].l--;
        qs[i].r--;
        qs[i].id=i;
    }

    auto ans = distinct_query(a,qs);

    for(auto x:ans) cout<<x<<"\n";
}

