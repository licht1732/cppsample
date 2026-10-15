#include <bits/stdc++.h>
using namespace std;

using ll = long long;
const ll MOD = 1e9+7;

int main() {
    string K;
    int D;
    cin >> K >> D;

    int n = K.size();
    
    //dp[桁数][今がその桁の上限の数か][状態]
    vector<vector<vector<ll>>> dp(n+1, vector(2, vector<ll>(D, 0)));

    dp[0][1][0] = 1;

    for (int pos = 0; pos < n; pos++) {
        int digit = K[pos] - '0';
        for (int tight = 0; tight <= 1; tight++) {
            for (int mod = 0; mod < D; mod++) {
                ll cur = dp[pos][tight][mod];
                if (cur == 0) continue;

                int limit = tight ? digit : 9;

                for (int d = 0; d <= limit; d++) {
                    int ntight = tight && (d == digit);
                    int nmod = (mod + d) % D;

                    dp[pos+1][ntight][nmod] += cur;
                    dp[pos+1][ntight][nmod] %= MOD;
                }
            }
        }
    }

    ll ans = (dp[n][0][0] + dp[n][1][0] - 1) % MOD;
    if (ans < 0) ans += MOD;

    cout << ans << endl;
}