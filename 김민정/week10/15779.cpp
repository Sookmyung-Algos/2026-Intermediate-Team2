
#include <iostream>
#include <string>
using namespace std;

int trie[1000005][10];
bool finish[1000005];
int cnt = 1;

bool insert(string s) {
    int cur = 0;
    bool ok = true;

    for (int i = 0; i < s.size(); i++) {
        int x = s[i] - '0';

        if (finish[cur]) {
            ok = false;
        }

        if (trie[cur][x] == 0) {
            trie[cur][x] = cnt++;
        }

        cur = trie[cur][x];
    }

    if (finish[cur]) {
        ok = false;
    }

    for (int i = 0; i < 10; i++) {
        if (trie[cur][i] != 0) {
            ok = false;
        }
    }

    finish[cur] = true;
    return ok;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int t;
    cin >> t;

    while (t--) {
        int n;
        cin >> n;

        for (int i = 0; i < cnt; i++) {
            for (int j = 0; j < 10; j++) {
                trie[i][j] = 0;
            }
            finish[i] = false;
        }

        cnt = 1;
        bool ok = true;

        for (int i = 0; i < n; i++) {
            string s;
            cin >> s;

            if (!insert(s)) {
                ok = false;
            }
        }

        if (ok) cout << "YES\n";
        else cout << "NO\n";
    }

    return 0;
}
