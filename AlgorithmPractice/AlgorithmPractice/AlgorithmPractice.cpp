#include "stdafx.h"
#include <cstdio>
#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
using namespace std;

vector<int> temp_arr;
vector<int> arr;

int main() {

	int t = 0, temp = 0;
	while (1) {
		cin >> t;

		if (t == 0) {
			break;
		}

		for (int i = 0; i<t; i++) {
			cin >> temp;
			arr.push_back(temp);
			if (i<6) { temp_arr.push_back(0); }
			else { temp_arr.push_back(1); }

		}

		temp = 0;

		do {
			
			for (int x : temp_arr) {
				cout << x << ' ';
			}
			cout << "\n";
		} while (next_permutation(temp_arr.begin(), temp_arr.end()));

		temp_arr.clear();
		arr.clear();
		cout << "\n";
	}

	return 0;
}

