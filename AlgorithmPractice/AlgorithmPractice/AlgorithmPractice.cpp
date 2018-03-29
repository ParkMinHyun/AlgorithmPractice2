#include "stdafx.h"
#include <iostream>
#include <cstdio>
#include <algorithm>
#include <vector>

using namespace std;

int A, B, C;
vector<vector<int>> arr;

void check(int h, int start, int aSize) {

	bool flag = true;
	int temp = arr[h][start];

	for (int i = 0; i < aSize; i++) {
		for (int j = 0; j < aSize; j++) {
			if (temp != arr[i + h][j + start]) {
				flag = false;
				break;
			}
		}
		if (!flag) {
			break;
		}
	}

	if (flag) {
		temp == -1 ? A++ : (temp == 0) ? B++ : C++;
		return;
	}

	if (aSize > 3) {
		int newSize = aSize / 3;
		for (int i = 0; i < newSize; i++) {
			for (int j = 0; j < newSize; j++) {
				check(i * newSize, j * newSize, newSize);
			}
		}
	}
	else {
		for (int i = 0; i < 3; i++) {
			for (int j = 0; j < 3; j++) {
				check(i + h, j + start, 1);
			}
		}
	}
}

int main() {
	int N;

	cin >> N;
	arr.resize(N);
	for (int i = 0; i < N; i++) {
		arr[i].resize(N);
	}

	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			cin >> arr[i][j];
		}
	}

	check(0, 0, N);
	cout << A << endl << B << endl << C << endl;
	return 0;
}