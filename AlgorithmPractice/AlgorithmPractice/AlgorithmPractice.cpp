#include "stdafx.h"
#include <iostream>
#include <cstdio>
#include <vector>
#include <queue>
#include <algorithm>

using namespace std;

int N, K;
long long sum;
vector<pair<int, int>> bosuk;
vector<int> bag;
priority_queue<int> pq;

int main() {
	cin >> N >> K;

	bosuk.resize(N);
	bag.resize(K);

	for (int i = 0; i < N; i++) {
		cin >> bosuk[i].first >> bosuk[i].second;
	}
	for (int i = 0; i < K; i++) {
		cin >> bag[i];
	}

	sort(bag.begin(), bag.end());
	sort(bosuk.begin(), bosuk.end());

	for (int i = 0, j = 0; i < K; i++) {
		while (j < N && bosuk[j].first <= bag[i]) {
			pq.push(bosuk[j++].second);
		}
		if (!pq.empty()) {
			sum += pq.top();
			pq.pop();
		}

	}
	cout << sum;
}