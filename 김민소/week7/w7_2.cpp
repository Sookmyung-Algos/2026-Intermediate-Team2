#include <iostream>
#include <vector>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t, n, m;

    cin >> t;

    cin >> n;
    vector<int> A(n);

    for (int i = 0; i < n; i++) {
        cin >> A[i];
    }

    cin >> m;
    vector<int> B(m);

    for (int i = 0; i < m; i++) {
        cin >> B[i];
    }
    vector<long long> countB(t + 1, 0);

    for (int start = 0; start < m; start++) {
        int sum = 0;

        for (int end = start; end < m; end++) {
            sum += B[end];

            if (sum > t) {
                break;
            }

            countB[sum]++;
        }
    }

    long long answer = 0;

    for (int start = 0; start < n; start++) {
        int sum = 0;

        for (int end = start; end < n; end++) {
            sum += A[end];

            if (sum > t) {
                break;
            }

            answer += countB[t - sum];
        }
    }

    cout << answer << '\n';

    return 0;
}