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

    for (int i = 1; i <= L; i++)
        cin >> C[i];

    vector<int> X(N);
    for (int& x : X)
        cin >> x;

    auto f = [&](int p) {
        ll sum = 0;
        for (int x : X)
            sum += C[abs(x - p)];
        return sum;
        };

    int l = 0, r = L;

    while (r - l > 3) {
        int m1 = l + (r - l) / 3;
        int m2 = r - (r - l) / 3;

        ll v1 = f(m1);
        ll v2 = f(m2);

        if (v1 <= v2)
            r = m2;
        else
            l = m1;
    }

    ll ans = LLONG_MAX;

    for (int i = l; i <= r; i++)
        ans = min(ans, f(i));

    cout << ans;
}