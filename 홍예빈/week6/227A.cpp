// 코드포스 227A : Where do I Turn?
#include <iostream>
using namespace std;

struct Point {
    long long x, y;
};

long long ccw(Point A, Point B, Point C) {
    long long value = (B.x - A.x) * (C.y - A.y) - (B.y - A.y) * (C.x - A.x);
    if (value > 0) return 1;   // 반시계 방향 (LEFT)
    if (value < 0) return -1;  // 시계 방향 (RIGHT)
    return 0;                  // 일직선 (TOWARDS)
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    Point A, B, C;
    cin >> A.x >> A.y;
    cin >> B.x >> B.y;
    cin >> C.x >> C.y;

    long long result = ccw(A, B, C);

    if (result > 0) {
        cout << "LEFT\n";
    } else if (result < 0) {
        cout << "RIGHT\n";
    } else {
        cout << "TOWARDS\n";
    }

    return 0;
}