#include <bits/stdc++.h>
using namespace std;

struct Point {
    long long x, y;
};

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    Point a, b, c;

    cin >> a.x >> a.y;
    cin >> b.x >> b.y;
    cin >> c.x >> c.y;

    long long dx1 = b.x - a.x;
    long long dy1 = b.y - a.y;
    long long dx2 = c.x - b.x;
    long long dy2 = c.y - b.y;

    long long ccw = dx1 * dy2 - dy1 * dx2;

    if (ccw > 0)
        cout << "LEFT";
    else if (ccw < 0)
        cout << "RIGHT";
    else
        cout << "TOWARDS";

    return 0;
}