#include <bits/stdc++.h>
using namespace std;

struct Node {
    int next[10] = {};
    bool finish = false;
};

vector<Node> trie;

bool insert(const string& s) {
    int cur = 0;

    for (char c : s) {
        if (trie[cur].finish)
            return false;

        int x = c - '0';

        if (!trie[cur].next[x]) {
            trie[cur].next[x] = trie.size();
            trie.emplace_back();
        }

        cur = trie[cur].next[x];
    }

    if (trie[cur].finish)
        return false;

    for (int i = 0; i < 10; i++) {
        if (trie[cur].next[i])
            return false;
    }

    trie[cur].finish = true;
    return true;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t;
    cin >> t;

    while (t--) {
        trie.clear();
        trie.emplace_back();

        int n;
        cin >> n;

        bool ok = true;

        while (n--) {
            string s;
            cin >> s;

            if (ok && !insert(s))
                ok = false;
        }

        cout << (ok ? "YES" : "NO") << '\n';
    }

    return 0;
}