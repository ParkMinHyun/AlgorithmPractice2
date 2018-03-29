#include "stdafx.h"
#include <iostream>
#include <cstdio>
#include <algorithm>
#include <vector>
#include <numeric>

using namespace std;

vector<int> arr, sum;

int main() {

	int N, last = 0;
	cin >> N;

	arr.resize(N);
	sum.resize(N);

	for (int i = 0; i < N; i++) {
		cin >> arr[i];
	}

	sort(arr.begin(), arr.end());

	sum[0] = arr[0];
	for (int i = 1; i < N; i++) {
		sum[i] = sum[i - 1] + arr[i];
	}
	
	cout << accumulate(sum.begin(), sum.end(), 0) << '\n';
	return 0;
}