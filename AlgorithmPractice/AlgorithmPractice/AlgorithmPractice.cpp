#include "stdafx.h"
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main() {

	int N, M, input;

	cin >> N >> M;
	vector<int> arr(N+M);

	for (int i = 0; i < N + M; i++) {
		scanf_s("%d", &input);
		arr[i] = input;
	}

	sort(arr.begin(), arr.end());
	for (int x : arr) {
		cout << x << ' ';
	}

	return 0;
}