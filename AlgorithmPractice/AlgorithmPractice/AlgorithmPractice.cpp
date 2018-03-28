#include "stdafx.h"
#include <cstdio>
#include <iostream>
#include <vector>
#include <algorithm>
#include <tuple>
#include <queue>
#include <set>

using namespace std;

int A, B, C, tAL, tBL, tCL;
queue<tuple<int, int, int>> q;
bool check[201][201][201];
set<int> s;

void checking() {
	if (!check[tAL][tBL][tCL]) {
		q.push(make_tuple(tAL, tBL, tCL));
		check[tAL][tBL][tCL] = true;
	}
}

int main() {
	cin >> A >> B >> C;

	q.push(make_tuple(0, 0, C));
	check[A][B][C] = true;

	while (!q.empty()) {
		int AL = get<0>(q.front());
		int BL = get<1>(q.front());
		int CL = get<2>(q.front());
		q.pop();

		if (AL == 0) {
			s.insert(CL);
		}

		tAL = AL; tBL = BL; tCL = CL;
		tBL += tAL;
		if (tBL >= B) {
			tAL = tBL - B;
			tBL = B;
		}
		else {
			tAL = 0;
		}
		checking();
		//--------------------------------------------//
		tAL = AL; tBL = BL; tCL = CL;
		tCL += tAL;
		if (tCL >= C) {
			tAL = tCL - C;
			tCL = C;
		}
		else {
			tAL = 0;
		}
		checking();
		//--------------------------------------------//
		tAL = AL; tBL = BL; tCL = CL;
		tAL += tBL;
		if (tAL >= A) {
			tBL = tAL - A;
			tAL = A;
		}
		else {
			tBL = 0;
		}
		checking();
		//--------------------------------------------//
		tAL = AL; tBL = BL; tCL = CL;
		tCL += tBL;
		if (tCL >= C) {
			tBL = tCL - C;
			tCL = C;
		}
		else {
			tBL = 0;
		}
		checking();
		//--------------------------------------------//
		tAL = AL; tBL = BL; tCL = CL;
		tAL += tCL;
		if (tAL >= A) {
			tCL = tAL - A;
			tAL = A;
		}
		else {
			tCL = 0;
		}
		checking();
		//--------------------------------------------//
		tAL = AL; tBL = BL; tCL = CL;
		tBL += tCL;
		if (tBL >= B) {
			tCL = tBL - B;
			tBL = B;
		}
		else {
			tCL = 0;
		}
		checking();
	}

	for (int x : s) {
		cout << x << ' ';
	}
	return 0;
}