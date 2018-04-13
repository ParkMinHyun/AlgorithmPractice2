#include "stdafx.h"
#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>

using namespace std;

struct Node {
	int y;
	int x;
	int zeroY;
	int zeroX;
	vector<vector<int>> v;
};

int result[3][3] = { {1,2,3},{4,5,6},{7,8,0} };
int mY[4] = { 1,-1,0,0 };
int mX[4] = { 0,0,1,-1 };
vector<vector<int>> puzzle(3, vector<int>(3));
queue<Node> q;

bool check(vector<vector<int>> p) {
	for (int i = 0; i < 3; i++) {
		for (int j = 0; j < 3; j++) {
			if (p[i][j] != result[i][j]) {
				return false;
			}
		}
	}
	return true;
}

bool rangeCheck(int nY, int nX) {
	if (nY >= 3 || nX >= 3 || nY < 0 || nX < 0) {
		return false;
	}
	return true;
}

int bfs() {
	int cnt = 1;
	while (!q.empty()) {
		int qSize = q.size();
		for (int i = 0; i < qSize; i++) {
			int cY = q.front().y;
			int cX = q.front().x;
			int zeroY = q.front().zeroY;
			int zeroX = q.front().zeroX;
			vector<vector<int>> cV = q.front().v;
			q.pop();

			// swap 하기
			swap(cV[cY][cX], cV[zeroY][zeroX]);
			// swap 결과 체크하기
			if (check(cV)) {
				return cnt;
			}
			// 아직도 정답이 아니면 다시 인접점 검사
			else {
				for (int j = 0; j < 4; j++) {
					int nY = cY + mY[j];
					int nX = cX + mX[j];

					if (nY == zeroY && nX == zeroX) {
						continue;
					}

					if (rangeCheck(nY, nX)) {
						q.push({ nY,nX,cY,cX,cV });
					}
				}
			}
		}
		cnt++;
	}

	return cnt;
}
int main() {

	for (int i = 0; i < 3; i++) {
		for (int j = 0; j < 3; j++) {
			cin >> puzzle[i][j];
		}
	}

	// zero 체크 및 인접점 담기
	for (int i = 0; i < 3; i++) {
		for (int j = 0; j < 3; j++) {
			if (puzzle[i][j] == 0) {
				for (int k = 0; k < 4; k++) {
					int nY = i + mY[k];
					int nX = j + mX[k];
					if (rangeCheck(nY, nX)) {
						q.push({ nY,nX,i,j ,puzzle });
					}
				}
			}
		}
	}

	cout << (!check(puzzle)) ? bfs() : 0;
	return 0;
}
