// Codeforces 432D - Prefixes and Suffixes
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

    // 각 접두부가 문자열 맨 앞에 등장하는 한 번을 센다.
    vector<int> cnt(n + 1, 1);
    cnt[0] = 0;

    for (int len = n; len > 0; --len) {
        int border = pi[len - 1];
        cnt[border] += cnt[len];
    }

    vector<int> lengths;
    for (int len = n; len > 0; len = pi[len - 1]) {
        lengths.push_back(len);
    }
    reverse(lengths.begin(), lengths.end());

    cout << lengths.size() << '\n';
    for (int len : lengths) {
        cout << len << ' ' << cnt[len] << '\n';
    }

    return 0;
}