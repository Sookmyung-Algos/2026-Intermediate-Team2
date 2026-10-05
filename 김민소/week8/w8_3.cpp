#include <bits/stdc++.h>
using namespace std;

using ll = long long;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int N;
    ll A, R, M;

    cin >> N >> A >> R >> M;

    vector<ll> h(N);

    for (int i = 0; i < N; i++) {
        cin >> h[i];
    }

    M = min(M, A + R);

    auto cost = [&](ll x) {
        ll add = 0;
        ll remove = 0;

        for (ll height : h) {
            if (height < x) {
                add += x - height;
            }
            else {
                remove += height - x;
            }
        }

        ll move = min(add, remove);

        return move * M
             + (add - move) * A
             + (remove - move) * R;
    };

    ll left = 0;
    ll right = *max_element(h.begin(), h.end());

    while (right - left > 3) {
        ll m1 = left + (right - left) / 3;
        ll m2 = right - (right - left) / 3;

        if (cost(m1) <= cost(m2)) {
            right = m2;
        }
        else {
            left = m1;
        }
    }

    ll answer = LLONG_MAX;

    for (ll x = left; x <= right; x++) {
        answer = min(answer, cost(x));
    }

    cout << answer << '\n';

    return 0;
}