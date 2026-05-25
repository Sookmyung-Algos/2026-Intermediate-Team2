#if 0
#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <vector>
using namespace std;

const long long INF = 1e18;

struct Edge
{
    int u;
    int v;
    long long w;
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
        cin >> edges[i].u >> edges[i].v >> edges[i].w;
    }

    vector<long long> dist(N + 1, INF);
    dist[1] = 0;

    bool has_minus_cycle = false;

    for (int i = 1; i <= N; ++i)
    {
        for (int j = 0; j < M; ++j)
        {
            int u = edges[j].u;
            int v = edges[j].v;
            long long w = edges[j].w;

            if (dist[u] != INF && dist[v] > dist[u] + w)
            {
                dist[v] = dist[u] + w;

                if (i == N)
                {
                    has_minus_cycle = true;
                }
            }
        }
    }

    if (has_minus_cycle)
    {
        cout << -1 << "\n";
    }
    else
    {
        for (int i = 2; i <= N; ++i)
        {
            if (dist[i] == INF)
            {
                cout << "INF\n";
            }
            else
            {
                cout << dist[i] << "\n";
            }
        }
    }

    return 0;
}
#endif