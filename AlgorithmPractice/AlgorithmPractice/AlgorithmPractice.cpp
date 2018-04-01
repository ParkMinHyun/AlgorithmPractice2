#include "stdafx.h"
#include <iostream>
#include <cstdio>
#include <vector>
#include <algorithm>
#include <cmath>
#include <climits>

using namespace std;

long long getDistance(int x1, int y1, int x2, int y2) {
	return pow(sqrt((x1 - x2)*(x1 - x2) + (y1 - y2)*(y1 - y2)), 2);
}
int main()
{
	vector<pair<int, int>> arr, brr;
	int N;
	long long sum = LLONG_MAX;

	cin >> N;
	arr.resize(N);
	brr.resize(N);

	for (int i = 0; i < N; i++) {
		cin >> arr[i].first >> arr[i].second;
		brr[i].second = arr[i].first;
		brr[i].first = arr[i].second;
	}

	sort(arr.begin(), arr.end());
	sort(brr.begin(), brr.end());

	for (int i = 0; i < N - 1; i++) {
		for (int j = 1; j < N - 2; j++) {
			sum = min(sum, getDistance(arr[i].first, arr[i].second, arr[i + j].first, arr[i + j].second));
			sum = min(sum, getDistance(brr[i].first, brr[i].second, brr[i + j].first, brr[i + j].second));
		}
	}

	cout << sum << '\n';
	return 0;
}
