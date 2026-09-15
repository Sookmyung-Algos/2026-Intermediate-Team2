#include <bits/stdc++.h>
using namespace std;
 
long long ccw(long long x1, long long y1, long long x2, long long y2, long long x3, long long y3) {
    return (x2-x1)*(y3-y1) - (y2-y1)*(x3-x1);
}
 
int main() {
    long long ax, ay, bx, by, cx, cy;
 
    cin >> ax >> ay;
    cin >> bx >> by;
    cin >> cx >> cy;
 
    long long a = ccw(ax, ay, bx, by, cx, cy);
 
    if(a > 0)
        cout << "LEFT";
    else if(a < 0)
        cout << "RIGHT";
    else
        cout << "TOWARDS";
 
    return 0;
}
