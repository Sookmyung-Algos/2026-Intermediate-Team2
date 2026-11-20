// Codeforces 706D - Vasiliy's Multiset
#include <iostream>
#include <vector>
using namespace std;

constexpr int HIGHEST_BIT = 29;

struct Node {
    int child[2]{};
    int count = 0;
};

void update(vector<Node>& trie, int x, int delta) {
    int node = 0;

    for (int b = HIGHEST_BIT; b >= 0; --b) {
        int bit = (x >> b) & 1;

        if (trie[node].child[bit] == 0) {
            trie[node].child[bit] = static_cast<int>(trie.size());
            trie.emplace_back();
        }

        node = trie[node].child[bit];
        trie[node].count += delta;
    }
}

int maxXor(const vector<Node>& trie, int x) {
    int node = 0;
    int answer = 0;

    for (int b = HIGHEST_BIT; b >= 0; --b) {
        int bit = (x >> b) & 1;
        int opposite = trie[node].child[bit ^ 1];

        if (opposite != 0 && trie[opposite].count > 0) {
            answer |= 1 << b;
            node = opposite;
        } else {
            node = trie[node].child[bit];
        }
    }

    return answer;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int q;
    cin >> q;

    vector<Node> trie;
    trie.reserve(1 + 30 * (q + 1));
    trie.emplace_back();  // 루트
    update(trie, 0, 1);   // 처음부터 들어 있는 0

    while (q--) {
        char op;
        int x;
        cin >> op >> x;

        if (op == '+') {
            update(trie, x, 1);
        } else if (op == '-') {
            update(trie, x, -1);
        } else {
            cout << maxXor(trie, x) << '\n';
        }
    }
}