#include "stdafx.h"
#include <iostream>
#include <vector>
#include <algorithm>

#define M 10007

using namespace std;

int main() {
	long long sum = 0;
	int N;

	cin >> N;
	vector<vector<long long>> arr(N + 1, vector<long long>(10));

	fill(arr[1].begin(), arr[1].end(), 1);

	for (int i = 2; i <= N; i++) {
		for (int j = 0; j < 10; j++) {

			for (int k = j; k < 10; k++) {
				arr[i][j] = (arr[i][j] + arr[i - 1][k]) % M;
			}
		}
	}

	for (int i = 0; i < 10; i++) {
		sum = (sum + arr[N][i]) % M;
	}
	cout << sum << '\n';


	return 0;
}