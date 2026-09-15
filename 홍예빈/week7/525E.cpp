// 코드포스 525E - Anya and Cubes
#include <iostream>
#include <vector>
#include <map>

using namespace std;

int n, k;
long long S;
vector<long long> a;
long long fact[20];
long long ans = 0;

// 각 (사용한 팩토리얼 스티커 개수, 합) 에 대한 경우의 수를 저장
map<long long, long long> left_map[26];

// 팩토리얼 값 미리 계산 (19! > 10^16 이므로 18까지하면 충분)
void init_fact() {
    fact[0] = 1;
    for (int i = 1; i <= 18; i++) {
        fact[i] = fact[i - 1] * i;
    }
}

// Step 1: 왼쪽 절반 탐색 (0 ~ mid - 1)
void dfs_left(int idx, int mid, int used_k, long long current_sum) {
    if (current_sum > S || used_k > k) return;
    if (idx == mid) {
        left_map[used_k][current_sum]++;
        return;
    }

    // 1. 선택하지 않는 경우
    dfs_left(idx + 1, mid, used_k, current_sum);

    // 2. 팩토리얼 없이 선택하는 경우
    dfs_left(idx + 1, mid, used_k, current_sum + a[idx]);

    // 3. 팩토리얼 적용 후 선택하는 경우 (a[idx] <= 18 일 때만 가능)
    if (a[idx] <= 18) {
        dfs_left(idx + 1, mid, used_k + 1, current_sum + fact[a[idx]]);
    }
}

// Step 2: 오른쪽 절반 탐색 및 조합 (mid ~ n - 1)
void dfs_right(int idx, int end_idx, int used_k, long long current_sum) {
    if (current_sum > S || used_k > k) return;
    if (idx == end_idx) {
        long long target_sum = S - current_sum;
        // 왼쪽에서 사용한 스티커 개수(l_k) + 오른쪽에서 사용한 스티커 개수(used_k) <= k
        for (int l_k = 0; l_k + used_k <= k; l_k++) {
            if (left_map[l_k].count(target_sum)) {
                ans += left_map[l_k][target_sum];
            }
        }
        return;
    }

    // 1. 선택하지 않는 경우
    dfs_right(idx + 1, end_idx, used_k, current_sum);

    // 2. 팩토리얼 없이 선택하는 경우
    dfs_right(idx + 1, end_idx, used_k, current_sum + a[idx]);

    // 3. 팩토리얼 적용 후 선택하는 경우
    if (a[idx] <= 18) {
        dfs_right(idx + 1, end_idx, used_k + 1, current_sum + fact[a[idx]]);
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    init_fact();

    cin >> n >> k >> S;
    a.resize(n);
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }

    int mid = n / 2;

    // 1. 왼쪽 절반 상태 백업
    dfs_left(0, mid, 0, 0);

    // 2. 오른쪽 절반 탐색하며 결과 카운트
    dfs_right(mid, n, 0, 0);

    cout << ans << "\n";

    return 0;
}