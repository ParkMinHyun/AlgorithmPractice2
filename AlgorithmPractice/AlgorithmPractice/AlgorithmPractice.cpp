#include "stdafx.h"
#include <iostream>
#include <vector>
#include <algorithm>

#define M 1000000000

using namespace std;

int main() {
	long long sum = 0;
	int N;

	cin >> N;
	vector<vector<long long>> arr(N + 1, vector<long long>(10));

	fill(arr[1].begin(), arr[1].end(), 1);
	arr[0][1] = 1;

	for (int i = 2; i <= N; i++) {
		for (int j = 1; j < 10; j++) {
			if (j == 1) {
				arr[i][j] = (arr[i - 1][j + 1] + arr[i - 2][j]) % M;
			}
			else if (j == 9) {
				arr[i][j] = arr[i - 1][8] % M;
			}
			else {
				arr[i][j] = (arr[i - 1][j - 1] + arr[i - 1][j + 1]) % M;
			}
		}
	}

	for (int i = 1; i < 10; i++) {
		sum = (sum + arr[N][i]) % M;
	}

	cout << sum << '\n';
	return 0;
}