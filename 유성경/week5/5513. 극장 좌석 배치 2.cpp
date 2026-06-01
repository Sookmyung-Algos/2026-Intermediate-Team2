#if 0
#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <vector>
using namespace std;

int main() 
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int N, K;
    if (!(cin >> N >> K)) return 0;

    vector<vector<vector<long long>>> dp(N + 1, vector<vector<long long>>(K + 1, vector<long long>(3, 0)));

    dp[1][0][0] = 1;

    if (K >= 1) 
    {
        dp[1][1][1] = 1; 
    }

    for (int i = 2; i <= N; ++i) 
    {
        for (int j = 0; j <= K; ++j)
        {
            dp[i][j][0] = dp[i - 1][j][0] + dp[i - 1][j][1] + dp[i - 1][j][2];

            if (j > 0) 
            {
                dp[i][j][1] = dp[i - 1][j - 1][0];

                if (i == 2)
                {
                    dp[i][j][2] = 0;
                }
                else
                {
                    dp[i][j][2] = dp[i - 1][j - 1][1];
                }
            }
        }
    }

    long long answer = dp[N][K][0] + dp[N][K][1];
    cout << answer << "\n";

    return 0;
}
#endif