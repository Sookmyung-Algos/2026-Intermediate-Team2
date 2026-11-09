#include <bits/stdc++.h>
using namespace std;
 
int pi[55];
 
int main() {
    int n, k;
    string t;
    cin >> n >> k >> t;

    int j = 0;
    for (int i = 1; i < n; i++) {
        while (j > 0 && t[i] != t[j]) j = pi[j-1];
        if (t[i] == t[j]) j++;
        pi[i] = j;
    }
 
    int p = pi[n-1];
    string ans = t;
    for (int i = 0; i < k-1; i++) {
        ans = ans + t.substr(p);
    }
    cout << ans << endl;
    return 0;
}
