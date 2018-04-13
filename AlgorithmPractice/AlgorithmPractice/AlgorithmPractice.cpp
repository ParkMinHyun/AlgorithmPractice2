#include "stdafx.h"
#include <iostream>
#include <cstdio>
#include <algorithm>
#include <vector>
#include <queue>

using namespace std;

struct Node {
	int y;
	int x;
};
struct Dir {
	int time;
	char dir;
};

// 위, 아래, 오른쪽, 왼쪽
int mY[4] = { -1,1,0,0 };
int mX[4] = { 0,0,1,-1 };

int N, K, L, nMax, appleY, appleX, dir = 2;
int map[101][101], time, snakeLen = 1;
bool appleMap[101][101];

Node head;
queue<Dir> infoQ;

void changeDir(char type, int &nY, int &nX) {

	// 오른쪽 일 경우
	if (type == 'D') {
		switch (dir)
		{
		case 0: nY = head.y + mY[2]; nX = head.x + mX[2]; dir = 2; break;
		case 1: nY = head.y + mY[3]; nX = head.x + mX[3]; dir = 3; break;
		case 2: nY = head.y + mY[1]; nX = head.x + mX[1]; dir = 1; break;
		case 3: nY = head.y + mY[0]; nX = head.x + mX[0]; dir = 0; break;
		}
	}
	// 왼쪽일 경우
	else if (type == 'L') {
		switch (dir)
		{
		case 0: nY = head.y + mY[3]; nX = head.x + mX[3]; dir = 3; break;
		case 1: nY = head.y + mY[2]; nX = head.x + mX[2]; dir = 2; break;
		case 2: nY = head.y + mY[0]; nX = head.x + mX[0]; dir = 0; break;
		case 3: nY = head.y + mY[1]; nX = head.x + mX[1]; dir = 1; break;
		}
	}
}

int main() {
	ios::sync_with_stdio(false);
	cin >> N >> K;

	for (int i = 0; i < K; i++) {
		cin >> appleY >> appleX;
		appleMap[appleY-1][appleX-1] = true;
	}

	cin >> L;
	for (int i = 0; i < L; i++) {
		int time; char dir;
		cin >> time >> dir;
		infoQ.push({ time,dir });
	}

	head.y = 0; head.x = 0;

	while (true) {
		int nY, nX;
		bool dirChange = false;

		// 시간 변경 시 방향 변경
		if (!infoQ.empty()) {
			if (infoQ.front().time == time) {
				changeDir(infoQ.front().dir, nY, nX);
				dirChange = true;
				infoQ.pop();
			}
		}
		if (!dirChange) {
			nY = head.y + mY[dir];
			nX = head.x + mX[dir];
		}

		// 이동할 위치에 사과가 있을 경우
		if (appleMap[nY][nX]) {
			appleMap[nY][nX] = false;
			snakeLen++;
		}
		// 벽에 부딪힌 경우 반복 종료
		if (nY >= N || nX >= N || nX < 0 || nY < 0) {
			time++;
			break;
		}
		// 자신의 몸과 부딪힌 경우
		if (map[nY][nX] != 0 && time - snakeLen < map[nY][nX]) {
			time++;
			break;
		}

		head.y = nY;
		head.x = nX;
		map[nY][nX] = time + 1;
		time++;
	}
	cout << time;
}