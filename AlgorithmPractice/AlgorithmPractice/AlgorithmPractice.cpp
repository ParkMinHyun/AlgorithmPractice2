#include "stdafx.h"
#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>
using namespace std;

int main() {

	int N, temp, sum = 0;
	cin >> N;

	vector<int> arr(N);

	for (int i = 0; i < N; i++) {
		cin >> arr[i];
	}

	sort(arr.begin(), arr.end());

	do {
		temp = 0;
		for (int i = 1; i < N; i++) {
			temp += abs(arr[i] - arr[i - 1]);
		}

		if (temp > sum) {
			sum = temp;
		}

	} while (next_permutation(arr.begin(), arr.end()));
	
	cout << sum << '\n';
	return 0;
}