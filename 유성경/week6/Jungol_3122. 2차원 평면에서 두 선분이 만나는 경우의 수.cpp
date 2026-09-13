#if 0
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

struct Point
{
    long long x;
    long long y;
};

struct Segment
{
    Point p1;
    Point p2;
};

long long ccw(Point a, Point b, Point c)
{
    long long op = a.x * b.y + b.x * c.y + c.x * a.y;
    op -= (a.y * b.x + b.y * c.x + c.y * a.x);

    if (op > 0)
    {
        return 1;
    }
    else if (op < 0)
    {
        return -1;
    }
    else
    {
        return 0;
    }
}

bool isIntersect(Segment a, Segment b)
{
    long long ab = ccw(a.p1, a.p2, b.p1) * ccw(a.p1, a.p2, b.p2);
    long long cd = ccw(b.p1, b.p2, a.p1) * ccw(b.p1, b.p2, a.p2);

    if (ab == 0 && cd == 0)
    {
        bool xIntersect = min(a.p1.x, a.p2.x) <= max(b.p1.x, b.p2.x) && min(b.p1.x, b.p2.x) <= max(a.p1.x, a.p2.x);
        bool yIntersect = min(a.p1.y, a.p2.y) <= max(b.p1.y, b.p2.y) && min(b.p1.y, b.p2.y) <= max(a.p1.y, a.p2.y);

        return xIntersect && yIntersect;
    }

    return ab <= 0 && cd <= 0;
}

int main(void)
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int N;
    cin >> N;

    vector<Segment> segments(N);
    for (int i = 0; i < N; ++i)
    {
        long long sx, sy, ex, ey;
        cin >> sx >> sy >> ex >> ey;
        segments[i].p1.x = sx;
        segments[i].p1.y = sy;
        segments[i].p2.x = ex;
        segments[i].p2.y = ey;
    }

    int answer = 0;
    for (int i = 0; i < N; ++i)
    {
        for (int j = i + 1; j < N; ++j)
        {
            if (isIntersect(segments[i], segments[j]))
            {
                answer++;
            }
        }
    }

    cout << answer << "\n";

    return 0;
}
#endif