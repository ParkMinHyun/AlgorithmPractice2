#include "stdafx.h"
#include <iostream>
#include <cstdio>
#include <algorithm>
#include <vector>
#include <string>

using namespace std;

vector<int> DP;
vector<int> fodo;

int main() {
	int N, input;
	cin >> N;

	fodo.resize(N + 1);
	DP.resize(N + 1);
	for (int i = 1; i <= N; i++) {
		cin >> fodo[i];
	}

	DP[0] = 0;
	DP[1] = fodo[1];
	DP[2] = fodo[1] + fodo[2];

	for (int i = 3; i <= N; i++) {
		DP[i] = max(max(DP[i - 3] + fodo[i - 1] + fodo[i], DP[i - 1]), DP[i - 2] + fodo[i]);
	}

	cout << DP[N];

	return 0;
}