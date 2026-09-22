#include <iostream>
#include <queue>
#include <vector>
#include <algorithm>
using namespace std;

int rowSize, colSize;
vector<string> board;

int dr[4] = {-1, 1, 0, 0};
int dc[4] = {0, 0, -1, 1};

int bfs(int startRow, int startCol) {
    vector<vector<int>> dist(rowSize, vector<int>(colSize, -1));
    queue<pair<int, int>> q;

    q.push({startRow, startCol});
    dist[startRow][startCol] = 0;

    int maxDistance = 0;

    while (!q.empty()) {
        int currentRow = q.front().first;
        int currentCol = q.front().second;
        q.pop();

        for (int direction = 0; direction < 4; direction++) {
            int nextRow = currentRow + dr[direction];
            int nextCol = currentCol + dc[direction];

            if (nextRow < 0 || nextRow >= rowSize ||
                nextCol < 0 || nextCol >= colSize) {
                continue;
            }

            if (board[nextRow][nextCol] == 'W' ||
                dist[nextRow][nextCol] != -1) {
                continue;
            }

            dist[nextRow][nextCol] = dist[currentRow][currentCol] + 1;
            maxDistance = max(maxDistance, dist[nextRow][nextCol]);

            q.push({nextRow, nextCol});
        }
    }

    return maxDistance;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> rowSize >> colSize;

    board.resize(rowSize);

    for (int row = 0; row < rowSize; row++) {
        cin >> board[row];
    }

    int answer = 0;

    for (int row = 0; row < rowSize; row++) {
        for (int col = 0; col < colSize; col++) {
            if (board[row][col] == 'L') {
                answer = max(answer, bfs(row, col));
            }
        }
    }

    cout << answer << '\n';

    return 0;
}