// 정올 3642번 - 철도역
#include <bits/stdc++.h>
using namespace std;

using ll = long long;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int L, N;
    cin >> L >> N;

    vector<ll> C(L + 1, 0);
    for (int d = 1; d <= L; ++d) {
        cin >> C[d];
    }

    vector<int> X(N);
    for (int& x : X) {
        cin >> x;
    }

    auto cost = [&](int station) -> ll {
        ll total = 0;

        for (int x : X) {
            total += C[abs(x - station)];
        }

        return total;
    };

    int lo = 0;
    int hi = L;

    while (hi - lo > 2) {
        int m1 = lo + (hi - lo) / 3;
        int m2 = hi - (hi - lo) / 3;

        if (cost(m1) > cost(m2)) {
            lo = m1;
        } else {
            hi = m2;
        }
    }

    ll answer = LLONG_MAX;

    for (int station = lo; station <= hi; ++station) {
        answer = min(answer, cost(station));
    }

    cout << answer << '\n';

    return 0;
}