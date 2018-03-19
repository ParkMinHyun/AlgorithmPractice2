#include "stdafx.h"
#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>

using namespace std;

int N, len, mPos;
vector<pair<int, int>> tree[100001];
vector<pair<int, int>> tempTree[100001];
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

	int V, vA, vB;

	cin >> N;
	treeCheck.resize(100001);
	for (int i = 1; i < N; i++) {
		cin >> V >> vA >> vB;
		tree[V].push_back(make_pair(vA, vB));
		tree[vA].push_back(make_pair(V, vB));
	}

	lenCheck(1);
	treeCheck.clear();
	treeCheck.resize(100001);
	lenCheck(mPos);

	cout << len << '\n';
	return 0;
}