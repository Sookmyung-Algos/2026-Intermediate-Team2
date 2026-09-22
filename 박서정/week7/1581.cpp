#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t, n, m;
    cin >> t;

    cin >> n;
    vector<int> a(n);
    for (int& x : a) cin >> x;

    cin >> m;
    vector<int> b(m);
    for (int& x : b) cin >> x;

    vector<int> A, B;

    for (int i = 0; i < n; i++) {
        int sum = 0;
        for (int j = i; j < n; j++) {
            sum += a[j];
            A.push_back(sum);
        }
    }

    for (int i = 0; i < m; i++) {
        int sum = 0;
        for (int j = i; j < m; j++) {
            sum += b[j];
            B.push_back(sum);
        }
    }

    sort(B.begin(), B.end());

    long long ans = 0;

    for (int x : A) {
        int target = t - x;
        auto l = lower_bound(B.begin(), B.end(), target);
        auto r = upper_bound(B.begin(), B.end(), target);
        ans += r - l;
    }

    cout << ans;
}