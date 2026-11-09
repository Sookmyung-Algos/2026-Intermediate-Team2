// Codeforces 126B - Password
#include <algorithm>
#include <iostream>
#include <string>
#include <vector>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    string s;
    cin >> s;
    int n = static_cast<int>(s.size());

    vector<int> pi(n, 0);
    for (int i = 1, j = 0; i < n; ++i) {
        while (j > 0 && s[i] != s[j]) {
            j = pi[j - 1];
        }
        if (s[i] == s[j]) {
            ++j;
        }
        pi[i] = j;
    }

    int inside = 0;
    for (int i = 0; i < n - 1; ++i) {
        inside = max(inside, pi[i]);
    }

    int len = pi[n - 1];
    while (len > inside) {
        len = pi[len - 1];
    }

    if (len == 0) {
        cout << "Just a legend\n";
    } else {
        cout << s.substr(0, len) << '\n';
    }

    return 0;
}