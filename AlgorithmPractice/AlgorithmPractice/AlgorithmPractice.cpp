#include "stdafx.h"
#include <iostream>
#include <cstdio>
#include <algorithm>
#include <vector>
#include <string.h>
using namespace std;

struct Node {
	int pos;
	int rotateDir;
};

vector<vector<int>> arr;
vector<Node> v;

// 현재 위치, 보낸 값, 현재 값 보낸 위치, 이전 회전 방향
void dfs(int pos, int num, int sendPos, int rotateDir) {

	// 종료조건 검사 (범위 넘어 가거나 값이 같은 경우)
	if (pos < 1 || pos > 4) {
		return;
	}

	if (num == arr[pos][(sendPos + 4) % 8]) {
		return;
	}

	// 양 옆으로 보내기
	if (sendPos == 2) {
		dfs(pos + 1, arr[pos][2], 2, -rotateDir);
	}
	else {
		dfs(pos - 1, arr[pos][6], 6, -rotateDir);
	}

	// 1이면 시계로 회전
	if (rotateDir == 1) {
		rotate(arr[pos].begin(), arr[pos].begin() + 1, arr[pos].end());
	}
	else {
		rotate(arr[pos].rbegin(), arr[pos].rbegin() + 1, arr[pos].rend());
	}

}

int main() {

	arr.resize(5);
	for (int i = 1; i <= 4; i++) arr[i].resize(8);
	
	for (int i = 1; i <= 4; i++) {
		for (int j = 0; j < 8; j++) {
			scanf_s("%1d", &arr[i][j]);
		}
	}

	int N, pos, dir, sum = 0;
	cin >> N;
	for (int i = 0; i < N; i++) {
		cin >> pos >> dir;
		v.push_back({ pos,dir });
	}

	// 입력만큼 반복
	for (int i = 0; i < N; i++) {
		// 오른쪽에게 보내기
		dfs(v[i].pos + 1, arr[v[i].pos][2], 2, v[i].rotateDir);
		// 왼쪽에게 보내기
		dfs(v[i].pos - 1, arr[v[i].pos][6], 6, v[i].rotateDir);
		// 1인 경우 시계 방향 회전
		if (v[i].rotateDir == 1) {
			rotate(arr[v[i].pos].rbegin(), arr[v[i].pos].rbegin() + 1, arr[v[i].pos].rend());
		}
		else {
			rotate(arr[v[i].pos].begin(), arr[v[i].pos].begin() + 1, arr[v[i].pos].end());
		}
	}

	if (arr[1][0] == 1) sum += 1;
	if (arr[2][0] == 1) sum += 2;
	if (arr[3][0] == 1) sum += 4;
	if (arr[4][0] == 1) sum += 8;

	// 출력
	cout << sum << '\n';
}