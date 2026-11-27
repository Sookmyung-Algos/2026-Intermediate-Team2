#include <iostream>
using namespace std;
 
int trie[6000005][2];
int cnt[6000005];
int nodeCount = 1;
 
void insert(int x) {
    int cur = 0;
 
    cnt[cur]++;
 
    for (int i = 30; i >= 0; i--) {
        int bit = (x >> i) & 1;
 
        if (trie[cur][bit] == 0) {
            trie[cur][bit] = nodeCount++;
        }
 
        cur = trie[cur][bit];
        cnt[cur]++;
    }
}
 
void erase(int x) {
    int cur = 0;
    cnt[cur]--;
 
    for (int i = 30; i >= 0; i--) {
        int bit = (x >> i) & 1;
 
        cur = trie[cur][bit];
        cnt[cur]--;
    }
}
 
int search(int x) {
    int cur = 0;
    int ans = 0;
 
    for (int i = 30; i >= 0; i--) {
        int bit = (x >> i) & 1;
        int want = 1 - bit;
 
        if (trie[cur][want] != 0 &&
            cnt[trie[cur][want]] > 0) {
            ans += (1 << i);
            cur = trie[cur][want];
        }
        else {
            cur = trie[cur][bit];
        }
    }
 
    return ans;
}
 
int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
 
    int q;
    cin >> q;
 
    insert(0);
 
    for (int i = 0; i < q; i++) {
        char op;
        int x;
 
        cin >> op >> x;
 
        if (op == '+') {
            insert(x);
        }
        else if (op == '-') {
            erase(x);
        }
        else if (op == '?') {
            cout << search(x) << "\n";
        }
    }
 
    return 0;
}
