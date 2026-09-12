// 정올 1129 : 평면내 선분의 교점
#include <iostream>
#include <vector>

using namespace std;

struct Point {
    long long x, y;
};

struct Segment {
    Point p1, p2;
};

long long ccw(Point A, Point B, Point C) {
    long long value = (B.x - A.x) * (C.y - A.y) - (B.y - A.y) * (C.x - A.x);
    if (value > 0) return 1;
    if (value < 0) return -1;
    return 0;
}

// 두 선분이 "완전히 교차"하는지 판정하는 함수
bool isStrictIntersect(Segment S1, Segment S2) {
    long long ab = ccw(S1.p1, S1.p2, S2.p1) * ccw(S1.p1, S1.p2, S2.p2);
    long long cd = ccw(S2.p1, S2.p2, S1.p1) * ccw(S2.p1, S2.p2, S1.p2);

    // 완전히 교차하려면 양쪽 모두 CCW 곱이 엄격하게 음수(< 0)
    return (ab < 0 && cd < 0);
}

int main() {
    // Fast I/O
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int N;
    cin >> N;

    vector<Segment> segs(N);
    for (int i = 0; i < N; i++) {
        cin >> segs[i].p1.x >> segs[i].p1.y >> segs[i].p2.x >> segs[i].p2.y;
    }

    int intersection_count = 0;

    // 모든 선분 쌍(i, j)을 비교
    for (int i = 0; i < N; i++) {
        for (int j = i + 1; j < N; j++) {
            if (isStrictIntersect(segs[i], segs[j])) {
                intersection_count++;
            }
        }
    }

    cout << intersection_count << "\n";

    return 0;
}