#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

struct Point {
    long long x, y;
};

struct Line {
    Point a, b;
};

int ccw(Point a, Point b, Point c) {
    long long cross =
        (b.x - a.x) * (c.y - a.y)
        - (b.y - a.y) * (c.x - a.x);

    if (cross > 0) return 1;
    if (cross < 0) return -1;
    return 0;
}

bool intersect(Line l1, Line l2) {
    Point A = l1.a;
    Point B = l1.b;
    Point C = l2.a;
    Point D = l2.b;

    int ab1 = ccw(A, B, C);
    int ab2 = ccw(A, B, D);

    int cd1 = ccw(C, D, A);
    int cd2 = ccw(C, D, B);

    
    if (ab1 == 0 && ab2 == 0) {
        
        bool xOverlap =
            max(min(A.x, B.x), min(C.x, D.x))
            <=
            min(max(A.x, B.x), max(C.x, D.x));

        bool yOverlap =
            max(min(A.y, B.y), min(C.y, D.y))
            <=
            min(max(A.y, B.y), max(C.y, D.y));

        return xOverlap && yOverlap;
    }

    return ab1 * ab2 <= 0 && cd1 * cd2 <= 0;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int N;
    cin >> N;

    vector<Line> lines(N);

    for (int i = 0; i < N; i++) {
        cin >> lines[i].a.x >> lines[i].a.y
            >> lines[i].b.x >> lines[i].b.y;
    }

    long long answer = 0;

    for (int i = 0; i < N; i++) {
        for (int j = i + 1; j < N; j++) {
            if (intersect(lines[i], lines[j])) {
                answer++;
            }
        }
    }

    cout << answer << '\n';

    return 0;
}