// 정올 2913번 카드게임 - 확률 DP
#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <algorithm>
using namespace std;

#define MAX 2001

int N;
int leftCard[MAX];
int rightCard[MAX];
int dp[MAX][MAX];

int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> N;

    for (int i=0; i<N; i++)
        cin >> leftCard[i];

    for (int i=0; i<N; i++)
        cin >> rightCard[i];

    for (int i=N-1; i>=0; i--){
        for (int j=N-1; j>=0; j--){
            dp[i][j]=max(
                dp[i+1][j],
                dp[i+1][j+1]
            );

            if (leftCard[i] > rightCard[j]){
                dp[i][j]=max(
                    dp[i][j],
                    dp[i][j+1]+rightCard[j]
                );
            }
        }
    }

    cout << dp[0][0];

    return 0;
}