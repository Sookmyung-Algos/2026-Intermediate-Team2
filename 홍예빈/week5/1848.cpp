// 정올 1848번 극장 좌석 - 확률 DP
#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
using namespace std;

#define MAX 41
int dp[MAX];

int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int N,M;
    cin >> N;
    cin >> M;

    dp[0]=1;
    dp[1]=1;

    for (int i=2; i<=N; i++){
        dp[i]=dp[i-1]+dp[i-2];
    }

    int answer=1;

    int prev=0;

    for (int i=0; i<M; i++){
        int vip;
        cin >> vip;

        int len=vip-prev-1;

        answer*=dp[len];

        prev=vip;
    }

    answer*=dp[N-prev];

    cout << answer;

    return 0;
}