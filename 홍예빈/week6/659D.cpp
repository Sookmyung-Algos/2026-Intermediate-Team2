// 코드포스 659D : Bicycle Race
#include <iostream>
#include <vector>

using namespace std;

struct Point {
    long long x, y;
};

long long ccw(Point A, Point B, Point C) {
    long long value = (B.x - A.x) * (C.y - A.y) - (B.y - A.y) * (C.x - A.x);
    if (value > 0) return 1;   // 우회전 (위험한 코너)
    if (value < 0) return -1;  // 좌회전 (안전)
    return 0;
}

int main() {
    // Fast I/O
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n;
    cin >> n;

    vector<Point> pts(n + 1);
    for (int i = 0; i <= n; i++) {
        cin >> pts[i].x >> pts[i].y;
    }

    int dangerous_turns = 0;

    // 0부터 n-2까지 순회하며 (pts[i], pts[i+1], pts[i+2]) 검사
    for (int i = 0; i < n - 1; i++) {
        if (ccw(pts[i], pts[i + 1], pts[i + 2]) > 0) {
            dangerous_turns++;
        }
    }

    cout << dangerous_turns << "\n";

    return 0;
}