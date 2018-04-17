#include "stdafx.h"
#include <iostream>
#include <cstdio>
#include <vector>

using namespace std;

// 우상좌하
int mY[4] = { 0,-1,0,1 };
int mX[4] = { 1,0,-1,0 };

int map[101][101];
vector<int> v;

int getRes() {
	int sum = 0;
	for (int i = 0; i < 99; i++) {
		for (int j = 0; j < 99; j++) {
			if (map[i][j] == 1 && map[i + 1][j] == 1 && map[i][j + 1] == 1 && map[i + 1][j + 1] == 1) {
				sum++;
			}
		}
	}
	return sum;
}

void bfs(int y, int x, int dir, int time) {
	int curvN = 0, startN = 0;
	map[y][x] = 1;

	v.push_back(dir);
	int startY = y;
	int startX = x;

	while (curvN <= time) {
		int vSize = v.size();
		for (int i = startN; i < vSize; i++) {
			int nY = startY + mY[v[i]];
			int nX = startX + mX[v[i]];

			startY = nY;
			startX = nX;
			startN = i + 1;
			map[nY][nX] = 1;
		}

		for (int i = vSize - 1; i >= 0; i--) {
			v.push_back((v[i] + 1) % 4);
		}
		curvN++;
	}
}

int main() {
	int K;
	cin >> K;
	for (int i = 0; i < K; i++) {
		int y, x, dir, time;
		cin >> x >> y >> dir >> time;

		v.clear();
		bfs(y, x, dir, time);
	}

	cout << getRes() << '\n';
	return 0;
}