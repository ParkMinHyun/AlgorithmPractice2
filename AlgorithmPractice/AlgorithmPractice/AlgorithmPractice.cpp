#include "stdafx.h"
#include <iostream>
#include <vector>

using namespace std;

int dp[10001];

int main() {
	int n, sum, coin = 0;

	cin >> n >> sum;
	dp[0] = 1;
	while (n--) {
		cin >> coin;
		for (int j = coin; j <= sum; ++j)
			dp[j] += dp[j - coin];
	}
	cout << dp[sum] << '\n';
}