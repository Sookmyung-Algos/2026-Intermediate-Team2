#include <bits/stdc++.h>
using namespace std;

struct Point {
    long long x, y;
};

struct Line {
    Point a, b;
};

long long ccw(Point a, Point b, Point c) {
    return (b.x-a.x)*(c.y-a.y) - (b.y-a.y)*(c.x-a.x);
}

int main() {
    int n;
    cin >> n;

    Line l[25];

    for(int i=0; i<n; i++) {
        cin >> l[i].a.x >> l[i].a.y >> l[i].b.x >> l[i].b.y;
    }

    int ans = 0;

    for(int i=0; i<n; i++) {
        for(int j=i+1; j<n; j++) {
            long long a = ccw(l[i].a, l[i].b, l[j].a);
            long long b = ccw(l[i].a, l[i].b, l[j].b);
            long long c = ccw(l[j].a, l[j].b, l[i].a);
            long long d = ccw(l[j].a, l[j].b, l[i].b);

            if(a*b < 0 && c*d < 0)
                ans++;
        }
    }

    cout << ans;

    return 0;
}
