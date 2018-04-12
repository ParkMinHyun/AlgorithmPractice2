#include "stdafx.h"
#include <iostream>
#include <cstdio>
#include <vector>
#include <cmath>

using namespace std;

int tc, N, X, cnt;
float map[21][21];

void check(vector<int> v) {

	vector<bool> c(N, false);
	for (int i = 1; i < N; i++) {
		if (v[i - 1] != v[i]) {

			// 낮은 칸과 높은 칸의 높이 차이는 1이어야 한다.
			if (abs(v[i] - v[i - 1]) != 1) {
				return;
			}

			if (v[i - 1] < v[i]) {
				for (int j = 1; j <= X; j++) {
					if (i - j < 0) {
						// 경사로를 놓다가 범위를 벗어나는 경우
						return;
					}
					if (v[i - 1] != v[i - j]) {
						// 낮은 지점의 칸의 높이가 모두 같지 않거나, L개가 연속되지 않은 경우
						return;
					}
					if (c[i - j]) {
						// 경사로를 놓은 곳에 또 경사로를 놓는 경우
						return;
					}
					c[i - j] = true;
				}
			}
			else {
				for (int j = 0; j < X; j++) {
					if (i + j >= N) {
						// 경사로를 놓다가 범위를 벗어나는 경우
						return;
					}
					if (v[i] != v[i + j]) {
						// 낮은 지점의 칸의 높이가 모두 같지 않거나, L개가 연속되지 않은 경우
						return;
					}
					if (c[i + j]) {
						// 경사로를 놓은 곳에 또 경사로를 놓는 경우
						return;
					}
					c[i + j] = true;
				}
			}
		}
	}
	// 체크에 안걸렸을 경우 활주로 건설 횟수 증가
	cnt++;
}

int main() {

	cin >> tc;
	for (int x = 1; x <= tc; x++) {
		cin >> N >> X;

		cnt = 0;
		for (int i = 0; i < N; i++) {
			for (int j = 0; j < N; j++) {
				cin >> map[i][j];
			}
		}

		// 열, 행 검사
		for (int i = 0; i < N; i++) {
			vector<int> v;
			for (int j = 0; j < N; j++) v.push_back(map[i][j]);
			check(v);

			v.clear();

			for (int j = 0; j < N; j++) v.push_back(map[j][i]);
			check(v);
		}
		cout << "#" << x << " " << cnt << '\n';
	}
}