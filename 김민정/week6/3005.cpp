#include <bits/stdc++.h>
using namespace std;

int main() {
    int n;
    cin >> n;

    long long x[10005], y[10005];

    for(int i=0; i<n; i++) {
        cin >> x[i] >> y[i];
    }

    long long sum = 0;

    for(int i=0; i<n-1; i++) {
        sum += x[i] * y[i+1] - y[i] * x[i+1];
    }

    sum += x[n-1] * y[0] - y[n-1] * x[0];

    if(sum < 0)
        sum = -sum;

    cout << fixed << setprecision(1) << sum / 2.0;

    return 0;
}
