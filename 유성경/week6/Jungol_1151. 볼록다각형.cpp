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

long long ccw(Point a, Point b, Point c)
{
    long long op = a.x * b.y + b.x * c.y + c.x * a.y;
    op -= (a.y * b.x + b.y * c.x + c.y * a.x);
    return op;
}

bool compare(Point a, Point b)
{
    if (a.x == b.x)
    {
        return a.y < b.y;
    }

    return a.x < b.x;
}

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

    sort(points.begin(), points.end(), compare);

    vector<Point> lower;
    for (int i = 0; i < N; ++i)
    {
        while (lower.size() >= 2 && ccw(lower[lower.size() - 2], lower.back(), points[i]) <= 0)
        {
            lower.pop_back();
        }
        lower.push_back(points[i]);
    }

    vector<Point> upper;
    for (int i = N - 1; i >= 0; --i)
    {
        while (upper.size() >= 2 && ccw(upper[upper.size() - 2], upper.back(), points[i]) <= 0)
        {
            upper.pop_back();
        }
        upper.push_back(points[i]);
    }

    vector<Point> hull;
    for (int i = 0; i < lower.size() - 1; ++i)
    {
        hull.push_back(lower[i]);
    }
    for (int i = 0; i < upper.size() - 1; ++i)
    {
        hull.push_back(upper[i]);
    }

    long long area2 = 0;
    int h = hull.size();
    for (int i = 0; i < h; ++i)
    {
        int j = (i + 1) % h;
        area2 += hull[i].x * hull[j].y;
        area2 -= hull[i].y * hull[j].x;
    }

    if (area2 < 0)
    {
        area2 = -area2;
    }

    if (area2 % 2 == 0)
    {
        cout << area2 / 2 << "\n";
    }
    else
    {
        cout << area2 / 2 << ".5\n";
    }

    return 0;
}
#endif