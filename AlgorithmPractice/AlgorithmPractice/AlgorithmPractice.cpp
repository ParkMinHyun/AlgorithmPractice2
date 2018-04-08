#include "stdafx.h"
#include <iostream>
#include <cstdio>
#include <vector>
#include <queue>
#include <string>

using namespace std;

int mX[4] = { -1,1,0,0 };
int mY[4] = { 0,0,1,-1 };

int H, W, startX, startY, cnt = 1;
bool check[51][51];
bool mul[51][51];

vector<string> pan;
queue<pair<int, int>> mQ;

void expand() {
	
	int mQSize = mQ.size();

	for(int i=0; i<mQSize; i++) {
		int cY = mQ.front().first;
		int cX = mQ.front().second;

		mQ.pop();

		for (int i = 0; i < 4; i++) {
			int nY = cY + mY[i];
			int nX = cX + mX[i];

			if (nY >= H || nX >= W || nY < 0 || nX < 0 || pan[nY][nX] == 'X' || check[nY][nX] || pan[nY][nX] == 'D') {
				continue;
			}

			if (!mul[nY][nX]) {
				mul[nY][nX] = true;
				mQ.push(make_pair(nY, nX));
			}
		}
	}
}

bool bfs() {

	queue<pair<int, int>> q;
	q.push(make_pair(startY, startX));
	check[startY][startX] = true;

	while (!q.empty()) {
		expand();
		int qSize = q.size();
		for (int i = 0; i < qSize; i++) {
			int cY = q.front().first;
			int cX = q.front().second;
			q.pop();
	
			for (int i = 0; i < 4; i++) {
				int nY = cY + mY[i];
				int nX = cX + mX[i];

				if (nY >= H || nX >= W || nY < 0 || nX < 0 || pan[nY][nX] == 'X' || mul[nY][nX]) {
					continue;
				}

				if (pan[nY][nX] == 'D') {
					return true;
				}

				if (!check[nY][nX]) {
					//cout << "이동" << cY << "," << cX << "에서 " << nY << "," << nX << endl;
					q.push(make_pair(nY, nX));
					check[nY][nX] = true;
				}
			}
		}
		cnt++;
	}
	return false;
}

int main()
{
	cin >> H >> W;

	pan.resize(H);
	for (int i = 0; i < H; i++) {
		cin >> pan[i];
	}

	for (int i = 0; i < H; i++) {
		for (int j = 0; j < W; j++) {
			if (pan[i][j] == 'S') {
				startY = i;
				startX = j;
			}
			else if (pan[i][j] == '*') {
				mul[i][j] = true;
				mQ.push(make_pair(i, j));
			}
		}
	}

	if (bfs()) {
		cout << cnt;
	}
	else {
		cout << "KAKTUS";
	}
}