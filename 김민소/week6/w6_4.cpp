#include <iostream>
#include <vector>
using namespace std;

struct Point {
    long long x, y;
};

struct Line {
    Point a, b;
};

long long ccw(Point a, Point b, Point c) {
    return (b.x - a.x) * (c.y - a.y)
         - (b.y - a.y) * (c.x - a.x);
}

bool intersect(Line l1, Line l2) {
    long long c1 = ccw(l1.a, l1.b, l2.a);
    long long c2 = ccw(l1.a, l1.b, l2.b);

    long long c3 = ccw(l2.a, l2.b, l1.a);
    long long c4 = ccw(l2.a, l2.b, l1.b);

    return c1 * c2 < 0 && c3 * c4 < 0;
}

int main() {
    int N;
    cin >> N;

    vector<Line> lines(N);

    for (int i = 0; i < N; i++) {
        cin >> lines[i].a.x >> lines[i].a.y
            >> lines[i].b.x >> lines[i].b.y;
    }

    int answer = 0;

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