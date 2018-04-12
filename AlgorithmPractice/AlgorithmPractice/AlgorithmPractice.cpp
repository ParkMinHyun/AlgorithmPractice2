#include "stdafx.h"
#include <iostream>
#include <cstdio>
#include <algorithm>
#include <vector>
#include <climits>

using namespace std;

int N, num, nMax = INT_MIN, nMin = INT_MAX;
vector<int> numV, permV;

int main() {
	cout << INT_MIN;
	cin >> N;

	for (int i = 0; i < N; i++) {
		cin >> num;
		numV.push_back(num);
	}
	for (int i = 1; i <= 4; i++) {
		cin >> num;
		for (int j = 0; j < num; j++) {
			permV.push_back(i);
		}
	}

	sort(permV.begin(), permV.end());
	do {
		int ans = numV[0];
		for (int i = 0; i < permV.size(); i++) {
			switch (permV[i]){
			case 1: ans += numV[i+1]; break;
			case 2: ans -= numV[i+1]; break;
			case 3: ans *= numV[i+1]; break;
			case 4: ans /= numV[i+1]; break;
			}
		}

		nMin = min(nMin, ans);
		nMax = max(nMax, ans);

	} while (next_permutation(permV.begin(), permV.end()));

	cout << nMax << '\n' << nMin << '\n';
}