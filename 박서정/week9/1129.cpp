#include <bits/stdc++.h>
using namespace std;

struct Point {
    long long x, y;
};

struct Segment {
    Point a, b;
};

long long ccw(Point a, Point b, Point c) {
    return (b.x - a.x) * (c.y - a.y)
        - (b.y - a.y) * (c.x - a.x);
}

bool intersect(Segment s1, Segment s2) {
    long long ab1 = ccw(s1.a, s1.b, s2.a);
    long long ab2 = ccw(s1.a, s1.b, s2.b);
    long long cd1 = ccw(s2.a, s2.b, s1.a);
    long long cd2 = ccw(s2.a, s2.b, s1.b);

    return ab1 * ab2 < 0 && cd1 * cd2 < 0;
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

    int answer = 0;

    for (int i = 0; i < N; i++) {
        for (int j = i + 1; j < N; j++) {
            if (intersect(seg[i], seg[j])) {
                answer++;
            }
        }
    }

    cout << answer;
}