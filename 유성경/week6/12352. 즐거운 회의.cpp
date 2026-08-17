#if 0
#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main(void)
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int N, M, T;
    cin >> N >> M >> T;

    vector<int> a(N + 1);
    vector<int> b(N + 1);

    for (int i = 1; i <= N; i++)
    {
        cin >> a[i] >> b[i];
    }

    vector<int> diff(T + 1, 0);

    for (int i = 0; i < M; i++)
    {
        int c, d;
        cin >> c >> d;

        int s = max(a[c], a[d]);
        int e = min(b[c], b[d]);

        if (s < e)
        {
            diff[s]++;
            diff[e]--;
        }
    }

    int curr = 0;
    for (int t = 0; t < T; t++)
    {
        curr += diff[t];
        cout << curr << "\n";
    }

    return 0;
}
#endif