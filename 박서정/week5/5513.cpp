// 5513: 극장 좌석 배치 2

#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
using namespace std;

#define MAX 31

int N, K;
long long dp[MAX][MAX][3];

int main(void)
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> N >> K;

    dp[0][0][0] = 1;

    for (int i = 0; i < N; i++)
    {
        for (int j = 0; j <= K; j++)
        {
            for (int c = 0; c <= 2; c++)
            {
                if (dp[i][j][c] == 0)
                {
                    continue;
                }

                dp[i + 1][j][0] += dp[i][j][c];

                if (j + 1 <= K && c < 2)
                {
                    if (!(i + 1 == 2 && c == 1))
                    {
                        dp[i + 1][j + 1][c + 1] += dp[i][j][c];
                    }
                }
            }
        }
    }

    cout << dp[N][K][0] + dp[N][K][1];

    return 0;
}