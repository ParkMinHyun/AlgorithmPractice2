#include "stdafx.h"
#include <iostream>
#include <vector>

using namespace std;

int sum, start;
int cycle[100001];
vector<int> arr;
vector<int> visit;

void check(int currentV, int depth) {
	visit[currentV] = depth;
	cycle[currentV] = start;

	int next = arr[currentV];

	if (visit[next] == 0) {
		check(next, depth + 1);
	}

	else if (start == cycle[next]) {
		sum += depth - visit[next] + 1;
	}
}

int main() {

	int N, V;
	cin >> N;
	while (N--) {
		cin >> V;

		visit.clear();
		visit.resize(V + 1, 0);
		arr.resize(V + 1);

		sum = 0;

		for (int i = 1; i <= V; ++i){
			cin >> arr[i];
		}

		for (int i = 1; i <= V; ++i) {
			start = i;
			if (visit[i] != 0){
				continue;
			}
			if (visit[arr[i]] == 0){
				check(i, 1);
			}
		}
		cout << V - sum << '\n';
	}
	return 0;
}
