#include "stdafx.h"
#include <iostream>
#include <deque>
using namespace std;

int main() {
	int N, M, count = 1;
	cin >> N >> M;

	deque<int> P;
	for (int i = 0; i < N; i++) {
		P.push_back(i + 1);
	}

	cout << "<";
	while (!P.empty()) {
		if (count != M) {
			P.push_back(P[0]);
			P.pop_front();
			count++;
		}
		else {
			if (P.size() != 1) {
				cout << P[0] << ", ";
			}
			else {
				cout << P[0] << ">";
				return 0;
			}
			P.pop_front();
			count = 1;
		}
	}
}