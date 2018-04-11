#include "stdafx.h"
#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
#include <string.h>

using namespace std;

int N, M, map[9][9], nMax;
int temp[9][9];
bool visit[9][9];

int mY[4] = { 1,-1,0,0 };
int mX[4] = { 0,0,1,-1 };

struct Node {
	int y;
	int x;
};

vector<Node> emptyV;
vector<Node> virusV;

int getEmpty() {
	int cnt = 0;
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			if (temp[i][j] == 0) {
				cnt++;
			}
		}
	}
	return cnt;
}

int bfs() {
	queue<Node> q;

	for (Node n : virusV) {
		q.push({ n.y,n.x });
		visit[n.y][n.x] = true;
	}

	while (!q.empty()) {
		int cY = q.front().y;
		int cX = q.front().x;
		q.pop();

		for (int i = 0; i < 4; i++) {
			int nY = cY + mY[i];
			int nX = cX + mX[i];

			if (nY < 0 || nX < 0 || nY >= N || nX >= M || visit[nY][nX]) {
				continue;
			}

			if (temp[nY][nX] == 0) {
				temp[nY][nX] = 2;
				visit[nY][nX] = true;
				q.push({ nY,nX });
			}
		}
	}
	return getEmpty();
}

void swap() {
	for (int a = 0; a < N; a++) {
		for (int b = 0; b < M; b++) {
			temp[a][b] = map[a][b];
		}
	}
}

int main() {
	cin >> N >> M;

	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			cin >> map[i][j];
			// 0인 곳만 vector에 넣기
			if (map[i][j] == 0) {
				emptyV.push_back({ i, j });
			}
			else if (map[i][j] == 2) {
				virusV.push_back({ i, j });
			}
		}
	}

	swap();

	int cnt = 0;
	for (int i = 0; i < emptyV.size() - 2; i++) {
		for (int j = i + 1; j < emptyV.size() - 1; j++) {
			for (int k = j + 1; k < emptyV.size(); k++) {

				int oneY = emptyV[i].y;
				int oneX = emptyV[i].x;

				int twoY = emptyV[j].y;
				int twoX = emptyV[j].x;

				int threeY = emptyV[k].y;
				int threeX = emptyV[k].x;

				temp[oneY][oneX] = 1;
				temp[twoY][twoX] = 1;
				temp[threeY][threeX] = 1;

				for (int f = 0; f < 9; f++) memset(visit[f], false, 9);
				nMax = max(nMax, bfs());
				swap();

			}
		}
	}
	cout << nMax;
}