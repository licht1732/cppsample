#include <bits/stdc++.h>
using namespace std;

int main(){
    int n, q;
    cin >> n >> q;

    vector<long long> x(n), y(n);
    for(int i = 0; i < n; i++){
        cin >> x[i] >> y[i];
    }

    long long Amax = LLONG_MIN, Amin = LLONG_MAX;
    long long Bmax = LLONG_MIN, Bmin = LLONG_MAX;

    for(int i = 0; i < n; i++){
        long long A = x[i] + y[i];
        long long B = x[i] - y[i];
        Amax = max(Amax, A);
        Amin = min(Amin, A);
        Bmax = max(Bmax, B);
        Bmin = min(Bmin, B);
    }

    while(q--){
        int que;
        cin >> que;
        que--;

        long long A = x[que] + y[que];
        long long B = x[que] - y[que];

        long long ans = 0;
        ans = max(ans, llabs(A - Amax));
        ans = max(ans, llabs(A - Amin));
        ans = max(ans, llabs(B - Bmax));
        ans = max(ans, llabs(B - Bmin));

        cout << ans << endl;
    }
}
