// 코드포스 888E : Maximum Subsequence
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int n;
long long m;
vector<long long> a;
vector<long long> left_sums, right_sums;

// 절반 범위의 모든 부분집합 합 % m 을 구하는 DFS
void get_subseq_sums(int idx, int end_idx, long long current_sum, vector<long long>& target_vec) {
    if (idx == end_idx) {
        target_vec.push_back(current_sum % m);
        return;
    }
    // 1. 현재 원소를 고르지 않는 경우
    get_subseq_sums(idx + 1, end_idx, current_sum, target_vec);
    // 2. 현재 원소를 고르는 경우
    get_subseq_sums(idx + 1, end_idx, (current_sum + a[idx]) % m, target_vec);
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> n >> m;
    a.resize(n);
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }

    // Step 1: 배열을 절반으로 나누어 각각 부분집합의 합 % m 구하기
    int mid = n / 2;
    get_subseq_sums(0, mid, 0, left_sums);
    get_subseq_sums(mid, n, 0, right_sums);

    // Step 2: 오른쪽 결과를 정렬 후 중복 제거 (이분 탐색 최적화)
    sort(right_sums.begin(), right_sums.end());
    right_sums.erase(unique(right_sums.begin(), right_sums.end()), right_sums.end());

    // Step 3: Meet in the Middle - 왼쪽의 각 값 x에 대해 (m - 1 - x) 이하인 최댓값을 오른쪽에서 구함
    long long ans = 0;
    for (long long x : left_sums) {
        // (x + y) < m 인 범위에서 가장 큰 y를 찾아 (x + y) % m 최대화
        auto it = upper_bound(right_sums.begin(), right_sums.end(), m - 1 - x);
        if (it != right_sums.begin()) {
            --it;
            ans = max(ans, (x + *it) % m);
        }
        // (x + y) >= m 일 때 modulo 연산 후 가장 큰 값은 오른쪽 배열의 맨 마지막 원소와의 조합
        ans = max(ans, (x + right_sums.back()) % m);
    }

    cout << ans << "\n";

    return 0;
}