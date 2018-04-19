#include "stdafx.h"
#include <iostream>
#include <cstdio>
#include <vector>

/*
* Time complexity: O(2^N)
* Space complexity: O(N^2)
*/

using namespace std;

vector<vector<long long>> memo;

long long getNum(int n, int r) {

	if (memo[n][r] > 0) {
		return memo[n][r];
	}

	if (r == 0 || n == r) {
		return memo[n][r] = 1;
	}

	return memo[n][r] = getNum(n - 1, r - 1) + getNum(n - 1, r);
}

int main()
{
	int T, N, M, K;

	cin >> T;
	while (T--) {
		cin >> N >> K >> M;

		memo.clear();
		memo.resize(N + 1);
		for (int i = 0; i < N + 1; i++) {
			memo[i].resize(N + 1);
		}

		long long a = getNum(N, M);
		long long b = getNum(N, K - M);
		cout << (a*b) % 1003001 << '\n';
	}

	return 0;
}