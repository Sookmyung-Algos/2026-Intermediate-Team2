// Á¤¿Ã #2223 ºí·¢È¦

#include <iostream>
#include <vector>

using namespace std;

struct Edge {
    int u, v;
    long long w;
};

bool hasNegativeCycle(int N, const vector<Edge>& edges) {
    vector<long long> dist(N + 1, 0);

    for (int i = 1; i <= N; i++) {
        bool updated = false;

        for (const Edge& e : edges) {
            if (dist[e.v] > dist[e.u] + e.w) {
                dist[e.v] = dist[e.u] + e.w;
                updated = true;

                if (i == N) {
                    return true;
                }
            }
        }

        if (!updated) break;
    }

    return false;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int F;
    cin >> F;

    while (F--) {
        int N, M, B;
        cin >> N >> M >> B;

        vector<Edge> edges;

        for (int i = 0; i < M; i++) {
            int S, E;
            long long T;
            cin >> S >> E >> T;

            edges.push_back({ S, E, T });
            edges.push_back({ E, S, T });
        }

        for (int i = 0; i < B; i++) {
            int S, E;
            long long T;
            cin >> S >> E >> T;

            edges.push_back({ S, E, -T });
        }

        if (hasNegativeCycle(N, edges)) {
            cout << "YES\n";
        }
        else {
            cout << "NO\n";
        }
    }

    return 0;
}