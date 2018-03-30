#include "stdafx.h"
#include <cstdio>
#include <iostream>

using namespace std;

int main() {

	long long v[10001];
	int K, N;
	long long sum = 0, mid, left, right, result = 0;

	cin >> K >> N;

	for (int i = 0; i < K; i++) {
		cin >> v[i];
	}

	left = 0;
	right = v[0];

	while (left <= right) {
		sum = 0;
		mid = (left + right) / 2;

		for (int i = 0; i < K; i++) {
			sum += v[i] / mid;
		}

		if (sum >= N) {
			left = mid + 1;
			if (mid > result) {
				result = mid;
			}
		}
		else {
			right = mid - 1;
		}
	}
	cout << result;
}