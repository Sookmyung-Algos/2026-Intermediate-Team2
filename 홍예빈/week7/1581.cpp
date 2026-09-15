// 정올 1581 : 두배열의 합
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

long long T;
int N, M;
vector<long long> A, B;
vector<long long> sumA, sumB;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> T;

    cin >> N;
    A.resize(N);
    for (int i = 0; i < N; i++) {
        cin >> A[i];
    }

    cin >> M;
    B.resize(M);
    for (int i = 0; i < M; i++) {
        cin >> B[i];
    }

    // Step 1: 배열 A의 모든 연속 부배열 합 구하기 (O(N^2))
    for (int i = 0; i < N; i++) {
        long long current_sum = 0;
        for (int j = i; j < N; j++) {
            current_sum += A[j];
            sumA.push_back(current_sum);
        }
    }

    // Step 2: 배열 B의 모든 연속 부배열 합 구하기 (O(M^2))
    for (int i = 0; i < M; i++) {
        long long current_sum = 0;
        for (int j = i; j < M; j++) {
            current_sum += B[j];
            sumB.push_back(current_sum);
        }
    }

    // Step 3: 이분 탐색을 위한 sumB 정렬
    sort(sumB.begin(), sumB.end());

    // Step 4: Meet in the Middle - sumA의 각 값 a에 대해 (T - a)가 sumB에 몇 개 있는지 카운트
    long long total_count = 0;
    for (long long a : sumA) {
        long long target = T - a;

        // equal_range로 target과 값이 같은 원소들의 범위(개수)를 O(log(M^2))에 탐색
        auto range = equal_range(sumB.begin(), sumB.end(), target);
        total_count += distance(range.first, range.second);
    }

    cout << total_count << "\n";

    return 0;
}