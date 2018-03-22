#include "stdafx.h"
#include <iostream>
#include <vector>
#include <set>
#include <algorithm>

using namespace std;

int main() {

	int N, M, input;

	cin >> N;
	set<long long> arr;
	for (int i = 0; i < N; i++) {
		cin >> input;
		arr.insert(input);
	}

	cin >> M;
	vector<long long> brr(M);
	for (int i = 0; i < M; i++) {
		cin >> input;

	}

	for (long long x : brr) {
		auto it = arr.find(x);
		if (it == arr.end()) {
			cout << 0 << ' ';
		}
		else {
			cout << 1 << ' ';
		}
	}

	return 0;
}