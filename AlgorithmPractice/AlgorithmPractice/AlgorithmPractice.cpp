#include "stdafx.h"
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;
int coin[100];

int main()
{
	int n, k;
	cin >> n >> k;

	vector<int> dp(1);

	for (int i = 0; i < n; i++) {
		cin >> coin[i];
	}

	for (int i = 1; i <= k; i++) {
		dp.push_back(10001);

		for (int j = 0; j < n; j++) {
			int before = i - coin[j];
			if (before >= 0 && dp[before] != 10001)
				dp[i] = min(dp[i], dp[before] + 1);
		}
	}

	printf("%d\n", dp[k] == 10001 ? -1 : dp[k]);
}
