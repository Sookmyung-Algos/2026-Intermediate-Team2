// 정올 3122 : 2차원 평면에서 두 선분이 만나는 경우의 수
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

struct Point {
    long long x, y;

    bool operator<(const Point& p) const {
        if (x != p.x) return x < p.x;
        return y < p.y;
    }
    bool operator<=(const Point& p) const {
        return !(p < *this);
    }
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

// 선분 교차 판정 함수 (끝점 닿기 및 일직선 포개짐 포함)
bool isIntersect(Point A, Point B, Point C, Point D) {
    long long ab = ccw(A, B, C) * ccw(A, B, D);
    long long cd = ccw(C, D, A) * ccw(C, D, B);

    // 두 선분이 일직선상에 위치하는 예외 처리
    if (ab == 0 && cd == 0) {
        if (B < A) swap(A, B);
        if (D < C) swap(C, D);
        return (A <= D && C <= B);
    }

    return (ab <= 0 && cd <= 0);
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int N;
    cin >> N;

    vector<Segment> segs(N);
    for (int i = 0; i < N; i++) {
        cin >> segs[i].p1.x >> segs[i].p1.y >> segs[i].p2.x >> segs[i].p2.y;
    }

    long long count = 0;

    // 모든 선분 쌍(i, j)을 비교 (O(N^2))
    for (int i = 0; i < N; i++) {
        for (int j = i + 1; j < N; j++) {
            if (isIntersect(segs[i].p1, segs[i].p2, segs[j].p1, segs[j].p2)) {
                count++;
            }
        }
    }

    cout << count << "\n";

    return 0;
}