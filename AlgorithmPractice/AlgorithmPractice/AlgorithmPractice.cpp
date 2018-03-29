#include "stdafx.h"
#include <iostream>
#include <cstdio>
#include <algorithm>
#include <vector>

using namespace std;

vector<pair<int, int>> arr;

int main() {

	int N, sum = 0, last = 0;
	cin >> N;

	arr.resize(N);

	for (int i = 0; i < N; i++) {
		cin >> arr[i].second >> arr[i].first;
	}

	sort(arr.begin(), arr.end());

	for (int i = 0; i < N; i++) {
		if (arr[i].second >= last) {
			last = arr[i].first; 
			sum++;
		}
	}

	cout << sum << '\n';
	return 0;
}