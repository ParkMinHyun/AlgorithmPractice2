#include "stdafx.h"
#include <iostream>
#include <vector>

using namespace std;

int H, W, type, sum;
int board[51][51];
vector<int> section;

void check(int i, int j) {
	if (i < 0 || i >= H || j < 0 || j >= W) {
		return;
	}

	if (board[i][j] == 1) {
		sum++;
		board[i][j] = -1;

		check(i, j + 1);
		check(i, j - 1);
		check(i + 1, j);
		check(i - 1, j);

		check(i + 1, j + 1);
		check(i - 1, j - 1);
		check(i + 1, j - 1);
		check(i - 1, j + 1);
	}

}

int main() {

	while (true)
	{
		cin >> W >> H;

		if (H == 0 && W == 0) {
			return 0;
		}

		for (int i = 0; i < H; i++) {
			for (int j = 0; j < W; j++) {
				cin >> board[i][j];
			}
		}

		section.clear();
		for (int i = 0; i < H; i++) {
			for (int j = 0; j < W; j++) {
				sum = 0;
				if (board[i][j] == 1) {
					check(i, j);
					section.push_back(sum);
				}
			}
		}
		cout << section.size() << '\n';

	}

	return 0;
}
