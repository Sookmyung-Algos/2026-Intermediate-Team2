#if 0
#include <iostream>
#include <vector>

using namespace std;

struct Point
{
    long long x;
    long long y;
};

long long ccw(Point a, Point b, Point c)
{
    long long op = (b.x - a.x) * (c.y - b.y) - (b.y - a.y) * (c.x - b.x);
    return op;
}

int main(void)
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int n;
    cin >> n;

    vector<Point> points(n + 1);
    for (int i = 0; i <= n; ++i)
    {
        cin >> points[i].x >> points[i].y;
    }

    int dangerous_turns = 0;
    for (int i = 1; i < n; ++i)
    {
        if (ccw(points[i - 1], points[i], points[i + 1]) > 0)
        {
            dangerous_turns++;
        }
    }

    cout << dangerous_turns << "\n";

    return 0;
}
#endif