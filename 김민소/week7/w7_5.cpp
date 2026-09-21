#include <iostream>
#include <unordered_map>
#include <vector>
using namespace std;

using ll = long long;

int n, maxStickers, splitPoint;
ll target;
vector<ll> numbers;

ll factorialValue[19];
ll answer = 0;

unordered_map<ll, ll> rightWays[26];

void makeRightStates(int index, int usedStickers, ll sum) {
    if (sum > target || usedStickers > maxStickers) {
        return;
    }

    if (index == n) {
        rightWays[usedStickers][sum]++;
        return;
    }

    makeRightStates(index + 1, usedStickers, sum);

    if (sum + numbers[index] <= target) {
        makeRightStates(
            index + 1,
            usedStickers,
            sum + numbers[index]
        );
    }

    if (usedStickers < maxStickers &&
        numbers[index] <= 18) {

        ll nextSum =
            sum + factorialValue[numbers[index]];

        if (nextSum <= target) {
            makeRightStates(
                index + 1,
                usedStickers + 1,
                nextSum
            );
        }
    }
}

void searchLeftStates(int index, int usedStickers, ll sum) {
    if (sum > target || usedStickers > maxStickers) {
        return;
    }

    if (index == splitPoint) {
        ll requiredSum = target - sum;

        for (int rightStickers = 0;
             usedStickers + rightStickers <= maxStickers;
             rightStickers++) {

            auto it =
                rightWays[rightStickers].find(requiredSum);

            if (it != rightWays[rightStickers].end()) {
                answer += it->second;
            }
        }

        return;
    }

    searchLeftStates(index + 1, usedStickers, sum);

    if (sum + numbers[index] <= target) {
        searchLeftStates(
            index + 1,
            usedStickers,
            sum + numbers[index]
        );
    }

    if (usedStickers < maxStickers &&
        numbers[index] <= 18) {

        ll nextSum =
            sum + factorialValue[numbers[index]];

        if (nextSum <= target) {
            searchLeftStates(
                index + 1,
                usedStickers + 1,
                nextSum
            );
        }
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> n >> maxStickers >> target;

    numbers.resize(n);

    for (ll& number : numbers) {
        cin >> number;
    }

    factorialValue[0] = 1;

    for (int i = 1; i <= 18; i++) {
        factorialValue[i] =
            factorialValue[i - 1] * i;
    }

    splitPoint = n / 2;

    makeRightStates(splitPoint, 0, 0);

    searchLeftStates(0, 0, 0);

    cout << answer << '\n';

    return 0;
}