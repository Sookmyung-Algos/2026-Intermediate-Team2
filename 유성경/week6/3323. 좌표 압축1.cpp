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

    int N;
    cin >> N;

    vector<int> v1(N);
    vector<int> v2(N);

    for (int i = 0; i < N; i++)
    {
        cin >> v1[i];
        v2[i] = v1[i];
    }

    sort(v2.begin(), v2.end());
    v2.erase(unique(v2.begin(), v2.end()), v2.end());

    for (int i = 0; i < N; i++)
    {
        int compressed_val = lower_bound(v2.begin(), v2.end(), v1[i]) - v2.begin() + 1;
        cout << compressed_val << " ";
    }

    return 0;
}
#endif