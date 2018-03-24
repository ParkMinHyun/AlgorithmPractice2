#include "stdafx.h"
#include <iostream>
#include <vector>
#include <bitset>
using namespace std;

int main() {
	int N, input;

	cin >> N;
	vector<bitset<16>> arr1, arr2;
	for (int i = 0; i < N; i++) {
		cin >> input;
		arr1.push_back(input);
	}

	for (int i = 0; i < N; i++) {
		cin >> input;
		arr2.push_back(input);
	}

	for (int i = 0; i < N; i++) {
		for (int j = N - 1; j >= 0; j--) {
			if (arr1[i][j] == 0 && arr2[i][j] == 0) {
				cout << " ";
			}
			else {
				cout << "#";
			}
		}
		cout << '\n';
	}

	return 0;
}