#include "stdafx.h"
#include <iostream>
#include <cstdio>
#include <vector>
#include <algorithm>
#include <queue>
/*
* Time complexity: O(2^N)
* Space complexity: O(N)
*/

using namespace std;

struct INFO {
	int start;
	int dur;
	int pay;
};

int N, M, D, I, nMax;
vector<INFO> v, resultV;

void dfs(int pos, int day, int sum, vector<INFO> tempV) {

	if (pos == N || sum > 100) {
		return;
	}

	if (nMax < sum) {
		nMax = sum;
		resultV = tempV;
	}

	for (int i = pos; i < N; i++) {
		if (day <= v[i].start) {
			tempV.push_back(v[i]);
			dfs(i + 1, v[i].start + v[i].dur, sum + v[i].pay, tempV);
			tempV.pop_back();
		}
	}
}

int main()
{
	cin >> N;
	for (int i = 0; i < N; i++) {
		int M, D, I;
		cin >> M >> D >> I;
		v.push_back({ M,D,I });
	}

	// 날짜, pay
	vector<INFO> tempV;
	dfs(0, 0, 0, tempV);

	cout << nMax << '\n';
	for (int i = 0; i < resultV.size(); i++) {
		cout << resultV[i].start << ' ' << resultV[i].dur << '\n';
	}
	return 0;
}