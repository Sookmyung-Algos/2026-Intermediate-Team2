#include <iostream>
#include <unordered_map>
using namespace std;

using ll = long long;

int n, m;
int totalMoves, halfMoves;

ll k;
ll board[20][20];
ll answer = 0;

unordered_map<ll, ll> middle[20][20];

void dfsFromStart(int row, int col, int moves, ll xorValue) {
    if (moves == halfMoves) {
        middle[row][col][xorValue]++;
        return;
    }

    if (row + 1 < n) {
        dfsFromStart(
            row + 1,
            col,
            moves + 1,
            xorValue ^ board[row + 1][col]
        );
    }

    if (col + 1 < m) {
        dfsFromStart(
            row,
            col + 1,
            moves + 1,
            xorValue ^ board[row][col + 1]
        );
    }
}

void dfsFromEnd(int row, int col, int moves, ll xorValue) {
    if (moves == totalMoves - halfMoves) {
        // startXor ^ endXor ^ middleCell = k
        ll requiredStartXor =
            k ^ xorValue ^ board[row][col];

        auto it = middle[row][col].find(requiredStartXor);

        if (it != middle[row][col].end()) {
            answer += it->second;
        }

        return;
    }

    if (row - 1 >= 0) {
        dfsFromEnd(
            row - 1,
            col,
            moves + 1,
            xorValue ^ board[row - 1][col]
        );
    }

    if (col - 1 >= 0) {
        dfsFromEnd(
            row,
            col - 1,
            moves + 1,
            xorValue ^ board[row][col - 1]
        );
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> n >> m >> k;

    for (int row = 0; row < n; row++) {
        for (int col = 0; col < m; col++) {
            cin >> board[row][col];
        }
    }

    totalMoves = n + m - 2;
    halfMoves = totalMoves / 2;

    dfsFromStart(0, 0, 0, board[0][0]);


    dfsFromEnd(
        n - 1,
        m - 1,
        0,
        board[n - 1][m - 1]
    );

    cout << answer << '\n';

    return 0;
}