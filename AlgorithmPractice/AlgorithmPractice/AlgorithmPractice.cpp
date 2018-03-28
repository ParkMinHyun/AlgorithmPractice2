#include "stdafx.h"
#include <cstdio>
#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>

using namespace std;

queue<pair<int, int>> q;
bool check[1000001];

int main() {
	int F, S, G, U, D, temp, result;
	cin >> F >> S >> G >> U >> D;

	vector<int> arr(F + 1);

	q.push(make_pair(S, 0));
	check[S] = true;

	while (!q.empty()) {
		int pos = q.front().first;
		int time = q.front().second;
		q.pop();

		if (pos == G) {
			result = time;
			break;
		}

		temp = pos + 2;
		if (temp > F) {
			temp = pos;
		}
		if (!check[temp]) {
			q.push(make_pair(temp, time + 1));
			check[temp] = true;
		}

		temp = pos - D;
		if (temp < 0) {
			temp = pos;
		}
		if (!check[temp]) {
			q.push(make_pair(temp, time + 1));
			check[temp] = true;
		}
	}

	if (!check[G]) {
		cout << "use the stairs";
	}
	else {
		cout << result;
	}
	return 0;
}