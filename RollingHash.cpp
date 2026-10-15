#include <bits/stdc++.h>
using namespace std;
using ll = long long;

struct RollingHash {
    static const ll mod1 = 1000000007;
    static const ll mod2 = 1000000009;
    static const ll base = 1007;
    vector<ll> hash1, hash2, pow1, pow2;

    RollingHash(const string &s) {
        int n = s.size();
        hash1.assign(n + 1, 0);
        hash2.assign(n + 1, 0);
        pow1.assign(n + 1, 1);
        pow2.assign(n + 1, 1);
        for (int i = 0; i < n; i++) {
            hash1[i + 1] = (hash1[i] * base + s[i]) % mod1;
            hash2[i + 1] = (hash2[i] * base + s[i]) % mod2;
            pow1[i + 1] = (pow1[i] * base) % mod1;
            pow2[i + 1] = (pow2[i] * base) % mod2;
        }
    }

    pair<ll, ll> get(int l, int r) const {
        ll res1 = (hash1[r] - hash1[l] * pow1[r - l]) % mod1;
        ll res2 = (hash2[r] - hash2[l] * pow2[r - l]) % mod2;
        if (res1 < 0) res1 += mod1;
        if (res2 < 0) res2 += mod2;
        return {res1, res2};
    }
};

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    
    int T;
    cin >> T;
    while (T--) {
        string A, B;
        cin >> A >> B;
        int n = A.size();

        string A2 = A + A;
        RollingHash rhA(A2), rhB(B);
        auto hB = rhB.get(0, n);

        int ans = -1;
        for (int i = 0; i < n; i++) {
            if (rhA.get(i, i + n) == hB) {
                ans = i;
                break;
            }
        }
        cout << ans << "\n";
    }
}
