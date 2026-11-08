// CodeForce 471_D. MUH and Cube Walls
#if 01
#include <iostream>
#include <vector>
using namespace std;

int main(void)
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int n, w;
    cin >> n >> w;

    vector<int> a(n);
    for (int i = 0; i < n; ++i)
    {
        cin >> a[i];
    }

    vector<int> b(w);
    for (int i = 0; i < w; ++i)
    {
        cin >> b[i];
    }

    if (w == 1)
    {
        cout << n << "\n";
        return 0;
    }

    if (n < w)
    {
        cout << 0 << "\n";
        return 0;
    }

    vector<int> diff_a(n - 1);
    for (int i = 0; i < n - 1; ++i)
    {
        diff_a[i] = a[i + 1] - a[i];
    }

    vector<int> diff_b(w - 1);
    for (int i = 0; i < w - 1; ++i)
    {
        diff_b[i] = b[i + 1] - b[i];
    }

    int m = diff_b.size();
    vector<int> pi(m, 0);
    for (int i = 1, j = 0; i < m; ++i)
    {
        while (j > 0 && diff_b[i] != diff_b[j])
        {
            j = pi[j - 1];
        }
        if (diff_b[i] == diff_b[j])
        {
            pi[i] = ++j;
        }
    }

    int ans = 0;
    int len_a = diff_a.size();
    for (int i = 0, j = 0; i < len_a; ++i)
    {
        while (j > 0 && diff_a[i] != diff_b[j])
        {
            j = pi[j - 1];
        }
        if (diff_a[i] == diff_b[j])
        {
            if (j == m - 1)
            {
                ans++;
                j = pi[j];
            }
            else
            {
                j++;
            }
        }
    }

    cout << ans << "\n";

    return 0;
}
#endif