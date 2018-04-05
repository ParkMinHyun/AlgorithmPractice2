#include "stdafx.h"
#include <iostream>
#include <cstdio>
#include <vector>

// 출처 : http://debuglog.tistory.com/83 활용
// 시간초과 났던 이유 : 나는 brute force로 풀었음 --> 백트래킹으로 최소화시키기.

using namespace std;

int arr[9][9];
bool rV[9][10];
bool vV[9][10];
bool nV[9][10];

void print() {
	for (int i = 0; i < 9; i++) {
		for (int j = 0; j < 9; j++) {
			cout << arr[i][j] << ' ';
		}
		cout << '\n';
	}
}

void sdoku() {
	//#1. 빈칸 찾기 
	int r = -1, c = -1;

	for (int i = 0; i < 9; i++) {
		for (int j = 0; j < 9; j++) {
			if (arr[i][j] == 0) {
				r = i;
				c = j;
				break;
			}
		}
		if (r != -1) {
			break;
		}
	}

	//#2. 완성되었는지 확인 후 출력
	if (r == -1) {
		print();
	}

	//#3. 풀이(백트래킹)
	for (int num = 1; num <= 9; num++) {
		if (!rV[r][num] && !vV[c][num] && !nV[3 * (r / 3) + (c / 3)][num]) {
			rV[r][num] = vV[c][num] = nV[3 * (r / 3) + (c / 3)][num] = true;
			arr[r][c] = num;
			sdoku();
			arr[r][c] = 0;
			rV[r][num] = vV[c][num] = nV[3 * (r / 3) + (c / 3)][num] = false;
		}
	}
}


int main() {

	for (int i = 0; i < 9; i++) {
		for (int j = 0; j < 9; j++) {
			cin >> arr[i][j];
			rV[i][arr[i][j]] = true;
			vV[j][arr[i][j]] = true;
			nV[3 * (i / 3) + (j / 3)][arr[i][j]] = true;
		}
	}
	sdoku();
}