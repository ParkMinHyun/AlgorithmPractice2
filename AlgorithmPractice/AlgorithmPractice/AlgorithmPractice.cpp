#include "stdafx.h"
#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

int N, type, sum;
int board[26][26];
vector<int> section;

void check(int i, int j) {
	if (i < 0 || i >= N || j < 0 || j >= N) {
		return;
	}

	if (board[i][j] == 1) {
		sum++;
		board[i][j] = -1;

		check(i, j + 1);
		check(i, j - 1);
		check(i + 1, j);
		check(i - 1, j);
	}

}

int main() {

	cin >> N;

	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			scanf_s("%1d", &board[i][j]);
		}
	}

	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			sum = 0;
			if (board[i][j] == 1) {
				check(i, j);
				section.push_back(sum);
			}
		}
	}

	sort(section.begin(), section.end());
	cout << section.size() << '\n';
	for (int num : section) {
		cout << num << '\n';
	}
	return 0;
}
