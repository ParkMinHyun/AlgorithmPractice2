#include "stdafx.h"
#include <iostream>
#include <vector>
#include <tuple>
#include <algorithm>

using namespace std;

vector<int> arr;

tuple<int, int> searchNan(int keySum) {
	for (int i = 0; i < 9; i++) {
		for (int j = i + 1; j < 9; j++) {
			if (keySum - (arr[i] + arr[j]) == 100) {
				return make_tuple(arr[i], arr[j]);
			}
		}
	}
}

int main() {

	int nan = 9;
	int keySum = 0;
	int key;

	while (nan--) {
		cin >> key;
		keySum += key;
		arr.push_back(key);
	}

	tuple<int, int> exceptNan = searchNan(keySum);
	sort(arr.begin(), arr.end());

	for (int num : arr) {
		if (num == get<0>(exceptNan) || num == get<1>(exceptNan))
			continue;
		cout << num << endl;
	}
}