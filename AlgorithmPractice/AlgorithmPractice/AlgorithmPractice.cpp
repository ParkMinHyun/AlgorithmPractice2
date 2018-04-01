#include "stdafx.h"
#include <iostream>
#include <cstdio>
#include <algorithm>
#include <string>
#include <vector>
#include <queue>

using namespace std;

long long h, w;
int sum = 1;
int lx[4] = { 1,2,2,1 };
int ly[4] = { -2,-1,1,2 };

vector<vector<bool>> check;
vector<vector<long long>> board;

void greedy(long long y, long long x) {

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