#include "stdafx.h"
#include <iostream>
#include <cstdio>
#include <vector>
#include <cmath>
#include <algorithm>
#include <climits>

using namespace std;

struct Node {
	int y;
	int x;
};

int getDis(int aY, int aX, int bY, int bX) {
	return abs(aY - bY) + abs(aX - bX);
}

int map[51][51], nMin = INT_MAX;

vector<Node> userV;
vector<Node> storeV;
vector<int> permV;

int N, M;

void dfs(int pos, int sum, vector<Node>v) {
	if (nMin < sum) {
		return;
	}

	if (pos == userV.size()) {
		nMin = min(sum, nMin);
		return;
	}

	int subMin = INT_MAX;
	for (int i = 0; i < M; i++) {
		subMin = min(subMin, getDis(v[i].y, v[i].x, userV[pos].y, userV[pos].x));
	}

	dfs(pos + 1, sum + subMin, v);
}

int main() {

	cin >> N >> M;

	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			cin >> map[i][j];

			if (map[i][j] == 1) {
				userV.push_back({ i,j });
			}
			else if (map[i][j] == 2) {
				storeV.push_back({ i,j });
			}
		}
	}

	int storeVSize = storeV.size();
	permV.resize(storeVSize, 1);
	for (int i = 0; i < storeVSize - M; i++) {
		permV[i] = 0;
	}

	do {
		vector<Node> temp;
		for (int i = 0; i < storeVSize; i++) {
			if (permV[i] == 1) {
				temp.push_back(storeV[i]);
			}
		}
		dfs(0, 0, temp);

	} while (next_permutation(permV.begin(), permV.end()));

	cout << nMin << '\n';

	return 0;
}