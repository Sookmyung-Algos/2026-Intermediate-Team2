// 1848: ±ÿ¿Â ¡¬ºÆ

#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
using namespace std;

#define MAX 41

int N, M;
int vip[MAX];
int dp[MAX];
int answer;

int main(void)
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> N;
    cin >> M;

    for (int i = 1; i <= M; i++)
    {
        cin >> vip[i];
    }

    dp[0] = 1;
    dp[1] = 1;

    for (int i = 2; i <= N; i++)
    {
        dp[i] = dp[i - 1] + dp[i - 2];
    }

    answer = 1;

    int prev = 0;

    for (int i = 1; i <= M; i++)
    {
        answer *= dp[vip[i] - prev - 1];
        prev = vip[i];
    }

    answer *= dp[N - prev];

    cout << answer;

    return 0;
}