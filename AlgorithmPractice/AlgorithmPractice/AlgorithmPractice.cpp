#include "stdafx.h"
#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

struct Info {
	int day;
	int pay;
};

int N, t, p, nMax;
vector<Info> v;

// 현재 날짜, 현재 Pay
void dfs(int pos, int pay) {

	if (pos > N) {
		return;
	}

	nMax = max(nMax, pay);

	for (int i = pos; i < N; i++) {
		dfs(i + v[i].day, pay + v[i].pay);
	}
}

int main() {
	cin >> N;

	for (int i = 0; i < N; i++) {
		cin >> t >> p;
		v.push_back({ t,p });
	}

	for (int i = 0; i < N; i++) {
		dfs(i + v[i].day, v[i].pay);
	}
	cout << nMax;
}