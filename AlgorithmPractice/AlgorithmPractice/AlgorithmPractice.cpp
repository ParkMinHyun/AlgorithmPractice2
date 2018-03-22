#include "stdafx.h"
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
	int N, num;
	cin >> N;

	vector<int> sum(12);

	sum[1] = 1;
	sum[2] = 2;
	sum[3] = 4;
	while (N--) {
		cin >> num;

		for (int i = 4; i <= num; i++) {
			sum[i] = sum[i - 1] + sum[i - 2] + sum[i - 3];
		}
		cout << sum[num] << '\n';
	}
	return 0;
}