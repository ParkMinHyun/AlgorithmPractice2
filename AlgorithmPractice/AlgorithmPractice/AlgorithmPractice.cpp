#include "stdafx.h"
#include <queue>
#include <iostream>
#include <cstdio>
#include <algorithm>
#include <numeric>
#include <string>
#include <tuple>

using namespace std;

int A, B, C;
int oSize, result = 999999;
bool visit[250][250][250];

deque<int> onePan[3];

bool checking(deque<int> A, deque<int> B, deque<int> C) {
	deque<int> T[3];
	T[0] = A;
	T[1] = B;
	T[2] = C;

	for (int i = 0; i < 3; i++) {
		if (T[i].size() == oSize) {
			return true;
		}
	}
	return false;
}

int sumNum(deque<int> t) {
	return accumulate(t.begin(), t.end(), 0);
}

void sol(deque<int> onePan[3], int time) {

	deque<int> TP[3];
	queue<pair<tuple<deque<int>, deque<int>, deque<int>>, int>> q;
	q.push(make_pair(make_tuple(onePan[0], onePan[1], onePan[2]), 0));

	while (!q.empty()) {

		deque<int> AQ = get<0>(q.front().first);
		deque<int> BQ = get<1>(q.front().first);
		deque<int> CQ = get<2>(q.front().first);
		int time = q.front().second;
		q.pop();

		AQ.size() == 0 ? A = 0 : A = AQ.back();
		BQ.size() == 0 ? B = 0 : B = BQ.back();
		CQ.size() == 0 ? C = 0 : C = CQ.back();

		int sA = sumNum(AQ);
		int sB = sumNum(BQ);
		int sC = sumNum(CQ);

		if (visit[sA][sB][sC]) {
			continue;
		}
		visit[sA][sB][sC] = true;

		if (checking(AQ, BQ, CQ)) {
			result = min(result, time);
			return;
		}

		// A<-B,C
		if (B > A && visit[sA][sB][sC]) {
			TP[0] = AQ; TP[1] = BQ; TP[2] = CQ;
			TP[0].push_back(TP[1].back());
			TP[1].pop_back();
			q.push(make_pair(make_tuple(TP[0], TP[1], TP[2]), time + 1));
		}
		if (C > A && visit[sA][sB][sC]) {
			TP[0] = AQ; TP[1] = BQ; TP[2] = CQ;
			TP[0].push_back(TP[2].back());
			TP[2].pop_back();
			q.push(make_pair(make_tuple(TP[0], TP[1], TP[2]), time + 1));
		}

		// B<-A,C
		if (A > B && visit[sA][sB][sC]) {
			TP[0] = AQ; TP[1] = BQ; TP[2] = CQ;
			TP[1].push_back(TP[0].back());
			TP[0].pop_back();
			q.push(make_pair(make_tuple(TP[0], TP[1], TP[2]), time + 1));
		}
		if (C > B && visit[sA][sB][sC]) {
			TP[0] = AQ; TP[1] = BQ; TP[2] = CQ;
			TP[1].push_back(TP[2].back());
			TP[2].pop_back();
			q.push(make_pair(make_tuple(TP[0], TP[1], TP[2]), time + 1));
		}

		// C<-A,B
		if (A > C && visit[sA][sB][sC]) {
			TP[0] = AQ; TP[1] = BQ; TP[2] = CQ;
			TP[2].push_back(TP[0].back());
			TP[0].pop_back();
			q.push(make_pair(make_tuple(TP[0], TP[1], TP[2]), time + 1));
		}
		if (B > C && visit[sA][sB][sC]) {
			TP[0] = AQ; TP[1] = BQ; TP[2] = CQ;
			TP[2].push_back(TP[1].back());
			TP[1].pop_back();
			q.push(make_pair(make_tuple(TP[0], TP[1], TP[2]), time + 1));
		}
	}
}

int main() {

	string str;

	for (int i = 0; i < 3; i++) {
		getline(cin, str);
		for (int j = 0; j < str.size(); j++) {
			if (str[j] != ' ') {
				onePan[i].push_back(str[j] - '0');
				oSize++;
			}
		}
	}

	sol(onePan, 0);
	cout << result;
	return 0;
}