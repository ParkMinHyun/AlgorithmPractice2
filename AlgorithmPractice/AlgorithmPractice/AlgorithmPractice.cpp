#include "stdafx.h"
#include <iostream>
#include <queue>
#include <vector>
#include <algorithm>

using namespace std;

int N, num, start, des;
vector<bool> visit(10001);
vector<pair<int, char>> parent(10001);

bool check(int d, vector<pair<int, char>> parent) {
	deque<char> result;
	if (des == d) {
		while (parent[d].second != 0) {
			result.push_front(parent[d].second);
			d = parent[d].first;
		}
		while (!result.empty()) {
			cout << result.front();
			result.pop_front();
		}
		cout << '\n';
		return true;
	}
	return false;
}

void bfs() {

	visit.clear();
	visit.resize(10001);
	parent.clear();
	parent.resize(10001);

	num = start;
	visit[start] = true;

	queue<int> sQ;
	sQ.push(num);

	while (!sQ.empty()) {
		int digit = sQ.front();

		sQ.pop();

		int tempN = (2 * digit) % 10000;
		if (!visit[tempN]) {
			parent[tempN] = make_pair(digit, 'D');
			visit[tempN] = true;
			sQ.push(tempN);
		}

		tempN = digit - 1;
		if (tempN == -1) {
			tempN = 9999;
		}
		if (!visit[tempN]) {
			parent[tempN] = make_pair(digit, 'S');
			visit[tempN] = true;
			sQ.push(tempN);
		}

		tempN = (digit % 1000) * 10 + digit / 1000;
		if (!visit[tempN]) {
			parent[tempN] = make_pair(digit, 'L');
			visit[tempN] = true;
			sQ.push(tempN);
		}

		tempN = (digit / 10) + (digit % 10) * 1000;;
		if (!visit[tempN]) {
			parent[tempN] = make_pair(digit, 'R');
			visit[tempN] = true;
			sQ.push(tempN);
		}
	}
	check(des, parent);
	cout << '\n';
}

int main() {

	cin >> N;

	while (N--) {
		cin >> start >> des;
		bfs();
	}

	return 0;
}