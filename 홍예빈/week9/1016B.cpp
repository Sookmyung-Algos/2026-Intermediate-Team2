// Codeforces 1016B - Segment Occurrences
#include <iostream>
#include <string>
#include <vector>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, m, q;
    string s, t;
    cin >> n >> m >> q >> s >> t;

    // pi[i]는 t[0..i]의 가장 긴 경계 길이
    vector<int> pi(m, 0);
    for (int i = 1, j = 0; i < m; ++i) {
        while (j > 0 && t[i] != t[j]) {
            j = pi[j - 1];
        }
        if (t[i] == t[j]) {
            ++j;
        }
        pi[i] = j;
    }

    vector<int> pref(n + 1, 0);
    for (int i = 0, j = 0; i < n; ++i) {
        while (j > 0 && s[i] != t[j]) {
            j = pi[j - 1];
        }
        if (s[i] == t[j]) {
            ++j;
        }
        if (j == m) {
            // i는 0-based 끝 위치, start는 1-based 시작 위치
            int start = i - m + 2;
            pref[start] = 1;
            j = pi[j - 1];  // 겹치는 등장도 찾을 수 있도록 경계를 유지
        }
    }

    for (int i = 1; i <= n; ++i) {
        pref[i] += pref[i - 1];
    }

    while (q--) {
        int l, r;
        cin >> l >> r;

        int last = r - m + 1;
        if (last < l) {
            cout << 0 << '\n';
        } else {
            cout << pref[last] - pref[l - 1] << '\n';
        }
    }

    return 0;
}