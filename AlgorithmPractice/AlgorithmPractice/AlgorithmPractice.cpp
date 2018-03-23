#include "stdafx.h"
#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
using namespace std;

// http://www.crocus.co.kr/627 참고 - BFS 방법

#define MAX 100000

int result = MAX;
int visit[MAX * 2 + 1];

queue<pair<int, int>> pQ;

int main() {
	int A, B;

	cin >> A >> B;

	if (A == B) {
		cout << 0;
		return 0;
	}

	pQ.push(make_pair(A, 0));

	while (!pQ.empty()) {
		int pos = pQ.front().first;
		int count = pQ.front().second;

		pQ.pop();
		visit[pos] = 1;

		if (pos == B) {
			result = min(count, result);
		}

		if (pos * 2 <= 2 * B  && visit[pos * 2] == 0) {
			pQ.push(make_pair(pos * 2, count + 1));
		}

		if (pos - 1 >= B / 4 && visit[pos - 1] == 0) {
			pQ.push(make_pair(pos - 1, count + 1));
		}

		if (pos + 1 <= B && visit[pos + 1] == 0) {
			pQ.push(make_pair(pos + 1, count + 1));
		}
	}

	cout << result << '\n';
	return 0;
}