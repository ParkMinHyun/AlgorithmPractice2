#include "stdafx.h"
#include <iostream>
#include <cstdio>
#include <vector>
#include <set>
#include <queue>
/*
* Time complexity: O(N)
* Space complexity: O(N)
*/

using namespace std;

bool check[100001];
vector<int> g[100001];

void bfs(vector<int> v) {
	queue<vector<int>> q;
	q.push(v);
	while (!q.empty()) {
		vector<int> t = q.front();
		q.pop();

		for (int i = 0; i < t.size(); i++) {
			if (!check[t[i]]) {
				check[t[i]] = true;
				q.push(g[t[i]]);
			}
		}
	}
}

int main()
{
	set<int> inputSet;
	int N, s, d, cnt = 0;
	cin >> N;

	while (N--) {
		cin >> s >> d;
		g[s].push_back(d);
		g[d].push_back(s);

		inputSet.insert(s);
		inputSet.insert(d);
	}

	for (auto it = inputSet.begin(); it != inputSet.end(); it++) {
		if (!check[*it]) {
			check[*it] = true;
			bfs(g[*it]);
			cnt++;
		}
	}
	cout << cnt;
	return 0;
}