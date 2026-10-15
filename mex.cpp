#include <bits/stdc++.h>
using namespace std;

int main() {
    int N, Q;
    cin >> N >> Q;
    vector<int> A(N);
    for (int i = 0; i < N; ++i) cin >> A[i];
    
    // データ
    map<int,int> ma;  // ma[val] := A の中に val が何個あるか
    set<int> se;  // 0 以上 N 以下の整数のうち、 A に含まれない数の集合
    for (int i = 0; i <= N; ++i) se.insert(i);
    for (int i = 0; i < N; ++i) {
        ++ma[A[i]];
        se.erase(A[i]);
    }
    
    // A の中から値 x を 1 個削除
    auto del = [&](int x) -> void {
        --ma[x];
        if (ma[x] == 0) se.insert(x);
    };
    
    // A に値 x を 1 個挿入
    auto ins = [&](int x) -> void {
        if (ma[x] == 0) se.erase(x);
        ++ma[x];
    };
            
    // クエリ処理
    while (Q--) {
        int id, x;
        cin >> id >> x;
        --id;
        
        del(A[id]);
        A[id] = x;
        ins(A[id]);
        
        cout << *se.begin() << endl;
    }
}