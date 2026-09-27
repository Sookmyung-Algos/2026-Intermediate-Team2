#include <bits/stdc++.h>
using namespace std;

using ll = long long;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int L, N;
    cin >> L >> N;

    vector<ll> C(L + 1);
    C[0] = 0;

    for (int i = 1; i <= L; i++) {
        cin >> C[i];
    }

    vector<int> X(N);

    for (int i = 0; i < N; i++) {
        cin >> X[i];
    }

    auto cost = [&](int pos) {
        ll sum = 0;

        for (int x : X) {
            int dist = abs(x - pos);
            sum += C[dist];
        }

        return sum;
    };

    int left = 0;
    int right = L;

    while (right - left > 3) {
        int m1 = left + (right - left) / 3;
        int m2 = right - (right - left) / 3;

        if (cost(m1) <= cost(m2)) {
            right = m2;
        }
        else {
            left = m1;
        }
    }

    ll answer = LLONG_MAX;

    for (int pos = left; pos <= right; pos++) {
        answer = min(answer, cost(pos));
    }

    cout << answer << '\n';

    return 0;
}