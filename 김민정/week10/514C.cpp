#include <iostream>
#include <string>
using namespace std;
 
int trie[600005][3];
bool finish[600005];
int cnt = 1;
 
void insert(string s) {
    int cur = 0;
 
    for (int i = 0; i < s.size(); i++) {
        int x = s[i] - 'a';
 
        if (trie[cur][x] == 0) {
            trie[cur][x] = cnt++;
        }
 
        cur = trie[cur][x];
    }
 
    finish[cur] = true;
}
 
bool search(string &s, int cur, int pos, int diff) {
    if (pos == s.size()) {
        if (diff == 1 && finish[cur]) {
            return true;
        }
        return false;
    }
 
    int x = s[pos] - 'a';
 
    for (int i = 0; i < 3; i++) {
        if (trie[cur][i] == 0) {
            continue;
        }
 
        int d = diff;
 
        if (i != x) {
            d++;
        }
 
        if (d > 1) {
            continue;
        }
 
        if (search(s, trie[cur][i], pos + 1, d)) {
            return true;
        }
    }
 
    return false;
}
 
int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
 
    int n, m;
    cin >> n >> m;
 
    for (int i = 0; i < n; i++) {
        string s;
        cin >> s;
        insert(s);
    }
 
    for (int i = 0; i < m; i++) {
        string s;
        cin >> s;
 
        if (search(s, 0, 0, 0)) {
            cout << "YES\n";
        }
        else {
            cout << "NO\n";
        }
    }
 
    return 0;
}
