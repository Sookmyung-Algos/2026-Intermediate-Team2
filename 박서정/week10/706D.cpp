#include <bits/stdc++.h>
using namespace std;

struct Node {
    int next[2] = {};
    int cnt = 0;
};

vector<Node> trie(1);

void update(int x, int d) {
    int cur = 0;

    for (int i = 29; i >= 0; i--) {
        int b = (x >> i) & 1;

        if (!trie[cur].next[b]) {
            trie[cur].next[b] = trie.size();
            trie.emplace_back();
        }

        cur = trie[cur].next[b];
        trie[cur].cnt += d;
    }
}

int query(int x) {
    int cur = 0;
    int ans = 0;

    for (int i = 29; i >= 0; i--) {
        int b = (x >> i) & 1;
        int v = trie[cur].next[b ^ 1];

        if (v && trie[v].cnt > 0) {
            ans |= 1 << i;
            cur = v;
        }
        else {
            cur = trie[cur].next[b];
        }
    }

    return ans;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int q;
    cin >> q;

    trie.reserve(30 * (q + 1) + 1);
    update(0, 1);

    while (q--) {
        char op;
        int x;

        cin >> op >> x;

        if (op == '+')
            update(x, 1);
        else if (op == '-')
            update(x, -1);
        else
            cout << query(x) << '\n';
    }

    return 0;
}