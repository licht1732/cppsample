#include <bits/stdc++.h>
using namespace std;

int main() {
    int H, W, N;
    cin >> H >> W >> N;

    vector<vector<int>> imos(H+1, vector<int>(W+1, 0));

    for (int i = 0; i < N; i++) {
        int A, B, C, D;
        cin >> A >> B >> C >> D;

        // 0-index に変換(座標の場合いらない下の+1もいらない)
        A--; B--; C--; D--;

        imos[A][B]++;
        imos[A][D+1]--;
        imos[C+1][B]--;
        imos[C+1][D+1]++;
    }

    // 横方向の累積和
    for (int i = 0; i < H; i++) {
        for (int j = 1; j < W; j++) {
            imos[i][j] += imos[i][j-1];
        }
    }

    // 縦方向の累積和
    for (int j = 0; j < W; j++) {
        for (int i = 1; i < H; i++) {
            imos[i][j] += imos[i-1][j];
        }
    }

    // 出力
    for (int i = 0; i < H; i++) {
        for (int j = 0; j < W; j++) {
            cout << imos[i][j] << " ";
        }
        cout << "\n";
    }
}
