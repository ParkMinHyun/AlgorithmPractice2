#include "stdafx.h"
#include <iostream>
#include <queue>
#include <string>
#include <string.h>

using namespace std;

int N, H, W, R, C, L, sum, M[51][51];
bool visit[51][51], first;

struct Node {
	int cY;
	int cX;
};

// 아래, 위, 오른, 왼
int type[8][4] = { {0,0,0,0}, {1,1,1,1},{1,1,0,0},{0,0,1,1},{0,1,1,0},{1,0,1,0},{1,0,0,1},{0,1,0,1} };
int mY[4] = { 1,-1,0,0 };
int mX[4] = { 0,0,1,-1 };

int bfs() {
	int time = 1;
	queue<Node> q;

	q.push({ R, C });
	visit[R][C] = true;
	while (!q.empty()) {

		if (L == time) {
			return sum;
		}

		int dir;
		int qSize = q.size();

		for (int i = 0; i < qSize; i++) {
			int cY = q.front().cY;
			int cX = q.front().cX;
			int cType = M[cY][cX];
			q.pop();

			for (int j = 0; j < 4; j++) {
				int nY = cY + mY[j];
				int nX = cX + mX[j];
				int nextType = M[nY][nX];

				if (nY >= H || nY < 0 || nX >= W || nX < 0 || visit[nY][nX] || nextType == 0) {
					continue;
				}

				switch (j)
				{
					case 0: dir = 1; break;
					case 1: dir = 0; break;
					case 2: dir = 3; break;
					case 3: dir = 2; break;
					default: break;
				}

				// 현재 통로에서 가려는 방향과 다음 통로의 반대 방향이 둘다 뚫려 있는지 확인
				if (type[cType][j] == 1 && type[nextType][dir] == 1) {
					sum++;
					visit[nY][nX] = true;
					q.push({ nY, nX });
				}
			}
		}
		time++;
	}
	return sum;
}

int main() {

	cin >> N;
	for (int i = 1; i <= N; i++) {
		cin >> H >> W >> R >> C >> L;

		for (int i = 0; i < H; i++) {
			for (int j = 0; j < W; j++) {
				cin >> M[i][j];
			}
		}

		sum = 1;
		memset(visit, false, sizeof(visit));
		cout << "#" << i << ' ' << bfs() << '\n';
	}

}