#include "stdafx.h"
#include <cstdio>
#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

vector<int> arr, temp;

int main() {
	int N;
	cin >> N;

	arr.resize(N);
	for (int i = 0; i < N; i++) {
		cin >> arr[i];
	}

	temp = arr;
	// +,- 일 때
	for (int i = 0; i < temp.size() - 1; i++) {
		if (i % 2 == 0) {
			if (temp[i] > temp[i + 1]) {
				temp.erase(temp.begin() + i);
				i--;
			}
		}
		else {
			if (temp[i] < temp[i + 1]) {
				temp.erase(temp.begin() + i);
				i--;
			}
		}
	}
	int sizeA = temp.size();

	temp = arr;
	// -,+ 일 때
	for (int i = 0; i < temp.size() - 1; i++) {
		if (i % 2 == 0) {
			if (temp[i] < temp[i + 1]) {
				temp.erase(temp.begin() + i);
				i--;
			}
		}
		else {
			if (temp[i] > temp[i + 1]) {
				temp.erase(temp.begin() + i);
				i--;
			}
		}
	}

	int sizeB = temp.size();
	sizeA = max(sizeA, sizeB);

	cout << sizeA << endl;

	return 0;
}