#include "stdafx.h"
#include <iostream>
#include <cstdio>
#include <algorithm>
#include <string>
#include <vector>
#include <queue>

// 출처 : http://joonas-yoon.blogspot.kr/2016/03/1783.html
using namespace std;

int main() {
	int h, w;
	cin >> h >> w;
	
	// 높이 1일 땐 1
	if (h == 1){
		cout << 1;
	}
	// 높이 2일 때 (가로 2칸씩 밖에 이동 못 함)
	else if (h == 2) {
		cout << min(4, (w + 1) / 2);
	}
	// 4칸 움직이기 전에
	else if (w < 7) {
		cout << min(4, w);
	}
	// 4칸 이상 움직였을 경우
	else {
		cout << w - 2;
	}
}
/*
모든 경우의 수 찾는 문제인 줄;;

long long h, w;
int sum = 1;
int lx[4] = { 1,2,2,1 };
int ly[4] = { -2,-1,1,2 };

vector<vector<bool>> check;
vector<vector<long long>> board;

void bfs(long long y, long long x) {

	queue<pair<long long, long long>> q;
	q.push(make_pair(y, x));

	while (!q.empty()) {
		long long cH, cW, nH, nW;
		cH = q.front().first;
		cW = q.front().second;
		q.pop();

		for (int i = 0; i < 4; i++) {
			nH = cH + ly[i];
			nW = cW + lx[i];

			if (nH < h && nH >= 0 && nW < w && !check[nH][nW]) {
				sum++;
				check[nH][nW] = true;
				q.push(make_pair(nH, nW));
			}
		}
	}
}

int main() {
	cin >> h >> w;

	board.resize(h);
	check.resize(h);
	for (long long i = 0; i < h; i++) {
		board[i].resize(w);
		check[i].resize(w);
	}

	check[h - 1][0] = true;
	greedy(h - 1, 0);

	cout << sum;
}
*/