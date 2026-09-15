#if 0
#include <iostream>

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

    Point a, b, c;
    cin >> a.x >> a.y;
    cin >> b.x >> b.y;
    cin >> c.x >> c.y;

    long long result = ccw(a, b, c);

    if (result > 0)
    {
        cout << "LEFT\n";
    }
    else if (result < 0)
    {
        cout << "RIGHT\n";
    }
    else
    {
        cout << "TOWARDS\n";
    }

    return 0;
}
#endif