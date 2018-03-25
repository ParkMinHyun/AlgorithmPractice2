#include "stdafx.h"
#include <iostream>
#include <map>
#include <algorithm>

using namespace std;

map<long long, int> m;

int main() {
	int N;
	long long input;

	cin >> N;
	for (int i = 0; i < N; i++) {
		cin >> input;
		m[input] ++;
	}

	int maxnum = -1;
	long long val;
	for (auto it = m.begin(); it != m.end(); it++)
	{
		if (it->second > maxnum)
		{
			maxnum = it->second;
			val = it->first;
		}
	}

	cout << val;
	return 0;
}