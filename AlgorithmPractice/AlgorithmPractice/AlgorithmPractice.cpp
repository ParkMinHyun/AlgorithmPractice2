#include "stdafx.h"
#include <cstdio>
#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

int main() {

	int N, input, cnt = 0, sum = 0;

	cin >> N;
	for (int i = 0; i < N; i++) {
		cin >> input;
		sum += input;
		cnt++;
	}

	while ((float)sum / cnt < 9.5) {
		sum += 10;
		cnt++;
	}

	cout << cnt - N << endl;
	return 0;
}