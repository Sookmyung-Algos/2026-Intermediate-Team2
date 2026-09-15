// 코드포스 1006F - Xor-Paths
#include <iostream>
#include <vector>
#include <map>

using namespace std;

int n, m;
long long k;
long long grid[20][20];
long long ans = 0;
int half;

// (r, c) 좌표에 도착했을 때 만들어진 XOR 값을 카운트하는 해시맵
map<long long, long long> path_count[20][20];

// Step 1: (0,0)에서 출발하여 half번 이동하는 정방향 DFS
void dfs_left(int r, int c, long long current_xor, int steps) {
    current_xor ^= grid[r][c];

    // 정확히 half번 이동했다면 해시맵에 저장 후 종료
    if (steps == half) {
        path_count[r][c][current_xor]++;
        return;
    }

    // 아래쪽 이동
    if (r + 1 < n) {
        dfs_left(r + 1, c, current_xor, steps + 1);
    }
    // 오른쪽 이동
    if (c + 1 < m) {
        dfs_left(r, c + 1, current_xor, steps + 1);
    }
}

// Step 2: (n-1, m-1)에서 출발하여 역방향으로 중간 지점까지 탐색하는 DFS
void dfs_right(int r, int c, long long current_xor, int steps) {
    // 이동 횟수가 (n + m - 2 - half)에 도달하면 중간 지점
    if (steps == (n + m - 2 - half)) {
        // 경로 상 중복되는 중간 칸 grid[r][c]를 제외하고 비교하기 위해 미리 xor 처리
        long long target_xor = k ^ current_xor;
        
        if (path_count[r][c].count(target_xor)) {
            ans += path_count[r][c][target_xor];
        }
        return;
    }

    current_xor ^= grid[r][c];

    // 위쪽 이동 (역추적)
    if (r - 1 >= 0) {
        dfs_right(r - 1, c, current_xor, steps + 1);
    }
    // 왼쪽 이동 (역추적)
    if (c - 1 >= 0) {
        dfs_right(r, c - 1, current_xor, steps + 1);
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> n >> m >> k;

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            cin >> grid[i][j];
        }
    }

    // 탐색을 반으로 나눌 기준 이동 횟수
    half = (n + m - 2) / 2;

    // 1. (0,0) 시작 DFS
    dfs_left(0, 0, 0, 0);

    // 2. (n-1, m-1) 시작 역방향 DFS
    dfs_right(n - 1, m - 1, 0, 0);

    cout << ans << "\n";

    return 0;
}