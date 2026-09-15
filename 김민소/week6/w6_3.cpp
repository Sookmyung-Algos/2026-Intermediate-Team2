#include <iostream>
#include <vector>
#include <iomanip>
#include <cmath>

using namespace std;

struct Point {
    long long x, y;
};

int main() {
    int N;
    cin >> N;

    vector<Point> p(N);

    for (int i = 0; i < N; i++) {
        cin >> p[i].x >> p[i].y;
    }

    long long sum = 0;

    for (int i = 0; i < N; i++) {
        int next = (i + 1) % N;

        sum += p[i].x * p[next].y;
        sum -= p[i].y * p[next].x;
    }

    double area = abs(sum) / 2.0;

    cout << fixed << setprecision(1) << area << '\n';

    return 0;
}