#if 0
#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <string>
using namespace std;

int main(void)
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int N, K;
    cin >> N >> K;

    string S;
    cin >> S;

    long long cnt_R = 0;
    long long cnt_L = 0;
    long long pairs = 0;

    for (int i = 0; i < K; i++)
    {
        if (S[i] == 'R')
        {
            cnt_R++;
        }
        else if (S[i] == 'L')
        {
            pairs += cnt_R;
            cnt_L++;
        }
    }

    cout << pairs * 2 << " ";

    for (int i = K; i < N; i++)
    {
        if (S[i - K] == 'R')
        {
            cnt_R--;
            pairs -= cnt_L;
        }
        else if (S[i - K] == 'L')
        {
            cnt_L--;
        }

        if (S[i] == 'R')
        {
            cnt_R++;
        }
        else if (S[i] == 'L')
        {
            pairs += cnt_R;
            cnt_L++;
        }

        cout << pairs * 2 << " ";
    }

    cout << "\n";

    return 0;
}
#endif