#include <algorithm>
#include <iostream>
#include <vector>
using namespace std;

using ll = long long;

vector<ll> makeSubsetSums(const vector<ll>& numbers, ll m) {
    vector<ll> sums = {0};

    for (ll number : numbers) {
        int previousSize = sums.size();

        for (int i = 0; i < previousSize; i++) {
            sums.push_back((sums[i] + number) % m);
        }
    }

    return sums;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    ll m;

    cin >> n >> m;

    vector<ll> leftNumbers;
    vector<ll> rightNumbers;

    for (int i = 0; i < n; i++) {
        ll value;
        cin >> value;

        if (i < n / 2) {
            leftNumbers.push_back(value);
        } else {
            rightNumbers.push_back(value);
        }
    }

    vector<ll> leftSums = makeSubsetSums(leftNumbers, m);
    vector<ll> rightSums = makeSubsetSums(rightNumbers, m);

    sort(rightSums.begin(), rightSums.end());

    ll answer = 0;

    for (ll leftSum : leftSums) {
        ll limit = m - 1 - leftSum;

        auto it = upper_bound(
            rightSums.begin(),
            rightSums.end(),
            limit
        );

        --it;

        answer = max(answer, leftSum + *it);
    }

    cout << answer << '\n';

    return 0;
}