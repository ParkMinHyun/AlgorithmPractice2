#include "stdafx.h"
#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>

// 선형 비교로 인한 시간초과 문제를 해결하지 못해
// http://www.crocus.co.kr/585 참고

using namespace std;

int parent[100002];
vector<vector<int>> edge;
queue<int> nodeQ;

int main() {

	int N;
	int vA, vB;

	cin >> N;

	edge.resize(N + 1);
	for (int i = 0; i< N - 1; i++) {
		cin >> vA >> vB;
		edge[vA].push_back(vB);
		edge[vB].push_back(vA);
	}

	nodeQ.push(1);
	while (!nodeQ.empty()) {
		int node = nodeQ.front();
		nodeQ.pop();

		// 부모가 없다면, 부모 자리에 node를 넣어주기! 그리고 해당 값은 또 nodeQ에 push
		for (int i = 0; i < edge[node].size(); i++) {
			if (parent[edge[node][i]] == 0) {
				nodeQ.push(edge[node][i]);
				parent[edge[node][i]] = node;
			}
		}
	}

	for (int i = 2; i <= N; i++) {
		cout << parent[i] << '\n';
	}
	return 0;
}