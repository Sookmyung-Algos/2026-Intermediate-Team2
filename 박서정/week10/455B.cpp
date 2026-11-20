#include <bits/stdc++.h>
using namespace std;

struct Node {
    int next[26] = {};
    bool win = false;
    bool lose = false;
};

vector<Node> trie(1);

void insert(const string& s) {
    int cur = 0;

    for (char c : s) {
        int x = c - 'a';

        if (!trie[cur].next[x]) {
            trie[cur].next[x] = trie.size();
            trie.emplace_back();
        }

        cur = trie[cur].next[x];
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, k;
    cin >> n >> k;

    while (n--) {
        string s;
        cin >> s;
        insert(s);
    }

    for (int u = (int)trie.size() - 1; u >= 0; u--) {
        bool leaf = true;

        for (int v : trie[u].next) {
            if (!v)
                continue;

            leaf = false;

            if (!trie[v].win)
                trie[u].win = true;

            if (!trie[v].lose)
                trie[u].lose = true;
        }

        if (leaf)
            trie[u].lose = true;
    }

    if (!trie[0].win)
        cout << "Second\n";
    else if (trie[0].lose || k % 2)
        cout << "First\n";
    else
        cout << "Second\n";

    return 0;
}