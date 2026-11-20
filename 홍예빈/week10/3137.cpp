// 정올 3137 - 전화번호 검색
#include <iostream>
#include <string>
#include <vector>
using namespace std;

struct Node {
    int next[10]{};
    bool isEnd = false;
};

bool insertNumber(vector<Node>& trie, const string& number) {
    int curr = 0;

    for (char digit : number) {
        // 기존 번호가 새 번호의 접두사
        if (trie[curr].isEnd) return false;

        int idx = digit - '0';
        if (trie[curr].next[idx] == 0) {
            trie[curr].next[idx] = static_cast<int>(trie.size());
            trie.emplace_back();
        }
        curr = trie[curr].next[idx];
    }

    // 새 번호가 기존 번호의 접두사
    for (int child : trie[curr].next) {
        if (child != 0) return false;
    }

    trie[curr].isEnd = true;
    return true;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t;
    cin >> t;

    while (t--) {
        int n;
        cin >> n;

        vector<Node> trie;
        trie.reserve(10 * n + 1);
        trie.emplace_back();  // 0번 노드는 루트

        bool consistent = true;
        for (int i = 0; i < n; ++i) {
            string number;
            cin >> number;

            if (consistent && !insertNumber(trie, number)) {
                consistent = false;
            }
        }

        cout << (consistent ? "YES" : "NO") << '\n';
    }
}