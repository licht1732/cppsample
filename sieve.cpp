#include <bits/stdc++.h>
using namespace std;

vector <bool> isprime;

vector <long long> Era(long long n) {
	isprime.resize(n, true);
	vector <long long> res;
	isprime[0] = false;
	isprime[1] = false;
	for(long long i = 2; i < n; ++i) isprime[i] = true;
	for(long long i = 2; i < n; ++i) {
		if(isprime[i]) {
			res.push_back(i);
			for(long long j = i * 2; j < n; j += i) isprime[j] = false;
		}
	}
	return res;
}

int main() {
    long long l,r;
    cin >> l >> r;

    vector<long long> primes=Era(sqrt(r)+1);

    vector<bool> sisprime(r-l+1,true);

    for(auto p : primes){
        long long s=max(p*p, ((l+p-1)/p)*p);
        for(long long j=s;j<=r;j+=p){
            sisprime[j-l]=false;
        }
    }

    if(l==1) sisprime[0]=false;

    int cnt=0;
    for(bool x : sisprime) if(x) cnt++;

    cout << cnt << endl;
}