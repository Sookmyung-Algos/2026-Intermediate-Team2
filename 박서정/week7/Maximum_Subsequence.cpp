#include <bits/stdc++.h>
using namespace std;

using ll = long long;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    ll m;
    cin >> n >> m;

    vector<ll> a(n);
    for (auto& x : a) cin >> x;

    int mid = n / 2;
    vector<ll> L, R;

    for (int mask = 0; mask < (1 << mid); mask++) {
        ll sum = 0;
        for (int i = 0; i < mid; i++)
            if (mask & (1 << i))
                sum = (sum + a[i]) % m;
        L.push_back(sum);
    }

    int rsz = n - mid;

    for (int mask = 0; mask < (1 << rsz); mask++) {
        ll sum = 0;
        for (int i = 0; i < rsz; i++)
            if (mask & (1 << i))
                sum = (sum + a[mid + i]) % m;
        R.push_back(sum);
    }

    sort(R.begin(), R.end());

    ll ans = 0;

    for (ll x : L) {
        auto it = upper_bound(R.begin(), R.end(), m - 1 - x);

        if (it != R.begin()) {
            --it;
            ans = max(ans, x + *it);
        }
    }

    cout << ans;
}