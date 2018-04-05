#include "stdafx.h"
#include <iostream>
#include <cstdio>
#include <vector>
#include <algorithm>

using namespace std;

int N, M, i1, i2;
vector<int> arr[32001], brr[32001];
vector<bool> check;

void dfs(int pos) {
	if (arr[pos].size() == 0) {
		cout << pos << ' ';
		return;
	}

	for (int i = 0; i < arr[pos].size(); i++) {
		if (!check[arr[pos][i]]) {
			check[arr[pos][i]] = true;
			dfs(arr[pos][i]);
		}
	}
	cout << pos << ' ';
}

int main() {
	cin >> N >> M;

	check.resize(N+1);
	for (int i = 0; i < M; i++) {
		cin >> i1 >> i2;
		arr[i2].push_back(i1);
	}

	for (int i = 1; i <= N; i++) {
		if (!check[i]) {
			check[i] = true;
			dfs(i);
		}
	}
}