#include <bits/stdc++.h>
using namespace std;

using ll = long long;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, m;
    cin >> n >> m;

    vector<ll> a(n), b(m);
    for (ll& x : a) cin >> x;
    for (ll& x : b) cin >> x;

    auto f = [&](ll x) {
        ll ret = 0;

        for (ll v : a)
            if (v < x)
                ret += x - v;

        for (ll v : b)
            if (v > x)
                ret += v - x;

        return ret;
        };

    ll l = 1, r = 1000000000LL;

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