#include "stdafx.h"
#include <iostream>
#include <cstdio>
#include <algorithm>
#include <vector>
#include <cmath>
#include <climits>

using namespace std;

vector<int> permV;

int main() {
	int tc, N;

	cin >> tc;
	for (int x = 1; x <= tc; x++) {
		cin >> N;

		permV.clear();
		int map[17][17];
		for (int i = 0; i < N; i++) {
			for (int j = 0; j < N; j++) {
				cin >> map[i][j];
			}
		}

		// 2개 조합 만들기
		for (int i = 0; i < N / 2; i++) {
			permV.push_back(1);
			permV.push_back(2);
		}
		sort(permV.begin(), permV.end());

		// 순열 조합
		int permVSize = permV.size();
		int nMin = INT_MAX;
		do {
			vector<int> arrA, arrB;
			for (int i = 0; i < permVSize; i++) {
				(permV[i] == 1) ? arrA.push_back(i) : arrB.push_back(i);
			}

			int sumA = 0, sumB = 0;
			for (int i = 0; i < N / 2 - 1; i++) {
				for (int j = i + 1; j < N / 2; j++) {
					sumA += map[arrA[i]][arrA[j]];
					sumA += map[arrA[j]][arrA[i]];
				}
			}

			for (int i = 0; i < N / 2 - 1; i++) {
				for (int j = i + 1; j < N / 2; j++) {
					sumB += map[arrB[i]][arrB[j]];
					sumB += map[arrB[j]][arrB[i]];
				}
			}
			nMin = min(nMin, abs(sumA - sumB));

		} while (next_permutation(permV.begin(), permV.end()));

		cout << "#" << x << ' ' << nMin << '\n';
	}

}