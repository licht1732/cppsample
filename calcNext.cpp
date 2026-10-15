#include <iostream>
#include <vector>
#include <string>
using namespace std;

// res[i][c] := i 文字目以降で最初に文字 c が登場する index
// 存在しないときは N
vector<vector<int> > calc_next(const string &S) {
    // 文字列 S の長さ
    int N = (int)S.size();

    // 答え
    vector<vector<int> > res(N + 1, vector<int>(26, N));

    // 後ろから見る
    for (int i = N - 1; i >= 0; --i) {
        // i + 1 文字目以降の結果を一旦 i 文字にコピー
        res[i] = res[i + 1];

        // i 文字目の情報を反映させる
        res[i][S[i] - 'a'] = i;
    }
    return res;
}

int main() {
    // 入力
    int N, K;
    string S;
    cin >> N >> K >> S;
    
    // 前処理
    string res = "";
    auto nex = calc_next(S);

    // 貪欲法
    int j = -1;
    for (int i = 0; i < K; ++i) {
        for (char c = 'a'; c <= 'z'; ++c) {
            int k = nex[j + 1][c - 'a'];

            // ちゃんと K 文字が作れれば OK
            if (N - k >= K - i) {
                res += c;
                j = k;
                break;
            }
        }
    }
    cout << res << endl;
}