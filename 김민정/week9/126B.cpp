#include <bits/stdc++.h>
using namespace std;
 
int pi[1000005];
 
int main() {
    string s;
    cin >> s;
    int n = s.size();
 
    int j = 0;
    for (int i = 1; i < n; i++) {
        while (j > 0 && s[i] != s[j]) j = pi[j-1];
        if (s[i] == s[j]) j++;
        pi[i] = j;
    }
 
    int L = pi[n-1];
    if (L == 0) {
        cout << "Just a legend" << endl;
        return 0;
    }
 
    int mx = 0;
    for (int i = 0; i < n-1; i++) {
        if (pi[i] > mx) mx = pi[i];
    }
 
    if (mx >= L) {
        cout << s.substr(0, L) << endl;
    } else {
        L = pi[L-1];
        if (L > 0) cout << s.substr(0, L) << endl;
        else cout << "Just a legend" << endl;
    }
    return 0;
}
