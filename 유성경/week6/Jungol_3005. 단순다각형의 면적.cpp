#if 0
#include <iostream>
#include <vector>

using namespace std;

struct Point
{
    long long x;
    long long y;
};

int main(void)
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int N;
    cin >> N;

    vector<Point> points(N);
    for (int i = 0; i < N; ++i)
    {
        cin >> points[i].x >> points[i].y;
    }

    long long area2 = 0;
    for (int i = 0; i < N; ++i)
    {
        int j = (i + 1) % N;
        area2 += points[i].x * points[j].y;
        area2 -= points[i].y * points[j].x;
    }

    if (area2 < 0)
    {
        area2 = -area2;
    }

    cout << fixed;
    cout.precision(1);
    cout << (double)area2 / 2.0 << "\n";

    return 0;
}
#endif