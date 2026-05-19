#if 0
#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <vector>
using namespace std;

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

    int F;
    cin >> F;

    while (F--)
    {
        int N, M, B;
        cin >> N >> M >> B;

        vector<Edge> edges;

        for (int i = 0; i < M; ++i)
        {
            int u, v;
            long long t;
            cin >> u >> v >> t;
            edges.push_back({ u, v, t });
            edges.push_back({ v, u, t });
        }

        for (int i = 0; i < B; ++i)
        {
            int u, v;
            long long t;
            cin >> u >> v >> t;
            edges.push_back({ u, v, -t });
        }

        vector<long long> dist(N + 1, 0);
        bool possible = false;

        for (int i = 1; i <= N; ++i)
        {
            for (int j = 0; j < edges.size(); ++j)
            {
                int u = edges[j].u;
                int v = edges[j].v;
                long long w = edges[j].w;

                if (dist[v] > dist[u] + w)
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
    }

    return 0;
}
#endif