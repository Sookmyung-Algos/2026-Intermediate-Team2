
#include <bits/stdc++.h>
using namespace std;
 
int ok[1005];
int sum[1005];
 
int main() {
    int n, m, q;
    cin >> n >> m >> q;
    string s, t;
    cin >> s >> t;
 
    for (int i = 1; i + m - 1 <= n; i++) {
        bool same = true;
        for (int k = 0; k < m; k++) {
            if (s[i-1+k] != t[k]) {
                same = false;
                break;
            }
        }
        if (same) ok[i] = 1;
    }
 
    for (int i = 1; i <= n; i++) {
        sum[i] = sum[i-1] + ok[i];
    }
 
    while (q--) {
        int l, r;
        cin >> l >> r;
        if (r - l + 1 < m) {
            cout << 0 << endl;
        } else {
            cout << sum[r-m+1] - sum[l-1] << endl;
        }
    }
    return 0;
}
