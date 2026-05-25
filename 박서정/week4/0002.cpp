#include <iostream>
#include <vector>
#include <queue>

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

    vector<Edge> edges;
    vector<vector<int> > reverseGraph(N + 1);

    for (int i = 0; i < M; i++) {
        int u, v;
        long long w;
        cin >> u >> v >> w;

        edges.push_back({ u, v, w });
        reverseGraph[v].push_back(u);
    }

    vector<int> canReachN(N + 1, 0);
    queue<int> q;

    canReachN[N] = 1;
    q.push(N);

    while (!q.empty()) {
        int cur = q.front();
        q.pop();

        for (int prev : reverseGraph[cur]) {
            if (canReachN[prev] == 0) {
                canReachN[prev] = 1;
                q.push(prev);
            }
        }
    }

    const long long INF = 4000000000000000000LL;
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

    bool minusInfinity = false;

    for (const Edge& e : edges) {
        if (dist[e.u] == INF) continue;

        if (dist[e.v] > dist[e.u] + e.w && canReachN[e.v]) {
            minusInfinity = true;
            break;
        }
    }

    if (minusInfinity) {
        cout << "-INF\n";
    }
    else if (dist[N] == INF) {
        cout << "INF\n";
    }
    else {
        cout << dist[N] << '\n';
    }

    return 0;
}