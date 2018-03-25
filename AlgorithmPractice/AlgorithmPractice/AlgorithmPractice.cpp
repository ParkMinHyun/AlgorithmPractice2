#include "stdafx.h"
#include <iostream>
#include <vector>

using namespace std;

vector<long long> arr;

int main() {

	int N;
	cin >> N;

	if (N == 1) {
		cout << 1 << '\n';
		return 0;
	}

	arr.resize(N+1);
	
	arr[1] = 1;
	arr[2] = 1;

	for (int i = 3; i <= N; i++) {
		arr[i] = arr[i - 1] + arr[i - 2];
	}

	cout << arr[N] << '\n';

	return 0;
}