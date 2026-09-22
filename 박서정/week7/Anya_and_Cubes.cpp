#include <bits/stdc++.h>
using namespace std;

using ll = long long;

int n, k;
ll S;
vector<ll> a;
ll fact[19];
vector<vector<ll>> L, R;

void dfs(int idx, int end, int cnt, ll sum, vector<vector<ll>>& v) {
    if (cnt > k || sum > S) return;

    if (idx == end) {
        v[cnt].push_back(sum);
        return;
    }

    dfs(idx + 1, end, cnt, sum, v);

    if (sum + a[idx] <= S)
        dfs(idx + 1, end, cnt, sum + a[idx], v);

    if (cnt < k && a[idx] <= 18 && sum + fact[a[idx]] <= S)
        dfs(idx + 1, end, cnt + 1, sum + fact[a[idx]], v);
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> n >> k >> S;

    a.resize(n);
    for (ll& x : a) cin >> x;

    fact[0] = 1;
    for (int i = 1; i <= 18; i++)
        fact[i] = fact[i - 1] * i;

    L.resize(k + 1);
    R.resize(k + 1);

    int mid = n / 2;

    dfs(0, mid, 0, 0, L);
    dfs(mid, n, 0, 0, R);

    for (int i = 0; i <= k; i++)
        sort(R[i].begin(), R[i].end());

    ll ans = 0;

    for (int i = 0; i <= k; i++) {
        for (ll x : L[i]) {
            for (int j = 0; i + j <= k; j++) {
                ll target = S - x;
                auto lo = lower_bound(R[j].begin(), R[j].end(), target);
                auto hi = upper_bound(R[j].begin(), R[j].end(), target);
                ans += hi - lo;
            }
        }
    }

    cout << ans;
}