#include <bits/stdc++.h>
using namespace std;

struct Point {
    long long x, y;
};

long long ccw(Point a, Point b, Point c) {
    return (b.x - a.x) * (c.y - a.y)
        - (b.y - a.y) * (c.x - a.x);
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    cin >> n;

    vector<Point> p(n + 1);

    for (int i = 0; i <= n; i++) {
        cin >> p[i].x >> p[i].y;
    }

    int answer = 0;

    for (int i = 1; i < n; i++) {
        if (ccw(p[i - 1], p[i], p[i + 1]) > 0) {
            answer++;
        }
    }

    if (ccw(p[n - 1], p[0], p[1]) > 0) {
        answer++;
    }

    cout << answer;
}