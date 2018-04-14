#include "stdafx.h"
#include <iostream>
#include <cstdio>
#include <queue>
#include <string.h>

using namespace std;

struct Node {
	int index;
	int dir;
};
int tc, K, index, dir;
vector<vector<int>> wheel(5, vector<int>(8));

void dfs(int index, int num, int pos, int dir) {
	// 범위 초과시 return;
	if (index >= 5 || index < 0) {
		return;
	}

	if (num == wheel[index][(pos + 4) % 8]) {
		return;
	}

	// 오른쪽 방향일 경우
	if (pos == 2) {
		dfs(index + 1, wheel[index][2], 2, -dir);
	}
	else{
		dfs(index - 1, wheel[index][6], 6, -dir);
	}

	// 왼쪽 방향일 경우
	if (-dir == 1) {
		rotate(wheel[index].rbegin(), wheel[index].rbegin() + 1, wheel[index].rend());
	}
	else {
		rotate(wheel[index].begin(), wheel[index].begin() + 1, wheel[index].end());
	}
}

int main() {
	cin >> tc;

	for (int x = 1; x <= tc; x++) {
		cin >> K;

		// 입력
		for (int i = 1; i <= 4; i++) {
			for (int j = 0; j < 8; j++) {
				cin >> wheel[i][j];
			}
		}

		for (int i = 0; i < K; i++) {
			cin >> index >> dir;

			// 오른쪽
			dfs(index+1, wheel[index][2], 2, dir);
			// 왼쪽
			dfs(index-1, wheel[index][6], 6, dir);
			// 왼쪽 방향일 경우
			if (dir == 1) {
				rotate(wheel[index].rbegin(), wheel[index].rbegin() + 1, wheel[index].rend());
			}
			else {
				rotate(wheel[index].begin(), wheel[index].begin() + 1, wheel[index].end());
			}
		}

		int sum = 0;
		if (wheel[1][0] == 1) sum += 1;
		if (wheel[2][0] == 1) sum += 2;
		if (wheel[3][0] == 1) sum += 4;
		if (wheel[4][0] == 1) sum += 8;
		cout << "#" << x << " " << sum << '\n';
	}
	return 0;
}