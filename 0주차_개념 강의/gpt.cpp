#include<bits/stdc++.h>
using namespace std;


int mp[101][101];
int visited[101][101];
int dy[] = {-1, 0, 1, 0};
int dx[] = {0, 1, 0, -1};
int M, N, K;

int dfs(int y, int x) {
    visited[y][x] = 1;
    int cnt = 1;

    for (int i = 0; i < 4; i++) {
        int ny = y + dy[i];
        int nx = x + dx[i];

        if (ny < 0 || nx < 0 || ny >= M || nx >= N || mp[ny][nx] == 1) continue;
        if (visited[ny][nx]) continue;

        cnt += dfs(ny, nx);
    }

    return cnt;
}

int main() {
    cin >> M >> N >> K;

    for (int i = 0; i < K; i++) {
        int x1, y1, x2, y2;
        cin >> x1 >> y1 >> x2 >> y2;

        for (int x = x1; x < x2; x++) {
            for (int y = y1; y < y2; y++) {
                mp[y][x] = 1;
            }
        }
    }

    vector<int> ret;

    for (int i = 0; i < M; i++) {
        for (int j = 0; j < N; j++) {
            if (mp[i][j] == 0 && !visited[i][j]) {
                ret.push_back(dfs(i, j));
            }
        }
    }

    sort(ret.begin(), ret.end());

    cout << ret.size() << "\n";
    for (int i : ret) {
        cout << i << " ";
    }
    cout << "\n";

    return 0;
}
