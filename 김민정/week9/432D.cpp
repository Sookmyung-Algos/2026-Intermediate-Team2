#include <bits/stdc++.h>
using namespace std;
 
int pi[100005];
long long cnt[100005];
 
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
 
    for (int i = 0; i < n; i++) {
        cnt[pi[i]]++;
    }
    for (int i = n; i >= 1; i--) {
        cnt[pi[i-1]] += cnt[i];
    }
    for (int i = 1; i <= n; i++) {
        cnt[i]++; 
    }
 
    vector<int> v;
    int len = n;
    while (len > 0) {
        v.push_back(len);
        len = pi[len-1];
    }
    reverse(v.begin(), v.end());
 
    cout << v.size() << endl;
    for (int i = 0; i < v.size(); i++) {
        cout << v[i] << " " << cnt[v[i]] << endl;
    }
    return 0;
}
