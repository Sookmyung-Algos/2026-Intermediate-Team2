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
    ll mx = 0;

    for (ll& x : h) {
        cin >> x;
        mx = max(mx, x);
    }

    M = min(M, A + R);

    auto f = [&](ll x) {
        ll add = 0, rem = 0;

        for (ll v : h) {
            if (v < x) add += x - v;
            else rem += v - x;
        }

        ll mv = min(add, rem);

        return mv * M + (add - mv) * A + (rem - mv) * R;
        };

    ll l = 0, r = mx;

    while (r - l > 3) {
        ll m1 = l + (r - l) / 3;
        ll m2 = r - (r - l) / 3;

        if (f(m1) <= f(m2))
            r = m2;
        else
            l = m1;
    }

    ll ans = LLONG_MAX;

    for (ll x = l; x <= r; x++)
        ans = min(ans, f(x));

    cout << ans;
}