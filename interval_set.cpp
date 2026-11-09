#include <bits/stdc++.h>
using namespace std;

using ll = long long;

set<pair<ll, ll>> intervals;
ll interval_count=0;

void add_interval(ll l, ll r) {
    auto it = intervals.lower_bound({l, LLONG_MIN});

    // 左隣が重なっていれば、そこから処理する
    if (it != intervals.begin()) {
        auto left = prev(it);
        if (left->second >= l) {
            it = left;
        }
    }

    while (it != intervals.end() && it->first <= r) {
        // 削除する区間の分を引く
        interval_count -= it->second - it->first + 1;

        l = min(l, it->first);
        r = max(r, it->second);
        it = intervals.erase(it);
    }

    intervals.insert({l, r});

    // 結合後の区間の分を足す
    interval_count += r - l + 1;
}

int main() {
    ll n;
    int Q;
    cin >> n >> Q;

    while (Q--) {
        ll l, r;
        cin >> l >> r;

        add_interval(l, r);
        cout << n-interval_count << endl;
    }
}