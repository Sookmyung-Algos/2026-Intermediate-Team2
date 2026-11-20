// Codeforces 455B - A lot of Games
#include <iostream>
#include <string>
#include <vector>
using namespace std;

struct Node {
    int next[26]{};
    bool canWin = false;
    bool canLose = false;
};

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, k;
    cin >> n >> k;

    vector<Node> trie;
    trie.reserve(100001);
    trie.emplace_back();  // 0번은 루트

    for (int i = 0; i < n; ++i) {
        string word;
        cin >> word;

        int curr = 0;
        for (char ch : word) {
            int idx = ch - 'a';
            if (trie[curr].next[idx] == 0) {
                trie[curr].next[idx] = static_cast<int>(trie.size());
                trie.emplace_back();
            }
            curr = trie[curr].next[idx];
        }
    }

    for (int v = static_cast<int>(trie.size()) - 1; v >= 0; --v) {
        bool hasChild = false;

        for (int u : trie[v].next) {
            if (u == 0) continue;

            hasChild = true;
            if (!trie[u].canWin) trie[v].canWin = true;
            if (!trie[u].canLose) trie[v].canLose = true;
        }

        if (!hasChild) trie[v].canLose = true;
    }

    bool firstWins = trie[0].canWin && (trie[0].canLose || k % 2 == 1);
    cout << (firstWins ? "First" : "Second") << '\n';
}