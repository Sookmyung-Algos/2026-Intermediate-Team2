// CodeForce 1016_B. Segment Occurrences
#if 01
#include <iostream>
#include <string>
#include <vector>
using namespace std;

int main(void)
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int n, m, q;
    cin >> n >> m >> q;

    string s, t;
    cin >> s >> t;

    vector<int> match(n + 1, 0);
    for (int i = 0; i <= n - m; ++i)
    {
        if (s.substr(i, m) == t)
        {
            match[i + 1] = 1;
        }
    }

    vector<int> pref(n + 1, 0);
    for (int i = 1; i <= n; ++i)
    {
        pref[i] = pref[i - 1] + match[i];
    }

    while (q--)
    {
        int l, r;
        cin >> l >> r;

        if (r - l + 1 < m)
        {
            cout << 0 << "\n";
        }
        else
        {
            int valid_r = r - m + 1;
            cout << pref[valid_r] - pref[l - 1] << "\n";
        }
    }

    return 0;
}
#endif