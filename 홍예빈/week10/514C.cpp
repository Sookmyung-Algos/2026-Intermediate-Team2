// Codeforces 514C - Watto and Mechanism
#include <algorithm>
#include <array>
#include <cstdint>
#include <iostream>
#include <string>
#include <vector>
using namespace std;

constexpr int MAX_TOTAL_LENGTH = 600000;
constexpr int NODE_BASE = MAX_TOTAL_LENGTH + 1;

struct Trie {
    vector<array<int, 3>> next{1};

    int add(int node, int letter) {
        if (next[node][letter] == 0) {
            next[node][letter] = static_cast<int>(next.size());
            next.push_back({});
        }
        return next[node][letter];
    }

    int follow(int node, int letter) const {
        if (node == -1) return -1;
        int child = next[node][letter];
        return child == 0 ? -1 : child;
    }
};

int64_t makeKey(int prefixNode, int suffixNode, int letter) {
    return (static_cast<int64_t>(prefixNode) * NODE_BASE + suffixNode)
           * 3 + letter;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, m;
    cin >> n >> m;

    Trie forwardTrie, reverseTrie;
    vector<int64_t> keys;
    vector<int> suffix;
    string word;

    for (int j = 0; j < n; ++j) {
        cin >> word;
        int length = static_cast<int>(word.size());

        // suffix[i]는 word[i..length-1]을 뒤집어 읽은 노드
        suffix.resize(length + 1);
        suffix[length] = 0;
        for (int i = length - 1; i >= 0; --i) {
            suffix[i] = reverseTrie.add(suffix[i + 1], word[i] - 'a');
        }

        int prefix = 0;
        for (int i = 0; i < length; ++i) {
            int letter = word[i] - 'a';
            keys.push_back(makeKey(prefix, suffix[i + 1], letter));
            prefix = forwardTrie.add(prefix, letter);
        }
    }

    sort(keys.begin(), keys.end());

    for (int j = 0; j < m; ++j) {
        cin >> word;
        int length = static_cast<int>(word.size());

        suffix.resize(length + 1);
        suffix[length] = 0;
        for (int i = length - 1; i >= 0; --i) {
            suffix[i] = reverseTrie.follow(suffix[i + 1], word[i] - 'a');
        }

        bool found = false;
        int prefix = 0;

        for (int i = 0; i < length && prefix != -1 && !found; ++i) {
            int letter = word[i] - 'a';

            if (suffix[i + 1] != -1) {
                for (int other = 0; other < 3; ++other) {
                    if (other == letter) continue;

                    int64_t key = makeKey(prefix, suffix[i + 1], other);
                    if (binary_search(keys.begin(), keys.end(), key)) {
                        found = true;
                        break;
                    }
                }
            }

            prefix = forwardTrie.follow(prefix, letter);
        }

        cout << (found ? "YES" : "NO") << '\n';
    }
}