// 정올 1520번 계단 오르기 - 확률 DP
#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <algorithm>
using namespace std;

#define MAX 301

int N;
int stair[MAX];
int dp[MAX];

int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> N;

    for (int i=1; i<=N; i++)
        cin >> stair[i];

    dp[1]=stair[1];

    if(N>=2)
        dp[2]=stair[1]+stair[2];

    for (int i=3; i<=N; i++){
        dp[i]=max(
            dp[i-2]+stair[i],
            dp[i-3]+stair[i-1]+stair[i]
        );
    }

    cout << dp[N];

    return 0;
}