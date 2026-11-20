#include <bits/stdc++.h>
using namespace std;

struct Point {
    long long x, y;
};

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int N;
    cin >> N;

    vector<Point> p(N);

    for (int i = 0; i < N; i++) {
        cin >> p[i].x >> p[i].y;
    }

    long long sum = 0;

    for (int i = 0; i < N; i++) {
        int j = (i + 1) % N;
        sum += p[i].x * p[j].y;
        sum -= p[i].y * p[j].x;
    }

    sum = abs(sum);

    cout << sum / 2;

    if (sum % 2)
        cout << ".5";
    else
        cout << ".0";
}