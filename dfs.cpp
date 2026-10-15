#include <bits/stdc++.h>
using namespace std;

int main() {
    int H, W, K;
    cin >> H >> W >> K;
    vector<vector<char>> S(H, vector<char>(W));
    for (int i = 0; i < H; i++) {
        for (int j = 0; j < W; j++) {
            cin >> S[i][j];
        }
    }

    int ans = 0;
    vector<vector<bool>> visited(H, vector<bool>(W, false));
    const int dx[4] = {1, -1, 0, 0};
    const int dy[4] = {0, 0, 1, -1};

    //経路全探索
    auto dfs = [&](auto&& dfs, int y, int x, int d) -> void {
        if (d == K) {
            ans++;
            return;
        }
        visited[y][x] = true;
        for (int dir = 0; dir < 4; dir++) {
            int ny = y + dy[dir];
            int nx = x + dx[dir];
            if (ny < 0 || ny >= H || nx < 0 || nx >= W) continue;
            if (S[ny][nx] == '#' || visited[ny][nx]) continue;
            dfs(dfs, ny, nx, d + 1);
        }
        visited[y][x] = false;
    };

    //1つのパスを探索
    auto dfs = [&](auto&&dfs,int now) -> bool {
        visited[now]=true;
        ans.push_back(now);
        if(now==y){
          for(auto c : ans){
            cout << c << " ";
          }
          cout << endl;
          return true;
        }
        for(auto next : g[now]){
          if(!visited[next]){
            if(dfs(dfs,next)){
              return true;
            }
            ans.pop_back();
          }
        }
        return false;
      };

    int n;
    vector<bool> visited_node(n);
    
    //グラフの単純パス全探索
    auto dfs = [&](auto&& dfs, int idx) -> void {
        visited[idx] = true;
        ans++;
        //計算量削減のために最大値を超えた時に打ち切り
        if(ans>=1e6){
            ans=min(ans,(int)1e6);
            return;
        }
        for (auto next : g[idx]) {
            if (visited_node[next]) continue;
            dfs(dfs, next);
        }
        visited[idx] = false;
    };

    for (int i = 0; i < H; i++) {
        for (int j = 0; j < W; j++) {
            if (S[i][j] == '.') {
                dfs(dfs, i, j, 0);
            }
        }
    }

    //サイクル検出
    vector<int> his;
    auto dfs = [&](auto&&dfs,int now) -> void {
        visited[now]++;
        his.push_back(now);
        for(auto nxt : g[now]){
            if(visited[nxt]==1 && his[his.size()-2]!=nxt){
                l.insert({min(now,nxt),max(now,nxt)});
                for(int i=his.size()-1;i>=1;i--){
                    if(his[i]==nxt) break;
                    int a=min(his[i],his[i-1]),b=max(his[i],his[i-1]);
                    l.insert({a,b});
                }
            }
            if(!visited[nxt]){
                dfs(dfs,nxt);
            }
        }
        visited[now]++;
        his.pop_back();
    };

    cout << ans << endl;
}
