#include "stdafx.h"
#include <iostream>
#include <queue>
#include <vector>
using namespace std;

vector<vector<int>> arr;
int boardSize, edgeNum, sum;
int arrDFS[1001];

void DFS(int start) {

	arrDFS[start] = 1;
	for (int i = 1; i <= boardSize; i++) {
		if (arr[start][i] == 1 && arrDFS[i] == 0) {
			DFS(i);
		}
	}
}

int main(void) {
	int from, to;

	cin >> boardSize >> edgeNum;

	for (int i = 0; i <= boardSize; i++) {
		vector<int> element;
		element.resize(boardSize + 1);
		arr.push_back(element);
	}

	while (edgeNum--) {
		cin >> from >> to;
		arr[to][from] = 1;
		arr[from][to] = 1;
	}

	for (int i = 1; i <= boardSize; i++) {
		if (arrDFS[i] == 0){
			DFS(i);
			sum++;
		}
	}

	cout << sum << '\n';
	return 0;
}