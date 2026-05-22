// 환전 차익거래

#include <iostream>
#include <vector>
#include <cmath>

using namespace std;

struct Edge {
    int u, v;
    double w;
};

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int N, M;
    cin >> N >> M;

    vector<Edge> edges;

    for (int i = 0; i < M; i++) {
        int u, v;
        double r;
        cin >> u >> v >> r;

        edges.push_back({ u, v, -log(r) });
    }

    const double INF = 1e100;
    const double EPS = 1e-12;

    vector<double> dist(N + 1, INF);
    dist[1] = 0.0;

    for (int i = 1; i <= N - 1; i++) {
        bool updated = false;

        for (const Edge& e : edges) {
            if (dist[e.u] >= INF / 2) continue;

            if (dist[e.v] > dist[e.u] + e.w + EPS) {
                dist[e.v] = dist[e.u] + e.w;
                updated = true;
            }
        }

        if (!updated) break;
    }

    bool arbitrage = false;

    for (const Edge& e : edges) {
        if (dist[e.u] >= INF / 2) continue;

        if (dist[e.v] > dist[e.u] + e.w + EPS) {
            arbitrage = true;
            break;
        }
    }

    if (arbitrage) {
        cout << "YES\n";
    }
    else {
        cout << "NO\n";
    }

    return 0;
}