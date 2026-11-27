
#include <iostream>
#include <string>
using namespace std;

int trie[100005][10];
bool isEnd[100005];
int cnt = 1;

bool insert(string s) {
    int cur = 0;

    for (int i = 0; i < s.size(); i++) {
        int x = s[i] - '0';

        if (isEnd[cur] == true) {
            return false;
        }

        if (trie[cur][x] == 0) {
            trie[cur][x] = cnt;
            cnt++;
        }

        cur = trie[cur][x];
    }

    if (isEnd[cur] == true) {
        return false;
    }

    for (int i = 0; i < 10; i++) {
        if (trie[cur][i] != 0) {
            return false;
        }
    }

    isEnd[cur] = true;
    return true;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int t, n;
    cin >> t;

    while (t--) {
        cin >> n;

        for (int i = 0; i < cnt; i++) {
            for (int j = 0; j < 10; j++) {
                trie[i][j] = 0;
            }
            isEnd[i] = false;
        }

        cnt = 1;
        bool answer = true;

        for (int i = 0; i < n; i++) {
            string s;
            cin >> s;

            if (insert(s) == false) {
                answer = false;
            }
        }

        if (answer) cout << "YES\n";
        else cout << "NO\n";
    }

    return 0;
}
