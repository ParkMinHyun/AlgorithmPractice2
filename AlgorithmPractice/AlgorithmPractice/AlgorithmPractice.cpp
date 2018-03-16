#include "stdafx.h"
#include <iostream>
#include <queue>
#include <vector>
using namespace std;

vector<vector<int>> arr;
int boardSize = 0, sum = 0;
int arrDFS[1001];
int arrBFS[1001];

void DFS(int start, int first) {
	if (first == 1) {
		cout << start << ' ';
	}

	for (int i = 0; i <= boardSize; i++) {
		if (arr[start][i] == 1 && arrDFS[i] == 0) {
			cout << i << ' ';
			arrDFS[i] = 1;
			DFS(i, 0);
		}
	}
}

void BFS(int start) {
	queue<int> Q;

	Q.push(start);

	while (!Q.empty()) {

		int qFront = Q.front();
		cout << qFront << ' ';
		Q.pop();

		for (int i = 0; i <= boardSize; i++) {
			if (arr[qFront][i] == 1 && arrBFS[i] == 0) {
				Q.push(i);
				arrBFS[i] = 1;
			}
		}
	}
}

int main(void) {
	int edge, start, from, to;

	cin >> boardSize >> edge >> start;

	for (int i = 0; i <= boardSize; ++i) {
		vector<int> element;
		element.resize(boardSize + 1);
		arr.push_back(element);
	}

	while (edge--) {
		cin >> from >> to;
		arr[to][from] = 1;
		arr[from][to] = 1;
	}

	arrDFS[start] = 1;
	DFS(start, 1);

	cout << '\n';

	arrBFS[start] = 1;
	BFS(start);

	return 0;
}