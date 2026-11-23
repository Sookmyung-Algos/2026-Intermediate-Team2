#include <iostream>
#include <string>
using namespace std;
 
int trie[100005][26];
bool win[100005];
bool lose[100005];
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
}
 
void dfs(int cur) {
    bool leaf = true;
 
    for (int i = 0; i < 26; i++) {
        int next = trie[cur][i];
 
        if (next != 0) {
            leaf = false;
            dfs(next);
 
            if (win[next] == false) {
                win[cur] = true;
            }
 
            if (lose[next] == false) {
                lose[cur] = true;
            }
        }
    }
 
    if (leaf) {
        win[cur] = false;
        lose[cur] = true;
    }
}
 
int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
 
    int n, k;
    cin >> n >> k;
 
    for (int i = 0; i < n; i++) {
        string s;
        cin >> s;
        insert(s);
    }
 
    dfs(0);
 
    if (win[0] == false) {
        cout << "Second\n";
    }
    else if (lose[0] == true) {
        cout << "First\n";
    }
    else {
        if (k % 2 == 1) {
            cout << "First\n";
        }
        else {
            cout << "Second\n";
        }
    }
 
    return 0;
}
