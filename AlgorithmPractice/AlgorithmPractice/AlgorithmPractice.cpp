#include "stdafx.h"
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int city[11][11];
bool check[11];

int N, start;
int minCost = 99999999;

void search(int i, int des, int sum) {

	check[i] = true;

	if (des == N) {
		if (city[i][start] != 0) {
			minCost = min(sum + city[i][start], minCost);
		}
		return;
	}

	for (int j = 0; j < N; j++) {
		if (!check[j] && city[i][j] != 0) {
			search(j, des + 1, sum + city[i][j]);
			check[j] = false;
		}

	}
}

int main() {
	cin >> N;

	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			cin >> city[i][j];
		}
	}

	for (int i = 0; i < N; i++) {
		start = i;
		search(i, 1, 0);
		check[i] = false;
	}

	cout << minCost << '\n';

	return 0;
}