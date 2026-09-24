// CodeForce 439_D.Devu and his Brother
#if 0
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main(void)
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int n, m;
    cin >> n >> m;

    vector<long long> a(n);
    for (int i = 0; i < n; ++i)
    {
        cin >> a[i];
    }

    vector<long long> b(m);
    for (int i = 0; i < m; ++i)
    {
        cin >> b[i];
    }

    sort(a.begin(), a.end());
    sort(b.begin(), b.end(), greater<long long>());

    long long ans = 0;
    int limit = min(n, m);

    for (int i = 0; i < limit; ++i)
    {
        if (a[i] < b[i])
        {
            ans += (b[i] - a[i]);
        }
        else
        {
            break;
        }
    }

    cout << ans << "\n";

    return 0;
}
#endif