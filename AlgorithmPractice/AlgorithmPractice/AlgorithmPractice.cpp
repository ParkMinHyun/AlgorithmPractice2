#include "stdafx.h"
#include <iostream>
#include <cstdio>
#include <vector>
#include <algorithm>
#include <functional>
using namespace std;

int N, M, le, ri, mid, nMax;
vector<int> arr;

void search() {

	ri = arr[0];

	while (le <= ri) {
		long long sum = 0;
		mid = (le + ri) / 2;

		for (int i = 0; i < N; i++) {
			if (arr[i] - mid > 0) {
				sum += arr[i] - mid;
			}
		}

		if (sum >= M) {
			le = mid + 1;
			if (sum == M) {
				nMax = max(nMax, mid);
				return;
			}
		}
		else {
			ri = mid - 1;
		}
	}
	nMax = (le + ri) / 2;
}

int main() {
	cin >> N >> M;
	arr.resize(N);

	for (int i = 0; i < N; i++) {
		cin >> arr[i];
	}

	sort(arr.begin(), arr.end(), greater<int>());
	search();
	cout << nMax;

}