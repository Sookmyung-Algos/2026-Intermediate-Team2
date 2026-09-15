#include <bits/stdc++.h>
using namespace std;

struct Point {
    long long x, y;

    bool operator<(const Point& p) const {
        if(x != p.x) return x < p.x;
        return y < p.y;
    }
};

struct Line {
    Point a, b;
};

int ccw(Point a, Point b, Point c) {
    long long v = (b.x-a.x)*(c.y-a.y) - (b.y-a.y)*(c.x-a.x);

    if(v > 0) return 1;
    if(v < 0) return -1;
    return 0;
}

bool meet(Point a, Point b, Point c, Point d) {
    int ab1 = ccw(a, b, c);
    int ab2 = ccw(a, b, d);
    int cd1 = ccw(c, d, a);
    int cd2 = ccw(c, d, b);

    if(ab1 == 0 && ab2 == 0 && cd1 == 0 && cd2 == 0) {
        if(b < a) swap(a, b);
        if(d < c) swap(c, d);

        if(b < c || d < a) return false;
        return true;
    }

    return ab1 * ab2 <= 0 && cd1 * cd2 <= 0;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int n;
    cin >> n;

    Line l[10005];

    for(int i=0; i<n; i++) {
        cin >> l[i].a.x >> l[i].a.y >> l[i].b.x >> l[i].b.y;
    }

    long long ans = 0;

    for(int i=0; i<n; i++) {
        for(int j=i+1; j<n; j++) {
            if(meet(l[i].a, l[i].b, l[j].a, l[j].b))
                ans++;
        }
    }

    cout << ans;

    return 0;
}
