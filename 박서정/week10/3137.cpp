#include <bits/stdc++.h>
using namespace std;

struct Node {
    int next[10] = {};
    int cnt = 0;
    bool finish = false;
};

vector<Node> trie;

void insert(const string& s) {
    int cur = 0;

    for (char c : s) {
        int x = c - '0';

        if (!trie[cur].next[x]) {
            trie[cur].next[x] = trie.size();
            trie.emplace_back();
        }

        cur = trie[cur].next[x];
        trie[cur].cnt++;
    }

    trie[cur].finish = true;
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

        while (n--) {
            string s;
            cin >> s;
            insert(s);
        }

        bool ok = true;

        for (const auto& node : trie) {
            if (node.finish && node.cnt > 1) {
                ok = false;
                break;
            }
        }

        cout << (ok ? "YES" : "NO") << '\n';
    }

    return 0;
}