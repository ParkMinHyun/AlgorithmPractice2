#include "stdafx.h"
#include <iostream>
#include <cstdio>
#include <vector>
#include <algorithm>

using namespace std;

int arr[9][9];

void rowCheck(int y) {
	int cnt = 0, pos;
	vector<bool> rV(10);
	for (int i = 0; i < 9; i++) {
		if (arr[y][i] == 0) {
			pos = i;
			continue;
		}
		rV[arr[y][i]] = true;
		cnt++;
	}

	if (cnt == 8) {
		for (int i = 1; i <= 9; i++) {
			if (!rV[i]) {
				arr[y][pos] = i;
			}
		}
	}
}

void verCheck(int x) {
	vector<bool> vV(10);
	int cnt = 0, pos;
	for (int i = 0; i < 9; i++) {
		if (arr[i][x] == 0) {
			pos = i;
			continue;
		}
		vV[arr[i][x]] = true;
		cnt++;
	}

	if (cnt == 8) {
		for (int i = 1; i <= 9; i++) {
			if (!vV[i]) {
				arr[pos][x] = i;
			}
		}
	}
}

void nemoCheck(int y, int x) {
	vector<bool> nV(10);

	int cnt = 0, posX, posY;
	for (int i = y / 3 * 3; i < (y / 3 * 3) + 3; i++) {
		for (int j = x / 3 * 3; j < (x / 3 * 3) + 3; j++) {
			if (arr[i][j] == 0) {
				posY = i;
				posX = j;
				continue;
			}
			nV[arr[i][j]] = true;
			cnt++;
		}
	}

	if (cnt == 8) {
		for (int i = 1; i <= 9; i++) {
			if (!nV[i]) {
				arr[posY][posX] = i;
			}
		}
	}
}

int main() {

	for (int i = 0; i < 9; i++) {
		for (int j = 0; j < 9; j++) {
			cin >> arr[i][j];
		}
	}

	while (true) {
		bool check = false;
		for (int i = 0; i < 9; i++) {
			for (int j = 0; j < 9; j++) {
				if (arr[i][j] == 0) {
					rowCheck(i);
					verCheck(j);
					nemoCheck(i, j);
					check = true;
				}
			}
		}
		if (!check) {
			for (int i = 0; i < 9; i++) {
				for (int j = 0; j < 9; j++) {
					cout << arr[i][j] << ' ';
				}
				cout << '\n';
			}
			return 0;
		}
	}
}