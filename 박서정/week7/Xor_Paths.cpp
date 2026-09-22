#include <bits/stdc++.h>
using namespace std;

using ll = long long;

int n, m;
ll k, a[20][20], ans;
int midStep;
unordered_map<ll, ll> mp[20][20];

void dfs1(int r, int c, int step, ll x) {
    x ^= a[r][c];

    if (step == midStep) {
        mp[r][c][x]++;
        return;
    }

    if (r + 1 < n) dfs1(r + 1, c, step + 1, x);
    if (c + 1 < m) dfs1(r, c + 1, step + 1, x);
}

void dfs2(int r, int c, int step, ll x) {
    x ^= a[r][c];

    if (step == (n + m - 2) - midStep) {
        ll need = x ^ a[r][c] ^ k;
        auto it = mp[r][c].find(need);
        if (it != mp[r][c].end()) ans += it->second;
        return;
    }

    if (r > 0) dfs2(r - 1, c, step + 1, x);
    if (c > 0) dfs2(r, c - 1, step + 1, x);
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> n >> m >> k;

    for (int i = 0; i < n; i++)
        for (int j = 0; j < m; j++)
            cin >> a[i][j];

    midStep = (n + m - 2) / 2;

    dfs1(0, 0, 0, 0);
    dfs2(n - 1, m - 1, 0, 0);

    cout << ans;
}