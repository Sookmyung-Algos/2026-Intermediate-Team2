#include <bits/stdc++.h>
using namespace std;
 
int a[200005], b[200005];
int pi[200005];
 
int main() {
    int n, w;
    cin >> n >> w;
    for (int i = 0; i < n; i++) cin >> a[i];
    for (int i = 0; i < w; i++) cin >> b[i];
 
    if (w == 1) {
        cout << n << endl;
        return 0;
    }
    if (w > n) {
        cout << 0 << endl;
        return 0;
    }
 
    vector<int> da, db;
    for (int i = 1; i < n; i++) da.push_back(a[i] - a[i-1]);
    for (int i = 1; i < w; i++) db.push_back(b[i] - b[i-1]);
 
    int m = db.size();
    int j = 0;
    for (int i = 1; i < m; i++) {
        while (j > 0 && db[i] != db[j]) j = pi[j-1];
        if (db[i] == db[j]) j++;
        pi[i] = j;
    }
 
    int ans = 0;
    j = 0;
    for (int i = 0; i < da.size(); i++) {
        while (j > 0 && da[i] != db[j]) j = pi[j-1];
        if (da[i] == db[j]) j++;
        if (j == m) {
            ans++;
            j = pi[j-1];
        }
    }
    cout << ans << endl;
    return 0;
}
