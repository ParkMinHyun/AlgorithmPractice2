#include "stdafx.h"
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main()
{
	int n;
	cin >> n;
	vector<int> arr(n);
	vector<int> sum(n + 1);

	for (int i = 0; i < n; i++) {
		cin >> arr[i];
	}

	sum[0] = 0;
	sum[1] = arr[0];
	for (int i = 2; i <= n; i++) {
		for (int j = 0; j < n; j++) {
			if (i - j <= 0) {
				continue;
			}
			if (sum[i] < sum[i - (j + 1)] + arr[j]) {
				sum[i] = sum[i - (j + 1)] + arr[j];
			}
		}
	}

	cout << sum[n] << '\n';
	return 0;
}