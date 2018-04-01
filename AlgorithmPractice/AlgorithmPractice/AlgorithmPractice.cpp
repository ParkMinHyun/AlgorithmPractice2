#include "stdafx.h"
#include <iostream>
#include <cstdio>
#include <vector>
#include <set>
#include <queue>
/*
* Time complexity: O(N)
* Space complexity: O(N^2)
*/

using namespace std;

bool check[100001];
vector<int> g[100001];

void bfs(vector<int> v) {
	queue<vector<int>> q;
	q.push(v);
	while (!q.empty()) {
		vector<int> t = q.front();
		if (t[0] == 0) {
			return;
		}
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
	set<int>temp;
	int N, s, d, cnt = 0;
	cin >> N;

	while (N--) {
		cin >> s >> d;
		g[s].push_back(d);
		g[d].push_back(s);

		temp.insert(s);
		temp.insert(d);
	}

	for (auto it = temp.begin(); it != temp.end(); it++) {
		if (!check[*it]) {
			check[*it] = true;
			bfs(g[*it]);
			cnt++;
		}
	}
	cout << cnt;
	return 0;
}