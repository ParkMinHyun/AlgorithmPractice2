#include "stdafx.h"
#include <cstdio>
#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

int main() {

	int N, i, cnt = 0;

	cin >> N;
	for (i = 1; i*i < N; i++) {

		if (N%i == 0) {
			cnt++;
		}

	}

	cnt *= 2;
	if (i*i == N) {
		cnt += 1;
	}

	cout << cnt << endl;

	return 0;
}