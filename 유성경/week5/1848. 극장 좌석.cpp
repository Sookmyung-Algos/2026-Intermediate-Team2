#if 0
#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
using namespace std;

int N;
int M;
int vip[41];
int dp[41];

int main(void)
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> N;
    cin >> M;

    dp[0] = 1;
    dp[1] = 1;

    for (int i = 2; i <= 40; i++)
    {
        dp[i] = dp[i - 1] + dp[i - 2];
    }

    for (int i = 0; i < M; i++)
    {
        cin >> vip[i];
    }

    int ans = 1;
    int prev = 0;

    for (int i = 0; i < M; i++)
    {
        int len = vip[i] - prev - 1;
        ans *= dp[len];
        prev = vip[i];
    }

    ans *= dp[N - prev];

    cout << ans;

    return 0;
}
#endif