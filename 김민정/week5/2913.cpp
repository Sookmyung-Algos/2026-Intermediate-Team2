#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int N;
    cin >> N;

    vector<int> leftCard(N + 1), rightCard(N + 1);

    for (int i = 0; i < N; i++) {
        cin >> leftCard[i];
    }

    for (int i = 0; i < N; i++) {
        cin >> rightCard[i];
    }

    vector<vector<int>> dp(N + 1, vector<int>(N + 1, 0));

    for (int i = N - 1; i >= 0; i--) {
        for (int j = N - 1; j >= 0; j--) {
            dp[i][j] = max(dp[i + 1][j], dp[i + 1][j + 1]);

            if (rightCard[j] < leftCard[i]) {
                dp[i][j] = max(dp[i][j], dp[i][j + 1] + rightCard[j]);
            }
        }
    }

    cout << dp[0][0] << '\n';

    return 0;
}
