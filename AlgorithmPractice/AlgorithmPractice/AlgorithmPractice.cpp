#include "stdafx.h"
#include <iostream>
#include <cstdio>
#include <algorithm>
#include <vector>
#include <climits>

using namespace std;

// 음수값 나올 수 있으니 nMax는 - 최대값으로 설정해줘야 함.
int tc, N, num;

int nMax = INT_MIN, nMin = INT_MAX;
vector<int> numV, operV;

void dfs(int cnt, int res, int plus, int minus, int mul, int div) {
	if (cnt >= N) {
		nMin = min(nMin, res);
		nMax = max(nMax, res);
		return;
	}

	if (plus > 0) {
		dfs(cnt + 1, res + numV[cnt], plus - 1, minus, mul, div);
	}
	if (minus > 0) {
		dfs(cnt + 1, res - numV[cnt], plus, minus - 1, mul, div);
	}
	if (mul > 0) {
		dfs(cnt + 1, res * numV[cnt], plus, minus, mul - 1, div);
	}
	if (div > 0) {
		dfs(cnt + 1, res / numV[cnt], plus, minus, mul, div - 1);
	}
}

int main() {
	cin >> N;

	numV.resize(N);
	operV.resize(4);

	for (int i = 0; i < N; i++) {
		cin >> numV[i];
	}
	for (int i = 0; i < 4; i++) {
		cin >> operV[i];
	}

	// 사이즈, 값, 덧셈, 뺄셈, 곱셈, 나눗셈
	dfs(1, numV[0], operV[0], operV[1], operV[2], operV[3]);
	cout << nMax << '\n' << nMin << '\n';

}