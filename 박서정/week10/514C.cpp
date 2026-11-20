#include <bits/stdc++.h>
using namespace std;

struct Node {
    int next[3] = {};
};

vector<Node> pre(1), suf(1);
unordered_map<long long, int> mp;

int extend(vector<Node>& trie, int u, int c) {
    if (!trie[u].next[c]) {
        trie[u].next[c] = trie.size();
        trie.emplace_back();
    }

    return trie[u].next[c];
}

long long key(int a, int b) {
    return (1LL * a << 32) | b;
}

void insert(const string& s) {
    int n = s.size();
    vector<int> p(n + 1), q(n + 1);

    for (int i = 0; i < n; i++)
        p[i + 1] = extend(pre, p[i], s[i] - 'a');

    for (int i = n - 1; i >= 0; i--)
        q[i] = extend(suf, q[i + 1], s[i] - 'a');

    for (int i = 0; i < n; i++)
        mp[key(p[i], q[i + 1])] |= 1 << (s[i] - 'a');
}

bool search(const string& s) {
    int n = s.size();
    vector<int> q(n + 1, -1);

    q[n] = 0;

    for (int i = n - 1; i >= 0; i--) {
        int v = suf[q[i + 1]].next[s[i] - 'a'];

        if (!v)
            break;

        q[i] = v;
    }

    int u = 0;

    for (int i = 0; i < n; i++) {
        int c = s[i] - 'a';

        if (q[i + 1] != -1) {
            auto it = mp.find(key(u, q[i + 1]));

            if (it != mp.end()) {
                if (it->second & (7 ^ (1 << c)))
                    return true;
            }
        }

        u = pre[u].next[c];

        if (!u)
            break;
    }

    return false;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, m;
    cin >> n >> m;

    mp.reserve(600005);

    while (n--) {
        string s;
        cin >> s;
        insert(s);
    }

    while (m--) {
        string s;
        cin >> s;

        cout << (search(s) ? "YES" : "NO") << '\n';
    }

    return 0;
}