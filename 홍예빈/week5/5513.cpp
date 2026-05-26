// 정올 5513번 극장 좌석 배치2 - 확률 DP
#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
using namespace std;

long long dp[31][31][4];

int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int N,K;
    cin>>N>>K;

    dp[0][0][0]=1;

    for (int i=0; i<N; i++){
        for (int j=0; j<=K; j++){
            for (int mask=0; mask<4; mask++){
                long long cur=dp[i][j][mask];

                if(cur==0) continue;
                {
                    int nmask=((mask<<1)&3);

                    dp[i+1][j][nmask]+=cur;
                }

                if (j<K){
                    int a=(mask>>1)&1;
                    int b=mask&1;
                    int c=1;

                    if (!(a==1 && b==1 && c==1)){
                        int nmask=((mask<<1)|1)&3;

                        dp[i+1][j+1][nmask]+=cur;
                    }
                }
            }
        }
    }

    long long ans=0;

    for (int mask=0; mask<4; mask++)
        ans+=dp[N][K][mask];

    cout<<ans;

    return 0;
}