#include "stdafx.h"
#include <iostream>
#include <cstdio>
#include <vector>
#include <tuple>
using namespace std;
/*
* Time complexity: O(N)
* Space complexity: O(logN)
*/

int main()
{
	int N, M, D, I, last = 0, sum = 0;
	vector<tuple<int, int, int>> v;
	vector<int> start;
	vector<int> end;

	cin >> N;
	for (int i = 0; i < N; i++) {
		cin >> M >> D >> I;
		v.push_back(make_tuple(M, M+D, I));
	}

	for (int i = 0; i < N; i++) {
		if (get<1>(v[i]) >= last) {
			last = get<0>(v[i]);
			sum += get<2>(v[i]);

			start.push_back(get<0>(v[i]));
			end.push_back(get<1>(v[i]) - get<0>(v[i]));
		}
	}

	for (int i = 0; i < start.size(); i++) {
		cout << start[i] << ' ' << end[i] << '\n';
	}

	cout << sum;
	return 0;
}