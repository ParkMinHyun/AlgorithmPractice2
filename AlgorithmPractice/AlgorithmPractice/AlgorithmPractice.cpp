#include "stdafx.h"
#include <iostream>
#include <cstdio>
#include <vector>
#include <string>
#include <algorithm>

using namespace std;

int N, arr[101], sum;

int twoGcd(int a, int b) {

	if (b == 0) {
		return a;
	}
	else {
		return twoGcd(b, a % b);
	}
}

int gcd(vector<int> array) {
	int result;

	if (array.size() <= 1)
		return array[0];

	result = twoGcd(array[0], array[1]);
	for (int i = 2; i < array.size(); ++i)
		result = twoGcd(result, array[i]);

	return result;
}

void bf(int pos, vector<int> sub) {

	if (sub.size() != 1 && gcd(sub) == 1) {
		sum++;
	}

	for (int i = pos + 1; i < N; i++) {
		sub.push_back(arr[i]);
		bf(i, sub);
	}
}

int main() {
	vector<int> sub;
	cin >> N;
	for (int i = 0; i < N; i++) {
		cin >> arr[i];
	}

	for (int i = 0; i < N - 1; i++) {
		sub.clear();
		sub.push_back(arr[i]);
		bf(i, sub);
	}
	cout << sum % 10000003;
}