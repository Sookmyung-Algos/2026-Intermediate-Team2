// CodeForce 126_B. Password
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

    string s;
    cin >> s;

    int n = s.length();
    vector<int> pi(n, 0);

    for (int i = 1, j = 0; i < n; ++i)
    {
        while (j > 0 && s[i] != s[j])
        {
            j = pi[j - 1];
        }
        if (s[i] == s[j])
        {
            pi[i] = ++j;
        }
    }

    if (pi[n - 1] == 0)
    {
        cout << "Just a legend\n";
        return 0;
    }

    int len = pi[n - 1];
    bool found = false;

    for (int i = 0; i < n - 1; ++i)
    {
        if (pi[i] >= len)
        {
            found = true;
            break;
        }
    }

    if (found)
    {
        cout << s.substr(0, len) << "\n";
    }
    else if (pi[len - 1] > 0)
    {
        cout << s.substr(0, pi[len - 1]) << "\n";
    }
    else
    {
        cout << "Just a legend\n";
    }

    return 0;
}
#endif