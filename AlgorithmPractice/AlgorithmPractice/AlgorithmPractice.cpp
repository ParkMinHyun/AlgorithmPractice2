#include "stdafx.h"
#include <iostream>
#include <cstdio>
#include <vector>

using namespace std;

int N, S, input, sum = 0;
vector<int> arr;

void bruteforce(int start, int subSum) {

	if (start == N) {
		return;
	}

	if (subSum == S) {
		sum++;
	}

	for (int i = start + 1; i < N; i++) {
		bruteforce(i, subSum + arr[i]);
	}
}

int main() {
	cin >> N >> S;

	arr.resize(N);
	for (int i = 0; i < N; i++) {
		cin >> arr[i];
	}

	for (int i = 0; i < N; i++) {
		bruteforce(i, arr[i]);
	}
	cout << sum;
}