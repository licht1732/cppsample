#include <bits/stdc++.h>
using namespace std;

int main() {
    int n;
    cin >> n;
    vector<int> a(n);
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }

    //長さのみ
    vector<int> dp;

    for (int i = 0; i < n; i++) {
        auto it = lower_bound(dp.begin(), dp.end(), a[i]);
        if (it == dp.end()) {
            dp.push_back(a[i]);
        } else {
            *it = a[i];
        }
    }

    cout << dp.size() << endl;
    

    //復元したい場合
    vector<int> dp_val;   // 末尾の値
    vector<int> dp_idx;   // その値の元の index
    vector<int> prev(n, -1); // 直前の要素の index

    for (int i = 0; i < n; i++) {
        // dp_val の中で a[i] 以上の最初の位置
        auto it = lower_bound(dp_val.begin(), dp_val.end(), a[i]);
        int pos = it - dp_val.begin();

        if (it == dp_val.end()) {
            dp_val.push_back(a[i]);
            dp_idx.push_back(i);
        } else {
            dp_val[pos] = a[i];
            dp_idx[pos] = i;
        }

        // 1つ前につながる要素を記録
        if (pos > 0) {
            prev[i] = dp_idx[pos - 1];
        }
    }

    // --- 復元 ---
    vector<int> lis;
    int cur = dp_idx.back(); // LIS の最後の要素の index
    while (cur != -1) {
        lis.push_back(a[cur]);
        cur = prev[cur];
    }
    reverse(lis.begin(), lis.end());

    // 出力
    cout << "LIS length = " << lis.size() << endl;
    for (int x : lis) {
        cout << x << " ";
    }
    cout << endl;
}
