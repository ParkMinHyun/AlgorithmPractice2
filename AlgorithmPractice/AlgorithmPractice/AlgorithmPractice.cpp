#include "stdafx.h"
#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

struct Node {
	int num;
	int startY;
	int startX;
};

int T, N, M, C, subMax, resultMax;
int pan[11][11];
vector<Node> v;
vector<Node> result;

void dfs(int y, int x, int sum, int remain, int pos) {
	// M 보다 같거나 많이 담겼을 경우 return;
	if (pos > M ) {
		return;
	}
	
	// 현재 벌꿀 값이 remain 보다 적게 남아있을 경우 계산해주기
	if (remain - pan[y][x] >= 0) {
		remain -= pan[y][x];
		sum += pan[y][x] * pan[y][x];
		subMax = max(sum, subMax);
	}

	// 부분 합 검사 dfs 돌리기
	for (int i = 1; i < M - pos; i++) {
		dfs(y, x + i, sum, remain, pos + i);
	}
}

int main() {

	cin >> T;
	for (int i = 1; i <= T; i++) {
		cin >> N >> M >> C;

		// 벌꿀 통 계산
		v.clear();
		result.clear();
		resultMax = 0;
		for (int i = 0; i < N; i++) {
			for (int j = 0; j < N; j++) {
				cin >> pan[i][j];
			}
		}

		// 부분 합 담기
		for (int i = 0; i < N; i++) {
			for (int j = 0, k; j <= N - M; j++) {
				v.push_back({ 0, i, j });
			}
		}

		// 부분 합 검사 및 부분 합 result Vector에 담기
		int tempSize = v.size();
		for (int i = 0; i < tempSize; i++) {
			subMax = 0;

			for (int j = 0; j < M; j++) {
				dfs(v[i].startY, v[i].startX + j, 0, C, j);
			}
			result.push_back({ subMax, v[i].startY, v[i].startX });
		}

		// 중첩 계산
		int resultSize = result.size();
		for (int i = 0; i < resultSize; i++) {
			for (int j = i + 1; j < resultSize; j++) {
				if (result[i].startY == result[j].startY &&
					result[i].startX < result[j].startX &&
					result[j].startX < result[i].startX + M) {
					continue;
				}
				else {
					resultMax = max(resultMax, (result[i].num + result[j].num));
				}
			}
		}
		cout << "#" << i << ' ' << resultMax << '\n';
	}
}