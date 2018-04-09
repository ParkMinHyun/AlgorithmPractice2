#include "stdafx.h"
#include <iostream>
#include <queue>
#include <string>
#include <string.h>
#include <algorithm>
#include <set>

using namespace std;

int T, N, R, sum, M[21][21];
bool visit[21][21], start;
int startX, startY, nMax;

// 오른쪽 아래, 왼쪽 아래, 왼쪽 위, 오른쪽 위
int mY[4] = { 1, 1,-1,-1 };
int mX[4] = { 1,-1,-1, 1 };

set<int> sSet;

void dfs(int y, int x, int sum, int type) {
	int nY = y + mY[type];
	int nX = x + mX[type];

	// 범위 초과인 경우
	if (nY >= N || nX >= N || nY < 0 || nX < 0) {
		return;
	}

	// 도착했을 경우
	if (type == 3 && nY == startY && nX == startX) {
		nMax = max(nMax, sum);
		return;
	}

	// 이미 있는 경우
	if (sSet.find(M[nY][nX]) != sSet.end()) {
		return;
	}

	// 백트래킹 위해 넣었다 빼주기
	sSet.insert(M[nY][nX]);

	// 처음은 그냥 ↘ 방향만 dfs 검사
	if (type == 0) {
		if (!start) {
			dfs(nY, nX, sum + 1, type);
			start = true;
		}
		// 그 다움부턴 ↙, ↘ 방향 검사
		else {
			dfs(nY, nX, sum + 1, type);
			dfs(nY, nX, sum + 1, type + 1);
		}
	}
	// ↙ 방향일 경우 ↙, ↖ 방향 검사 
	else if (type == 1 || type == 2) {
		dfs(nY, nX, sum + 1, type);
		dfs(nY, nX, sum + 1, type + 1);
	}
	// ↖ 방향일 경우 ↗ 방향 검사해서 네모 만들기
	else if (type == 3) {
		dfs(nY, nX, sum + 1, type);
	}
	sSet.erase(M[nY][nX]);
}

int main() {

	cin >> T;
	for (int i = 1; i <= T; i++) {
		cin >> N;

		for (int i = 0; i < N; i++) {
			for (int j = 0; j < N; j++) {
				cin >> M[i][j];
			}
		}

		nMax = 0;
		for (int i = 0; i < N; i++) {
			for (int j = 0; j < N; j++) {
				startY = i; startX = j;
				sSet.insert(M[i][j]);
				dfs(i, j, 1, 0);
				sSet.erase(M[i][j]);
			}
		}

		if (nMax == 0) {
			nMax = -1;
		}
		cout << "#" << i << ' ' << nMax << '\n';
	}

}