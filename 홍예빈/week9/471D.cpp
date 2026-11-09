// Codeforces 471D - MUH and Cube Walls
#include <iostream>
#include <vector>
using namespace std;

vector<int> readDifferences(int length) {
    vector<int> diff(length - 1);
    int prev;
    cin >> prev;

    for (int& delta : diff) {
        int height;
        cin >> height;
        delta = height - prev;
        prev = height;
    }

    return diff;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, w;
    cin >> n >> w;

    if (w == 1) {
        cout << n << '\n';
        return 0;
    }
    if (w > n) {
        cout << 0 << '\n';
        return 0;
    }

    vector<int> text = readDifferences(n);
    vector<int> pattern = readDifferences(w);
    int m = w - 1;

    // 코끼리 벽의 차이 배열로 접두부 배열을 만든다.
    vector<int> pi(m, 0);
    for (int i = 1, j = 0; i < m; ++i) {
        while (j > 0 && pattern[i] != pattern[j]) {
            j = pi[j - 1];
        }
        if (pattern[i] == pattern[j]) {
            ++j;
        }
        pi[i] = j;
    }

    int answer = 0;
    int j = 0;
    for (int delta : text) {
        while (j > 0 && delta != pattern[j]) {
            j = pi[j - 1];
        }
        if (delta == pattern[j]) {
            ++j;
        }
        if (j == m) {
            ++answer;
            j = pi[j - 1];  // 서로 겹치는 구간도 센다.
        }
    }

    cout << answer << '\n';
    return 0;
}