#include "stdafx.h"
#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>

using namespace std;

int len, mPos;
vector<pair<int, int>> tree[100001];
vector<pair<int, int>> treeCheck;
queue<int> nodeQ;

void lenCheck(int start) {
	nodeQ.push(start);

	treeCheck[start].first = -1;
	treeCheck[start].second = 0;

	while (!nodeQ.empty()) {
		int node = nodeQ.front();
		nodeQ.pop();

		for (int i = 0; i < tree[node].size(); i++) {
			if (treeCheck[tree[node][i].first].first == 0) {
				nodeQ.push(tree[node][i].first);

				treeCheck[tree[node][i].first].first = node;
				treeCheck[tree[node][i].first].second = treeCheck[node].second + tree[node][i].second;

				if (len < treeCheck[tree[node][i].first].second) {
					len = treeCheck[tree[node][i].first].second;
					mPos = tree[node][i].first;
				}
			}
		}
	}
}
int main() {

	int N, V;
	int vA, vB;

	cin >> N;
	treeCheck.resize(100001);
	for (int i = 1; i <= N; i++) {
		cin >> V;
		while (true) {
			cin >> vA;
			if (vA == -1) {
				break;
			}
			cin >> vB;

			tree[V].push_back(make_pair(vA, vB));
		}
	}

	lenCheck(1);
	treeCheck.clear();
	treeCheck.resize(100001);

	// 가장 멀리에서 한 번 더 작업 해줘야 함!
	lenCheck(mPos);

	cout << len << '\n';
	return 0;
}