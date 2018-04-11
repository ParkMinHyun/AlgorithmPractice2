#include "stdafx.h"
#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
#include <string.h>

using namespace std;

int N, M, map[51][51];
bool visit[51][51];

// 북동남서
int mY[4] = { -1,0,1, 0 };
int mX[4] = { 0,1,0,-1 };
int cY, cX, dir, cnt = 1;

struct Node {
	int y;
	int x;
};

void dfs(int y, int x) {

	int cleanNum = 0;
	// 네 방향 모두 청소가 이미 되있는지 검사
	for (int i = 0; i < 4; i++) {
		int nY = y + mY[i];
		int nX = x + mX[i];

		if (nY >= N || nX >= M || nY < 0 || nX < 0) {
			continue;
		}

		if (visit[nY][nX] || map[nY][nX] == 1) {
			cleanNum++;
		}
	}

	// 네 방향 모두 청소가 되있을 경우
	if (cleanNum == 4) {
		int nY = y + mY[(dir + 2) % 4];
		int nX = x + mX[(dir + 2) % 4];
		// 뒤에가 벽인 경우
		if (map[nY][nX] == 1) {
			return;
		}
		// 하지만, 뒤에가 벽이 아닌 경우
		else {
			dfs(nY, nX);
		}
	}
	else {
		// 일반적인 경우, 왼쪽 검사
		dir = (dir + 3) % 4;
		int nY = y + mY[dir];
		int nX = x + mX[dir];

		if (nY >= N || nX >= M || nY < 0 || nX < 0 || visit[nY][nX] || map[nY][nX] == 1) {
			dfs(y, x);
		}
		else {
			cnt++;
			visit[nY][nX] = true;
			dfs(nY, nX);
		}
	}
}
int main() {
	cin >> N >> M;
	cin >> cY >> cX >> dir;

	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			cin >> map[i][j];
		}
	}

	visit[cY][cX] = true;

	dfs(cY, cX);
	cout << cnt;
}