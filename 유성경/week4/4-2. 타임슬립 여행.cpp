#if 0
#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <vector>
using namespace std;

const long long INF = 1e18;
const long long MINUS_INF = -1e18;

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

    for (int i = 1; i <= N - 1; ++i)
    {
        for (int j = 0; j < M; ++j)
        {
            int u = edges[j].u;
            int v = edges[j].v;
            long long w = edges[j].w;

            if (dist[u] != INF && dist[u] != MINUS_INF)
            {
                if (dist[v] > dist[u] + w)
                {
                    dist[v] = dist[u] + w;
                }
            }
        }
    }

    for (int i = 1; i <= N; ++i)
    {
        for (int j = 0; j < M; ++j)
        {
            int u = edges[j].u;
            int v = edges[j].v;
            long long w = edges[j].w;

            if (dist[u] != INF)
            {
                if (dist[u] == MINUS_INF)
                {
                    dist[v] = MINUS_INF;
                }
                else if (dist[v] > dist[u] + w)
                {
                    dist[v] = MINUS_INF;
                }
            }
        }
    }

    if (dist[N] == MINUS_INF)
    {
        cout << "-INF\n";
    }
    else if (dist[N] == INF)
    {
        cout << "INF\n";
    }
    else
    {
        cout << dist[N] << "\n";
    }

    return 0;
}
#endif