#include "stdafx.h"
#include <iostream>
#include <algorithm>
using namespace std;

int main() {

	int N, sum;
	int R[1001] = { 0 }, G[1001] = { 0 }, B[1001] = { 0 };

	cin >> N;
	for (int i = 1; i <= N; i++) {
		cin >> R[i] >> G[i] >> B[i];
	}

	for (int i = 1; i <= N; i++) {

		R[i] = min(G[i - 1], B[i - 1]) + R[i];
		G[i] = min(R[i - 1], B[i - 1]) + G[i];
		B[i] = min(R[i - 1], G[i - 1]) + B[i];
	}

	cout << min(min(R[N], G[N]), B[N]) << '\n';

	return 0;
}