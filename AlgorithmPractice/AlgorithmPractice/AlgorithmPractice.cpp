#include "stdafx.h"
#include <iostream>

using namespace std;

int tV, tR, L;
int sum;
int turnelType[8][4] = {
	{ 0,0,0,0 },
	{ 1,1,1,1 },
	{ 1,1,0,0 },
	{ 0,0,1,1 },
	{ 1,0,0,1 },
	{ 0,1,0,1 },
	{ 0,1,1,0 },
	{ 1,0,1,0 }};
int turnel[51][51];
int check[51][51];

void search(int mV, int mR, int hour, int arrow) {
	if (L == hour || mV > tV || mV < 0 || mR > tR || mR < 0 || turnel[mV][mR] == 0 || check[mV][mR] == 1) {
		return;
	}

	if (arrow != 100) {
		if (turnelType[turnel[mV][mR]][arrow] != 1) {
			return;
		}
	}

	check[mV][mR] = 1;
	sum++;

	if (turnel[mV][mR] == 1) {
		search(mV - 1, mR, hour + 1, 1);
		search(mV + 1, mR, hour + 1, 0);
		search(mV, mR + 1, hour + 1, 2);
		search(mV, mR - 1, hour + 1, 3);
	}
	else if (turnel[mV][mR] == 2) {
		search(mV - 1, mR, hour + 1, 1);
		search(mV + 1, mR, hour + 1, 0);
	}
	else if (turnel[mV][mR] == 3) {
		search(mV, mR + 1, hour + 1, 2);
		search(mV, mR - 1, hour + 1, 3);
	}
	else if (turnel[mV][mR] == 4) {
		search(mV - 1, mR, hour + 1, 1);
		search(mV, mR + 1, hour + 1, 2);
	}
	else if (turnel[mV][mR] == 5) {
		search(mV + 1, mR, hour + 1, 0);
		search(mV, mR + 1, hour + 1, 2);
	}
	else if (turnel[mV][mR] == 6) {
		search(mV + 1, mR, hour + 1, 0);
		search(mV, mR - 1, hour + 1, 3);
	}
	else if (turnel[mV][mR] == 7) {
		search(mV - 1, mR, hour + 1, 1);
		search(mV, mR - 1, hour + 1, 3);
	}
}
void init() {
	sum = 0;
	for (int i = 0; i < 51; i++)
		for (int j = 0; j < 51; j++)
			check[i][j] = 0;
}

int main() {
	int T;
	cin >> T;

	int  mV, mR;
	for (int testCase = 1; testCase <= T; testCase++) {
		init();

		cin >> tV >> tR >> mV >> mR >> L;

		for (int i = 0; i < tV; i++) {
			for (int j = 0; j < tR; j++) {
				cin >> turnel[i][j];
			}
		}

		search(mV, mR, 0, 100);
		cout << "#" << testCase << " " << sum << '\n';
	}
}