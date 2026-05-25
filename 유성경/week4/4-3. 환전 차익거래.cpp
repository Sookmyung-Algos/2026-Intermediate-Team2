#if 0
#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <vector>
#include <cmath>
using namespace std;

const double INF = 1e18;

struct Edge
{
    int u;
    int v;
    double w;
};

int main(void)
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int N, M;
    cin >> N >> M;

    vector<Edge> edges(M);
    for (int i = 0; i < M; ++i)
    {
        double r;
        cin >> edges[i].u >> edges[i].v >> r;
        edges[i].w = -log(r);
    }

    vector<double> dist(N + 1, INF);
    dist[1] = 0.0;

    bool possible = false;

    for (int i = 1; i <= N; ++i)
    {
        for (int j = 0; j < M; ++j)
        {
            int u = edges[j].u;
            int v = edges[j].v;
            double w = edges[j].w;

            if (dist[u] != INF && dist[v] > dist[u] + w + 1e-9)
            {
                dist[v] = dist[u] + w;

                if (i == N)
                {
                    possible = true;
                }
            }
        }
    }

    if (possible)
    {
        cout << "YES\n";
    }
    else
    {
        cout << "NO\n";
    }

    return 0;
}
#endif