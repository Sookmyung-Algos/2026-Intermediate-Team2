#include <bits/stdc++.h>
using namespace std;

struct Point {
    long long x, y;
};

struct Segment {
    Point a, b;
};

int ccw(Point a, Point b, Point c) {
    long long v = (b.x - a.x) * (c.y - a.y)
        - (b.y - a.y) * (c.x - a.x);

    if (v > 0) return 1;
    if (v < 0) return -1;
    return 0;
}

bool intersect(Segment s1, Segment s2) {
    Point a = s1.a;
    Point b = s1.b;
    Point c = s2.a;
    Point d = s2.b;

    int ab1 = ccw(a, b, c);
    int ab2 = ccw(a, b, d);
    int cd1 = ccw(c, d, a);
    int cd2 = ccw(c, d, b);

    if (ab1 == 0 && ab2 == 0 && cd1 == 0 && cd2 == 0) {
        if (max(a.x, b.x) < min(c.x, d.x)) return false;
        if (max(c.x, d.x) < min(a.x, b.x)) return false;
        if (max(a.y, b.y) < min(c.y, d.y)) return false;
        if (max(c.y, d.y) < min(a.y, b.y)) return false;
        return true;
    }

    return ab1 * ab2 <= 0 && cd1 * cd2 <= 0;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int N;
    cin >> N;

    vector<Segment> seg(N);

    for (int i = 0; i < N; i++) {
        cin >> seg[i].a.x >> seg[i].a.y
            >> seg[i].b.x >> seg[i].b.y;
    }

    long long answer = 0;

    for (int i = 0; i < N; i++) {
        for (int j = i + 1; j < N; j++) {
            if (intersect(seg[i], seg[j])) {
                answer++;
            }
        }
    }

    cout << answer;
}