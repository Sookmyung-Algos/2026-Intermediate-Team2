#include <iostream>
#include <vector>
using namespace std;

struct Point {
    long long x, y;
};

int main() {
    int n;
    cin >> n;

    vector<Point> p(n + 1);

    for (int i = 0; i <= n; i++) {
        cin >> p[i].x >> p[i].y;
    }

    int answer = 0;

    for (int i = 1; i < n; i++) {
        long long x1 = p[i].x - p[i - 1].x;
        long long y1 = p[i].y - p[i - 1].y;

        long long x2 = p[i + 1].x - p[i].x;
        long long y2 = p[i + 1].y - p[i].y;

        long long cross = x1 * y2 - y1 * x2;

        if (cross > 0) {
            answer++;
        }
    }

    cout << answer << '\n';

    return 0;
}