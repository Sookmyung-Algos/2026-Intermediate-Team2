// CodeForce 102_A.Many Equal Substrings
#if 01
#include <iostream>
#include <string>

using namespace std;

int main(void)
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int n, k;
    cin >> n >> k;

    string t;
    cin >> t;

    int overlap = 0;
    for (int len = 1; len < n; ++len)
    {
        if (t.substr(0, len) == t.substr(n - len))
        {
            overlap = len;
        }
    }

    cout << t;

    string tail = t.substr(overlap);
    for (int i = 0; i < k - 1; ++i)
    {
        cout << tail;
    }

    cout << "\n";

    return 0;
}
#endif