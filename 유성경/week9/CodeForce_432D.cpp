// CodeForce 432_D. Prefixes and Suffixes
#if 01
#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
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

    vector<int> cnt(n + 1, 0);
    for (int i = 0; i < n; ++i)
    {
        cnt[pi[i]]++;
    }

    for (int i = n; i >= 1; --i)
    {
        if (cnt[i] > 0 && pi[i - 1] > 0)
        {
            cnt[pi[i - 1]] += cnt[i];
        }
    }

    for (int i = 1; i <= n; ++i)
    {
        cnt[i]++;
    }

    vector<int> valid_lengths;
    int curr = n;
    while (curr > 0)
    {
        valid_lengths.push_back(curr);
        curr = pi[curr - 1];
    }

    reverse(valid_lengths.begin(), valid_lengths.end());

    cout << valid_lengths.size() << "\n";
    for (int len : valid_lengths)
    {
        cout << len << " " << cnt[len] << "\n";
    }

    return 0;
}
#endif