#include "stdafx.h"
#include <cstdio>
#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

vector<vector<int>> arr;
vector<bool> check;
int tc, N, chairN, A, B;
bool success;

void dfs(int pos) {

	if (pos == chairN) {
		success = true;
		return;
	}

	for (int i = 0; i < arr[pos].size(); i++) {
		if (!check[arr[pos][i]]) {
			check[arr[pos][i]] = true;
			dfs(pos + 1);
			check[arr[pos][i]] = false;
		}
	}
}

int main() {

	cin >> tc;
	while (tc--) {
		cin >> chairN >> N;

		arr.clear();
		arr.resize(chairN);
		check.clear();
		check.resize(chairN);
		success = false;

		for (int i = 0; i < N; i++) {
			cin >> A >> B;
			arr[A].push_back(B);
		}

		for (int i = 0; i < arr[0].size(); i++) {
			check[arr[0][i]] = true;
			dfs(1);
			check[arr[0][i]] = false;
		}

		if (success) {
			cout << "O" << '\n';
		}
		else {
			cout << "X" << '\n';
		}

	}

	return 0;
}