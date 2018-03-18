#include "stdafx.h"
#include <iostream>
#include <vector>
#include <queue>
#include <utility>
using namespace std;

int N, minPath = 999999;
int group;

int board[101][101];
int temp[101][101];
queue<pair<int, int>> pathQ;

int nH[4] = { 1,-1,0,0 };
int nW[4] = { 0,0,1,-1 };


void check(int i, int j, int section) {
	if (i < 0 || i >= N || j < 0 || j >= N) {
		return;
	}

	if (board[i][j] == 1) {
		board[i][j] = section;

		check(i, j + 1, section);
		check(i, j - 1, section);
		check(i + 1, j, section);
		check(i - 1, j, section);
	}
}

void bridge() {

	while (!pathQ.empty()) {
		int cH = pathQ.front().first;
		int cW = pathQ.front().second;
		pathQ.pop();

		for (int i = 0; i < 4; i++) {
			int nextH = cH + nH[i];
			int nextW = cW + nW[i];

			if (nextH >= 0 && nextH < N && nextW >= 0 && nextW < N) {
				if (board[nextH][nextW] == 0 && (temp[nextH][nextW] > temp[cH][cW] + 1 || temp[nextH][nextW] == 0)) {
					temp[nextH][nextW] = temp[cH][cW] + 1;
					pathQ.push(make_pair(nextH, nextW));
				}
				else if (board[nextH][nextW] != group && board[nextH][nextW] != 0) {
					if (minPath > temp[cH][cW]) {
						minPath = temp[cH][cW];
					}
				}
			}
		}
	}
}

int main() {

	cin >> N;

	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			cin >> board[i][j];
			if (board[i][j] == 0) {
				temp[i][j] = 0;
			}
		}
	}

	int section = 2;
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			if (board[i][j] == 1) {
				check(i, j, section++);
			}
		}
	}

	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			if (board[i][j] != 0) {
				group = board[i][j];
				pathQ.push(make_pair(i, j));
				bridge();
			}
		}
	}

	cout << minPath << '\n';
	return 0;
}