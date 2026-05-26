// 1326: √‡±∏(MNOGOMET)

#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <iomanip>
#include <cstring>
using namespace std;

#define MAX_N 101
#define MAX_P 201
#define MAX_R 11
#define MAX_OUT 205

int N, R, T;
int P;

int outCnt[MAX_P];
int outTo[MAX_P][MAX_OUT];
double outProb[MAX_P][MAX_OUT];

double goalProb[MAX_P];
int scoreTeam[MAX_P];
int afterShoot[MAX_P];

double dp[MAX_R][MAX_R][MAX_P];
double nextDp[MAX_R][MAX_R][MAX_P];
double answer[MAX_R][MAX_R];

void addTransition(int from, int to, double prob)
{
    for (int i = 0; i < outCnt[from]; i++)
    {
        if (outTo[from][i] == to)
        {
            outProb[from][i] += prob;
            return;
        }
    }

    outTo[from][outCnt[from]] = to;
    outProb[from][outCnt[from]] = prob;
    outCnt[from]++;
}

void inputPlayer(int team, int idx)
{
    int id = team * N + idx;

    double accuracy;
    int nF, nE;

    cin >> accuracy >> nF >> nE;

    int total = nF + nE + 1;
    double unitProb = 1.0 / total;

    for (int i = 0; i < nF; i++)
    {
        int num;
        cin >> num;

        int target = team * N + (num - 1);
        addTransition(id, target, unitProb);
    }

    for (int i = 0; i < nE; i++)
    {
        int num;
        cin >> num;

        int opponent = 1 - team;
        int target = opponent * N + (num - 1);
        addTransition(id, target, unitProb);
    }

    int opponentFirst = (1 - team) * N;

    addTransition(id, opponentFirst, unitProb * (1.0 - accuracy));

    goalProb[id] = unitProb * accuracy;
    scoreTeam[id] = team;
    afterShoot[id] = opponentFirst;
}

int main(void)
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> N >> R >> T;

    P = 2 * N;

    for (int i = 0; i < N; i++)
    {
        inputPlayer(0, i);
    }

    for (int i = 0; i < N; i++)
    {
        inputPlayer(1, i);
    }

    dp[0][0][0] = 1.0;

    for (int time = 0; time < T; time++)
    {
        memset(nextDp, 0, sizeof(nextDp));

        for (int a = 0; a < R; a++)
        {
            for (int b = 0; b < R; b++)
            {
                for (int p = 0; p < P; p++)
                {
                    double cur = dp[a][b][p];

                    if (cur == 0.0)
                    {
                        continue;
                    }

                    for (int k = 0; k < outCnt[p]; k++)
                    {
                        int nextPlayer = outTo[p][k];
                        double prob = outProb[p][k];

                        nextDp[a][b][nextPlayer] += cur * prob;
                    }

                    double gProb = cur * goalProb[p];

                    if (scoreTeam[p] == 0)
                    {
                        if (a + 1 == R)
                        {
                            answer[R][b] += gProb;
                        }
                        else
                        {
                            nextDp[a + 1][b][afterShoot[p]] += gProb;
                        }
                    }
                    else
                    {
                        if (b + 1 == R)
                        {
                            answer[a][R] += gProb;
                        }
                        else
                        {
                            nextDp[a][b + 1][afterShoot[p]] += gProb;
                        }
                    }
                }
            }
        }

        memcpy(dp, nextDp, sizeof(dp));
    }

    for (int a = 0; a < R; a++)
    {
        for (int b = 0; b < R; b++)
        {
            for (int p = 0; p < P; p++)
            {
                answer[a][b] += dp[a][b][p];
            }
        }
    }

    cout << fixed << setprecision(6);

    for (int a = 0; a <= R; a++)
    {
        for (int b = 0; b <= R; b++)
        {
            if (a == R && b == R)
            {
                continue;
            }

            cout << answer[a][b] << '\n';
        }
    }

    return 0;
}