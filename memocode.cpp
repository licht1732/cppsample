#include <bits/stdc++.h>
using namespace std;

//多倍長整数用
#include<boost/multiprecision/cpp_int.hpp>
using namespace boost::multiprecision;

cpp_int h;

//Era(n)を呼んだ後、isprime[i]=iが素数かどうか　となっている。
vector < bool > isprime;
//返り値は素数のリスト。
vector <long long> Era(int n) {
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
    int n;
    cin >> n;
    vector<vector<int>> v(n,vector<int>,n);//多次元配列宣言
    //要素二つをsortしたいときのsort方法(pairで普通にsortした方がいいかも)
    std::sort(data.begin(), data.end(), [](const std::pair<int, int>& a, const std::pair<int, int>& b) {
        if (a.first != b.first) {
            return a.first < b.first; // 第1キーで昇順ソート
        }
        return a.second > b.second; // 第2キーで降順ソート
    });
    //pairいろいろ
    vector<pair<int,int> p(n);
    for(int i=0;i<n;i++){
        int a,b;
        cin >> a >> b;
        p[i]=make_pair(a,b);
    }
    sort(p.begin().p.end());//1つ目の要素からsortされる
    for(auto pp:p){
        cout << pp.first << " " << pp.second;
    }
    //二分探索
    lower_bound(v.begin(),v.end(),x);//x以上の最小の要素
    upper_bound(v.begin(),v.end(),x);//xを越える最小の要素
    
    //二分探索で見つけた配列番号の探し方
    lower_bound(a.begin(),a.end(),x)-a.begin();//先頭からの距離
    a.end()-lower_bound(a.begin(),a.end(),x);  //末尾までの距離
    upper_bound(a.begin(),a.end(),x)-a.begin()-1;//先頭からの距離(xを超えてほしくないとき)

    //イテレータ使ってeraseや二分探索結果の値の検索
    //配列のeraseしたいときはその配列をmultisetに入れておいてこれやれ
    auto index=ms.lower_bound(a[i]);
    if(index==ms.end()){
        cout << -1 << endl;
        return 0;
    }
    ans+=*index;
    ms.erase(index);

    //bit全探索
    for (int bit=0; bit<(1<<n); bit++){
        vector<int> use(n, 0);
        for (int j=0; j<n; j++){
            if (bit & (1<<j)) use[j]=1;
        }
        // useは[0, 0, 1]のような(各行のどれか)が作成できる
        // useを使った何らかの処理
        for(int j=0;j<n;j++){
            if(use[j]==1){
                //その配列番号使う時の処理
            }
        }
        //一つ探索終わった時の処理を書く
    }

    s.substr(s.size()-x);//sの後ろからx文字取ってくる
    s.substr(0,3);//0文字目から3文字取ってくる

    llabs(a,b); //long longの時はこっちの方が安全かも？

    popcount(a);//aを2進数表記した時のqの数をカウント
}