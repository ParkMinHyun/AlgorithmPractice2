#include "stdafx.h"
#include <iostream>
#include <cstdio>
#include <vector>
#include <algorithm>
#include <string>

using namespace std;

int H, W, nMax;
string arr[21];
bool check[26];

int mY[4] = { -1,1,0,0 };
int mX[4] = { 0,0,1,-1 };

void dfs(int y, int x, char ch, int cnt) {

	nMax = max(cnt, nMax);

	for (int i = 0; i < 4; i++) {
		int nY = y + mY[i];
		int nX = x + mX[i];

		if (nX < 0 || nX >= W || nY < 0 || nY >= H) {
			continue;
		}

		if (!check[arr[nY][nX] - 'A']) {
			check[arr[nY][nX] - 'A'] = true;
			dfs(nY, nX, arr[nX][nY], cnt + 1);
			check[arr[nY][nX] - 'A'] = false;
		}

	}
}

int main() {
	cin >> H >> W;

	for (int i = 0; i < H; i++) {
		cin >> arr[i];
	}

	check[arr[0][0] - 'A'] = true;
	dfs(0, 0, arr[0][0], 1);
	cout << nMax;
}