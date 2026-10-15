#include <bits/stdc++.h>
using namespace std;

struct LazySegTree{
    int n;
    vector<long long> seg,lazy;

    LazySegTree(int n):n(n){
        seg.resize(4*n);
        lazy.resize(4*n);
    }

    void build(vector<long long>&a,int k,int l,int r){
        if(r-l==1){
            seg[k]=a[l];
            return;
        }
        int m=(l+r)/2;
        build(a,k*2,l,m);
        build(a,k*2+1,m,r);
        seg[k]=seg[k*2]+seg[k*2+1];
    }

    void push(int k,int l,int r){
        if(lazy[k]==0) return;

        seg[k]+=lazy[k]*(r-l);

        if(r-l>1){
            lazy[k*2]+=lazy[k];
            lazy[k*2+1]+=lazy[k];
        }

        lazy[k]=0;
    }

    void update(int a,int b,long long x,int k,int l,int r){
        push(k,l,r);

        if(r<=a||b<=l) return;

        if(a<=l&&r<=b){
            lazy[k]+=x;
            push(k,l,r);
            return;
        }

        int m=(l+r)/2;

        update(a,b,x,k*2,l,m);
        update(a,b,x,k*2+1,m,r);

        seg[k]=seg[k*2]+seg[k*2+1];
    }

    long long query(int a,int b,int k,int l,int r){
        push(k,l,r);

        if(r<=a||b<=l) return 0;

        if(a<=l&&r<=b) return seg[k];

        int m=(l+r)/2;

        return query(a,b,k*2,l,m)+query(a,b,k*2+1,m,r);
    }
};

int main(){
    int N,Q;
    cin>>N>>Q;

    vector<long long>C(N);
    for(int i=0;i<N;i++) cin>>C[i];

    LazySegTree seg(N);
    seg.build(C,1,0,N);

    while(Q--){
        int t;
        cin>>t;

        if(t==1){
            int l,r,v;
            cin>>l>>r>>v;
            l--;
            seg.update(l,r,v,1,0,N);
        }
        else{
            int l,r;
            cin>>l>>r;
            l--;
            cout<<seg.query(l,r,1,0,N)<<endl;
        }
    }
}