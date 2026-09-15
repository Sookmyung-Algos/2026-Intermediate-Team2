// 정올 3005 : 단순다각형의 면적
#include <iostream>
#include <vector>
#include <cmath>
#include <iomanip>

using namespace std;

struct Point {
    long long x, y;
};

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int N;
    cin >> N;

    vector<Point> pts(N);
    for (int i = 0; i < N; i++) {
        cin >> pts[i].x >> pts[i].y;
    }

    // 신발끈 공식 (Shoelace Formula)
    long long sum = 0;
    for (int i = 0; i < N; i++) {
        int next = (i + 1) % N; // 마지막 점은 첫 번째 점과 연결
        sum += (pts[i].x * pts[next].y) - (pts[next].x * pts[i].y);
    }

    // 면적 계산 (절댓값 후 2로 나누기)
    double area = abs(sum) / 2.0;

    // 소수점 첫째 자리까지 출력 (소수 둘째 자리에서 반올림)
    cout << fixed << setprecision(1) << area << "\n";

    return 0;
}