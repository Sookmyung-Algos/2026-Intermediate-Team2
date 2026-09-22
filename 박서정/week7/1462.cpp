#include <bits/stdc++.h>
using namespace std;

int R, C, ans;
char a[51][51];
int dista[51][51];
int dr[] = { -1, 1, 0, 0 };
int dc[] = { 0, 0, -1, 1 };

void bfs(int sr, int sc) {
    memset(dista, -1, sizeof(dista));

    queue<pair<int, int>> q;
    q.push({ sr, sc });
    dista[sr][sc] = 0;

    while (!q.empty()) {
        auto [r, c] = q.front();
        q.pop();

        ans = max(ans, dista[r][c]);

        for (int d = 0; d < 4; d++) {
            int nr = r + dr[d];
            int nc = c + dc[d];

            if (nr < 0 || nr >= R || nc < 0 || nc >= C) continue;
            if (a[nr][nc] != 'L') continue;
            if (dista[nr][nc] != -1) continue;

            dista[nr][nc] = dista[r][c] + 1;
            q.push({ nr, nc });
        }
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> R >> C;

    for (int i = 0; i < R; i++)
        cin >> a[i];

    for (int i = 0; i < R; i++)
        for (int j = 0; j < C; j++)
            if (a[i][j] == 'L')
                bfs(i, j);

    cout << ans;
}