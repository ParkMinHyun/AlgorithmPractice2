#include "stdafx.h"
#include <cstdio>
#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
#include <stack>

using namespace std;

stack<int> plusN;
queue<int> minusN;
vector<int> arr;
int main() {

	int N, sum = 0, a, b;
	cin >> N;

	arr.resize(N);
	for (int i = 0; i < N; i++) {
		cin >> arr[i];
	}

	sort(arr.begin(), arr.end());

	int arrLen = arr.size();
	for (int i = 0; i < arrLen; i++) {
		arr[i] > 0 ? plusN.push(arr[i]) : minusN.push(arr[i]);
	}

	while (!plusN.empty()) {
		a = plusN.top();
		plusN.pop();
		b = plusN.top();
		plusN.pop();

		a*b >= a + b ? sum += a * b : sum += a + b;
		if (plusN.size() == 1) {
			sum += plusN.top();
			break;
		}
	}

	while (!minusN.empty()) {
		a = minusN.front();
		minusN.pop();
		b = minusN.front();
		minusN.pop();
		sum += a * b;

		if (minusN.size() == 1) {
			sum += minusN.front();
			break;
		}
	}

	cout << sum;
	return 0;
}