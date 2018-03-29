#include "stdafx.h"
#include <iostream>
#include <cstdio>

using namespace std;

int map[2300][2300];
int cnt[4];

int total;

void solve(int n, int y, int x, int jump)
{
	int first = map[y][x];

	bool chk = true;

	for (int i = y; i < y + n; i++) {
		for (int j = x; j < x + n; j++)
			if (map[i][j] != first)
			{
				chk = false;
				break;
			}
	}

	if (chk) {
		cnt[first + 1]++;
		return;
	}

	for (int i = 0; i < 3; i++) {
		for (int j = 0; j < 3; j++) {
			solve(n / 3, y + jump * i, x + jump * j, jump / 3);
		}
	}
}

int main()
{
	int n;
	cin >> n;

	total = n;

	for (int i = 0; i < n; i++)
		for (int j = 0; j < n; j++)
			cin >> map[i][j];

	solve(n, 0, 0, n / 3);

	cout << cnt[0] << endl;
	cout << cnt[1] << endl;
	cout << cnt[2] << endl;

	return 0;
}