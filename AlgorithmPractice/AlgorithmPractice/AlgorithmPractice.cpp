#include "stdafx.h"
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

vector<int> arr(100);

int eureka(int num) {
	for (int i = 1; arr[i] < num; i++) {
		for (int j = i; arr[j] < num; j++) {
			for (int k = j; arr[k] < num; k++) {
				if (num == arr[i] + arr[j] + arr[k]) {
					return 1;
				}
			}
		}
	}
	return 0;
}

void setSum() {
	int subSum = 0;
	for (int i = 1; i < 100; i++) {
		subSum += i;
		arr[i] = subSum;
	}
}

int main() {

	setSum();

	int T, K;
	cin >> T;
	while (T--) {
		cin >> K;
		cout << eureka(K) << '\n';
	}
}