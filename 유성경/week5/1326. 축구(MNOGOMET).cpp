#if 0
#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <vector>
#include <map>
#include <algorithm>
#include <iomanip>
#include <cstring>
using namespace std;

int N, R, T;

struct Player
{
    double acc;
    int nF, nE;
    vector<int> F, E;
};

Player players[2][101];

double dp[2][101][11][11];
double ndp[2][101][11][11];

int main(void)
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> N >> R >> T;

    for (int team = 0; team < 2; team++)
    {
        for (int i = 0; i < N; i++)
        {
            cin >> players[team][i].acc >> players[team][i].nF >> players[team][i].nE;
            players[team][i].F.resize(players[team][i].nF);
            players[team][i].E.resize(players[team][i].nE);
            for (int j = 0; j < players[team][i].nF; j++)
            {
                cin >> players[team][i].F[j];
                players[team][i].F[j]--;
            }
            for (int j = 0; j < players[team][i].nE; j++)
            {
                cin >> players[team][i].E[j];
                players[team][i].E[j]--;
            }
        }
    }

    int maxS = R + 1;

    // ¸ðµç °¡´ÉÇÑ score¸¦ 0À¸·Î ÃÊ±âÈ­
    // (s0==R, s1 in 0..R-1), (s1==R, s0 in 0..R-1), (s0<R, s1<R)
    map<pair<int, int>, double> result;
    for (int s0 = 0; s0 < R; s0++)
        result[make_pair(s0, R)] = 0.0;
    for (int s1 = 0; s1 < R; s1++)
        result[make_pair(R, s1)] = 0.0;
    for (int s0 = 0; s0 < R; s0++)
        for (int s1 = 0; s1 < R; s1++)
            result[make_pair(s0, s1)] = 0.0;

    memset(dp, 0, sizeof(dp));
    dp[0][0][0][0] = 1.0;

    for (int t = 0; t < T; t++)
    {
        memset(ndp, 0, sizeof(ndp));

        for (int tm = 0; tm < 2; tm++)
        {
            for (int pi = 0; pi < N; pi++)
            {
                for (int s0 = 0; s0 < maxS; s0++)
                {
                    for (int s1 = 0; s1 < maxS; s1++)
                    {
                        double prob = dp[tm][pi][s0][s1];
                        if (prob < 1e-18) continue;

                        Player& p = players[tm][pi];
                        int nF = p.nF, nE = p.nE;
                        double total = nF + nE + 1.0;
                        double pF = nF / total;
                        double pE = nE / total;
                        double pS = 1.0 / total;
                        int oppTm = 1 - tm;

                        // F: ÆÐ½º
                        if (nF > 0)
                        {
                            double each = pF / nF;
                            for (int i = 0; i < (int)p.F.size(); i++)
                            {
                                ndp[tm][p.F[i]][s0][s1] += prob * each;
                            }
                        }

                        // E: »©¾Ñ±è
                        if (nE > 0)
                        {
                            double each = pE / nE;
                            for (int i = 0; i < (int)p.E.size(); i++)
                            {
                                ndp[oppTm][p.E[i]][s0][s1] += prob * each;
                            }
                        }

                        // S: ½¸
                        double hitP = p.acc * pS;
                        double missP = (1.0 - p.acc) * pS;

                        // ½¸ ½ÇÆÐ: »ó´ëÆÀ 1¹ø ¼±¼ö¿¡°Ô
                        ndp[oppTm][0][s0][s1] += prob * missP;

                        // ½¸ ¼º°ø: Á¡¼ö Áõ°¡
                        int ns0 = s0, ns1 = s1;
                        if (tm == 0) ns0++;
                        else ns1++;

                        if (ns0 >= R || ns1 >= R)
                        {
                            result[make_pair(min(ns0, R), min(ns1, R))] += prob * hitP;
                        }
                        else
                        {
                            ndp[oppTm][0][ns0][ns1] += prob * hitP;
                        }
                    }
                }
            }
        }

        if (t + 1 == T)
        {
            for (int tm = 0; tm < 2; tm++)
                for (int pi = 0; pi < N; pi++)
                    for (int s0 = 0; s0 < maxS; s0++)
                        for (int s1 = 0; s1 < maxS; s1++)
                            if (ndp[tm][pi][s0][s1] > 1e-18)
                                result[make_pair(s0, s1)] += ndp[tm][pi][s0][s1];
        }
        else
        {
            memcpy(dp, ndp, sizeof(dp));
        }
    }

    vector<pair<pair<int, int>, double> > res(result.begin(), result.end());
    sort(res.begin(), res.end());

    cout << fixed << setprecision(10);
    for (int i = 0; i < (int)res.size(); i++)
    {
        cout << res[i].second << "\n";
    }

    return 0;
}
#endif