#include <bits/stdc++.h>
using namespace std;
 
struct Point {
    long long x, y;
};
 
long long ccw(Point a, Point b, Point c) {
    return (b.x-a.x)*(c.y-a.y) - (b.y-a.y)*(c.x-a.x);
}
 
int main() {
    int n;
    cin >> n;
 
    Point p[1005];
 
    for(int i=0; i<=n; i++) {
        cin >> p[i].x >> p[i].y;
    }
 
    int ans = 0;
 
    for(int i=1; i<n; i++) {
        if(ccw(p[i-1], p[i], p[i+1]) > 0)
            ans++;
    }
 
    cout << ans;
 
    return 0;
}
