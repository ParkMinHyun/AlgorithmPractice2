#include "stdafx.h"
#include <iostream>
#include <queue>
#include <string>
#include <vector>
#include <utility>
using namespace std;

vector<vector<int>> arr;
vector<pair<int, bool>> arrBFS;

int boardSize, edgeNum;

string BFS(int start) {
	queue<int> Q;

	arrBFS[start].first = 1;
	arrBFS[start].second = false;

	Q.push(start);
	while (!Q.empty()) {

		int temp = Q.front();
		Q.pop();

		for (int i = 0; i < arr[temp].size(); i++) {
			if (arrBFS[arr[temp][i]].first == 0) {
				Q.push(arr[temp][i]);
				arrBFS[arr[temp][i]].first = 1;
				arrBFS[arr[temp][i]].second = !arrBFS[temp].second;
			}
			else if (arrBFS[arr[temp][i]].second == arrBFS[temp].second) {
				return "NO\n";
			}
		}
	}
	return "YES\n";
}

int main(void) {
	int N;
	cin >> N;

	while (N--) {
		int from, to;

		cin >> boardSize >> edgeNum;

		arr.clear();
		arr.resize(boardSize + 1);
		arrBFS.clear();
		arrBFS.resize(boardSize + 1);

		while (edgeNum--) {
			cin >> from >> to;
			arr[to].push_back(from);
			arr[from].push_back(to);
		}

		cout << BFS(from);

	}
	return 0;
}