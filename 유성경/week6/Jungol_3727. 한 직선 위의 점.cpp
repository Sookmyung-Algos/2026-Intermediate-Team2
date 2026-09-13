#if 0
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

long long get_abs(long long x)
{
    if (x < 0)
    {
        return -x;
    }
    return x;
}

long long get_gcd(long long a, long long b)
{
    while (b != 0)
    {
        long long r = a % b;
        a = b;
        b = r;
    }
    return a;
}

struct Point
{
    long long x;
    long long y;
};

struct Slope
{
    long long dy;
    long long dx;

    bool operator<(const Slope& other) const
    {
        if (dy == other.dy)
        {
            return dx < other.dx;
        }
        return dy < other.dy;
    }

    bool operator==(const Slope& other) const
    {
        return dy == other.dy && dx == other.dx;
    }
};

int main(void)
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int N;
    cin >> N;

    if (N <= 2)
    {
        cout << N << "\n";
        return 0;
    }

    vector<Point> points(N);
    for (int i = 0; i < N; ++i)
    {
        cin >> points[i].x >> points[i].y;
    }

    int max_points = 2;

    for (int i = 0; i < N; ++i)
    {
        vector<Slope> slopes;
        for (int j = i + 1; j < N; ++j)
        {
            long long dy = points[j].y - points[i].y;
            long long dx = points[j].x - points[i].x;

            if (dx == 0)
            {
                dy = 1;
            }
            else if (dy == 0)
            {
                dx = 1;
            }
            else
            {
                if (dx < 0)
                {
                    dx = -dx;
                    dy = -dy;
                }

                long long g = get_gcd(get_abs(dy), get_abs(dx));
                dy /= g;
                dx /= g;
            }

            Slope s;
            s.dy = dy;
            s.dx = dx;
            slopes.push_back(s);
        }

        if (!slopes.empty())
        {
            sort(slopes.begin(), slopes.end());
            int current_max = 1;
            int count = 1;

            for (size_t k = 1; k < slopes.size(); ++k)
            {
                if (slopes[k] == slopes[k - 1])
                {
                    count++;
                }
                else
                {
                    if (count > current_max)
                    {
                        current_max = count;
                    }
                    count = 1;
                }
            }

            if (count > current_max)
            {
                current_max = count;
            }

            if (current_max + 1 > max_points)
            {
                max_points = current_max + 1;
            }
        }
    }

    cout << max_points << "\n";

    return 0;
}
#endif