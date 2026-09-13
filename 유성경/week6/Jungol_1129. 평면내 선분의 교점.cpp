#if 01
#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <vector>
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

    if (ab < 0 && cd < 0)
    {
        return true;
    }

    return false;
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
        long long x1, y1, x2, y2;
        cin >> x1 >> y1 >> x2 >> y2;
        segments[i].p1.x = x1;
        segments[i].p1.y = y1;
        segments[i].p2.x = x2;
        segments[i].p2.y = y2;
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