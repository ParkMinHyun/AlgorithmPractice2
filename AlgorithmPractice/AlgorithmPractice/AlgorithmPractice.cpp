#include "stdafx.h"
#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>

using namespace std;

int main(void) {

	int sum;

	int A, P;
	vector<int> arr;

	cin >> A >> P;
	arr.push_back(A);

	int cnt = 0;
	while (true) {
		sum = 0;

		int temp = arr[cnt++];
		while (temp) {

			int digit = temp % 10;
			sum += pow(digit, P);
			temp /= 10;
		}

		auto it = find(arr.begin(), arr.end(), sum);

		if (it != arr.end()) {
			arr.erase(it, arr.end());
			break;
		}
		else {
			arr.push_back(sum);
		}
	}

	cout << arr.size() << endl;
	return 0;
}