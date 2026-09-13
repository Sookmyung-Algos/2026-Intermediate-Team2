#include <iostream>
using namespace std;

int main() {
    long long ax, ay;
    long long bx, by;
    long long cx, cy;

    cin >> ax >> ay;
    cin >> bx >> by;
    cin >> cx >> cy;

    long long x1 = bx - ax;
    long long y1 = by - ay;

    long long x2 = cx - bx;
    long long y2 = cy - by;

    long long cross = x1 * y2 - y1 * x2;

    if (cross > 0) {
        cout << "LEFT";
    }
    else if (cross < 0) {
        cout << "RIGHT";
    }
    else {
        cout << "TOWARDS";
    }

    return 0;
}