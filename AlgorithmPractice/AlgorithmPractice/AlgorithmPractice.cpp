#include "stdafx.h"
#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
#include <string.h>

using namespace std;
int T, N, K, sLen;
int M[9][9];
bool check[9][9];
bool hoo;

int mY[4] = { 1,-1,0,0 };
int mX[4] = { 0,0,1,-1 };
queue<pair<int, int>> hQ;

void dfs(int y, int x, int cnt) {

	sLen = max(sLen, cnt);

	for (int i = 0; i < 4; i++) {
		int nY = mY[i] + y;
		int nX = mX[i] + x;
		int cH = M[nY][nX];

		if (nY >= N || nX >= N || nY < 0 || nX < 0 || check[nY][nX]) {
			continue;
		}

		if (M[y][x] <= M[nY][nX] && M[nY][nX] < M[y][x] + K && !hoo) {
			M[nY][nX] = M[y][x] - 1;
			check[nY][nX] = true;
			hoo = true;
			dfs(nY, nX, cnt + 1);
			check[nY][nX] = false;
			M[nY][nX] = cH;
			hoo = false;
		}
		else if (M[y][x] > M[nY][nX]) {
			check[nY][nX] = true;
			dfs(nY, nX, cnt + 1);
			check[nY][nX] = false;
		}
	}
}

int main()
{
	cin >> T;
	for (int a = 1; a <= T; a++) {
		sLen = 0;
		cin >> N >> K;

		int nMax = 0;
		for (int i = 0; i < N; i++) {
			for (int j = 0; j < N; j++) {
				cin >> M[i][j];
				nMax = max(nMax, M[i][j]);
			}
		}
		for (int i = 0; i < N; i++) {
			for (int j = 0; j < N; j++) {
				if (M[i][j] == nMax) {
					hQ.push(make_pair(i, j));
				}
			}
		}

		while (!hQ.empty()) {
			memset(check, false, sizeof(check));

			int cY = hQ.front().first;
			int cX = hQ.front().second;
			check[cY][cX] = true;
			dfs(cY, cX, 1);
			hQ.pop();
		}

		cout << "#" << a << ' ' << sLen << '\n';
	}
}