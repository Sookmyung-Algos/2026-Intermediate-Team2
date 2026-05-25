// 음수 간선의 최단 거리

#include <iostream>
#include <vector>
#include <tuple>
#include <limits>

using namespace std;

struct Edge {
    int u, v;
    long long w;
};

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int N, M;
    cin >> N >> M;

    vector<Edge> edges(M);

    for (int i = 0; i < M; i++) {
        cin >> edges[i].u >> edges[i].v >> edges[i].w;
    }

    const long long INF = numeric_limits<long long>::max() / 4;

    vector<long long> dist(N + 1, INF);
    dist[1] = 0;

    for (int i = 1; i <= N - 1; i++) {
        bool updated = false;

        for (const Edge& e : edges) {
            if (dist[e.u] == INF) continue;

            if (dist[e.v] > dist[e.u] + e.w) {
                dist[e.v] = dist[e.u] + e.w;
                updated = true;
            }
        }

        if (!updated) break;
    }

    for (const Edge& e : edges) {
        if (dist[e.u] == INF) continue;

        if (dist[e.v] > dist[e.u] + e.w) {
            cout << -1 << '\n';
            return 0;
        }
    }

    for (int i = 2; i <= N; i++) {
        if (dist[i] == INF) {
            cout << "INF\n";
        }
        else {
            cout << dist[i] << '\n';
        }
    }

    return 0;
}