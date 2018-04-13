#include "stdafx.h"
#include <iostream>
#include <cstdio>
#include <queue>
#include <algorithm>

using namespace std;

struct Node {
	int y;
	int x;
	int num;
};
int map[11][11];
int N, M, C, nMax, subMax;
vector<Node> arr, nV;

// y 위치, 계산 값, 남은 양, 위치
void dfs(int y, int x, int num, int remain, int cnt) {

	subMax = max(subMax, num);

	if (cnt >= x + M - 1) {
		return;
	}

	for (int i = cnt + 1; i < x + M; i++) {
		if (remain - map[y][i] >= 0) dfs(y, x, num + map[y][i] * map[y][i], remain - map[y][i], i);
	}
}
int main() {
	int tc;
	cin >> tc;

	for (int x = 1; x <= tc; x++) {
		cin >> N >> M >> C;

		arr.clear();
		nMax = 0;
		for (int i = 0; i < N; i++) {
			for (int j = 0; j < N; j++) {
				cin >> map[i][j];
			}
		}

		for (int i = 0; i < N; i++) {
			for (int j = 0; j <= N - M; j++) {
				subMax = 0;
				for (int k = 0; k < M; k++) {
					if (map[i][j + k] <= C) dfs(i, j, map[i][j + k] * map[i][j + k], C - map[i][j + k], j + k);
				}
				arr.push_back({ i,j, subMax });
			}
		}

		int arrSize = arr.size();
		for (int i = 0; i < arrSize - 1; i++) {
			for (int j = i + 1; j < arrSize; j++) {
				if (arr[i].y == arr[j].y && (arr[i].x < arr[j].x && arr[j].x < arr[i].x + M)) {
					continue;
				}
				else {
					nMax = max(nMax, arr[i].num + arr[j].num);
				}
			}
		}
		cout << "#" << x << " " << nMax << '\n';
	}
	return 0;
}