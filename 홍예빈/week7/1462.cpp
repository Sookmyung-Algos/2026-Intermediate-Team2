// 정올 1462 : 보물섬
#include <iostream>
#include <vector>
#include <string>
#include <queue>
#include <algorithm>

using namespace std;

int R, C;
vector<string> grid;

// 상, 하, 좌, 우 이동을 위한 배열
int dx[4] = {-1, 1, 0, 0};
int dy[4] = {0, 0, -1, 1};

// 특정 (sx, sy) 육지에서 출발하여 도달할 수 있는 가장 먼 거리를 반환하는 BFS 함수
int bfs(int sx, int sy) {
    // 방문 여부 및 이동 거리를 저장하는 2차원 배열 (-1로 초기화)
    vector<vector<int>> dist(R, vector<int>(C, -1));
    queue<pair<int, int>> q;

    q.push({sx, sy});
    dist[sx][sy] = 0;

    int max_d = 0;

    while (!q.empty()) {
        auto [x, y] = q.front();
        q.pop();

        for (int i = 0; i < 4; i++) {
            int nx = x + dx[i];
            int ny = y + dy[i];

            // 지도를 벗어나지 않고, 육지('L')이며, 아직 방문하지 않은 경우
            if (nx >= 0 && nx < R && ny >= 0 && ny < C) {
                if (grid[nx][ny] == 'L' && dist[nx][ny] == -1) {
                    dist[nx][ny] = dist[x][y] + 1;
                    max_d = max(max_d, dist[nx][ny]);
                    q.push({nx, ny});
                }
            }
        }
    }

    return max_d;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> R >> C;
    grid.resize(R);

    for (int i = 0; i < R; i++) {
        cin >> grid[i];
    }

    int answer = 0;

    // 모든 육지('L') 칸을 시작점으로 하여 BFS 수행
    for (int i = 0; i < R; i++) {
        for (int j = 0; j < C; j++) {
            if (grid[i][j] == 'L') {
                answer = max(answer, bfs(i, j));
            }
        }
    }

    cout << answer << "\n";

    return 0;
}