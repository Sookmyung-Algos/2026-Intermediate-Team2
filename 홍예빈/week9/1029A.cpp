// Codeforces 1029A - Many Equal Substrings
#include <iostream>
#include <string>
#include <vector>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, k;
    string s;
    cin >> n >> k >> s;

    vector<int> pi(n, 0);
    for (int i = 1; i < n; ++i) {
        int j = pi[i - 1];
        while (j > 0 && s[i] != s[j]) {
            j = pi[j - 1];
        }
        if (s[i] == s[j]) {
            ++j;
        }
        pi[i] = j;
    }

    string tail = s.substr(pi[n - 1]);

    cout << s;
    for (int i = 1; i < k; ++i) {
        cout << tail;
    }
    cout << '\n';

    return 0;
}