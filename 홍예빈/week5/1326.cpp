// 정올 1326번 축구(MNOGOMET) - 확률 DP
#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <iomanip>
#include <cstring>
using namespace std;

#define MAXN 205
#define MAXR 11

struct Player{
    double acc;
    int nf,ne;
    int F[101];
    int E[101];
};

Player P[MAXN];
double dp[2][MAXR][MAXR][MAXN];

int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int N,R,T;
    cin>>N>>R>>T;

    int M=2*N;

    for (int i=0; i<M; i++){
        cin>>P[i].acc>>P[i].nf>>P[i].ne;

        for (int j=0; j<P[i].nf; j++){
            int x;
            cin>>x;
            --x;

            if(i>=N) x+=N;

            P[i].F[j]=x;
        }

        for (int j=0; j<P[i].ne; j++){
            int x;
            cin>>x;
            --x;

            if(i<N) x+=N;

            P[i].E[j]=x;
        }
    }

    dp[0][0][0][0]=1.0;

    for (int t=0; t<T; t++){
        int cur=t&1;
        int nxt=cur^1;

        memset(dp[nxt],0,sizeof(dp[nxt]));

        for (int s1=0; s1<=R; s1++){
            for (int s2=0; s2<=R; s2++){
                for (int own=0; own<M; own++){
                    double prob=dp[cur][s1][s2][own];

                    if (prob<1e-15) continue;

                    if (s1==R || s2==R){
                        dp[nxt][s1][s2][own]+=prob;
                        continue;
                    }

                    int nf=P[own].nf;
                    int ne=P[own].ne;
                    double den=nf+ne+1.0;

                    for (int k=0; k<nf; k++){
                        int v=P[own].F[k];

                        dp[nxt][s1][s2][v]+=prob/den;
                    }

                    for (int k=0; k<ne; k++){
                        int v=P[own].E[k];

                        dp[nxt][s1][s2][v]+=prob/den;
                    }

                    int nextOwner=(own<N)?N:0;
                    double shoot=prob/den;

                    if (own<N){
                        int ns1=min(R,s1+1);

                        dp[nxt][ns1][s2][nextOwner]
                            += shoot*P[own].acc;
                    }
                    else {
                        int ns2=min(R,s2+1);

                        dp[nxt][s1][ns2][nextOwner]
                            += shoot*P[own].acc;
                    }

                    dp[nxt][s1][s2][nextOwner]
                        += shoot*(1.0-P[own].acc);
                }
            }
        }
    }

    int last=T&1;
    double ans[MAXR][MAXR]={0,};

    for (int s1=0; s1<=R; s1++){
        for (int s2=0; s2<=R; s2++){
            for (int own=0; own<M; own++){
                ans[s1][s2]+=dp[last][s1][s2][own];
            }
        }
    }

    cout<<fixed<<setprecision(6);

    for (int a=0; a<=R; a++){
        for (int b=0; b<=R; b++){
            if (a<R && b<R)
                cout<<ans[a][b]<<"\n";
            else if (a==R || b==R)
                cout<<ans[a][b]<<"\n";
        }
    }
    return 0;
}