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
		// 이동할 다음 점
		int nY = mY[i] + y;
		int nX = mX[i] + x;
		int cH = M[nY][nX];

		// 방문했거나 배열 범위 넘어가면 skip
		if (nY >= N || nX >= N || nY < 0 || nX < 0 || check[nY][nX]) {
			continue;
		}
		
		// 다음 이동할 산 높이가 현재 산 높이보다 클 경우 7->8 일 경우 K를 고려하기 
		// ex) K : 3일 때  6->8로 가면 
		// 6 <= 8 &&  8 < 6 + 3(k) 에 성립하면
		// 다음 이동할 산을 현재 산 높이 -1 만큼 깎기 (깎는거 최소화 시켜야 다음 이동할 범위가 많아지기 때문에)
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

		// 정점 최대 점들 갯수만큼 반복 시키기
		while (!hQ.empty()) {
			memset(check, false, sizeof(check));

			int cY = hQ.front().first;
			int cX = hQ.front().second;

			// 현재 정점 체크해주고 dfs 검사
			check[cY][cX] = true;
			dfs(cY, cX, 1);
			hQ.pop();
		}

		cout << "#" << a << ' ' << sLen << '\n';
	}
}