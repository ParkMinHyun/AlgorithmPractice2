#include "stdafx.h"
#include <iostream>
#include <algorithm>
#include <vector>
#include <string.h>
#include <queue>

using namespace std;

int T, N, M, houseNum;
int pan[21][21];

int mY[4] = { 1,-1,0,0 };
int mX[4] = { 0,0,1,-1 };
bool visit[21][21];

struct Node {
	int y;
	int x;
};

int operFee(int K) {
	return  (K * K) + (K - 1) * (K - 1);
}

void search(int y, int x) {
	queue<Node> q;
	int houseCnt, K = 1;
	q.push({ y, x });

	// 현재 검사 출발 지점에 집이 있으면 houseCnt = 1
	(pan[y][x] == 1) ? houseCnt = 1 : houseCnt = 0;
	// 방문 표시
	visit[y][x] = true;

	// bfs 검사 (계속 넓혀 나가기 : 모든 지점 visit가 true 되면 종료)
	while (!q.empty()) {
		
		if (K > N+1) {
			return;
		}

		int qSize = q.size();
		for (int s = 0; s < qSize; s++) {
			int cY = q.front().y;
			int cX = q.front().x;
			q.pop();

			// 십자가 검사
			for (int i = 0; i < 4; i++) {
				int nY = cY + mY[i];
				int nX = cX + mX[i];
				
				// 범위 초과 or 이미 방문했으면 continue;
				if (nY >= N || nX >= N || nY < 0 || nX < 0 || visit[nY][nX]) {
					continue;
				}

				// 옮겨갈 지점에 집이 있으면 houseCnt ++;
				if (pan[nY][nX] == 1) {
					houseCnt++;
				}

				// 옮겨갈 지점 visit = true 체크한 후 queue에 담기
				visit[nY][nX] = true;
				q.push({ nY,nX });
			}
		}
		// K 증가 ( 맨 처음엔 1, 그 다음 2, 그 다음 3 ....... N = 20일 때 최대 39)
		K++;
		// K 상황 : 손해보지 않으면서 집 갯수가 더 많을 경우
		// 2부터 검사
		if (houseNum < houseCnt && houseCnt * M - operFee(K) >= 0) {
			houseNum = houseCnt;
		}
	}
}

int main() {
	cin >> T;

	for (int x = 1; x <= T; x++) {
		cin >> N >> M;

		for (int i = 0; i<21; i++) {
			memset(pan[i], 0, sizeof(int) * 21); //모든 값 0으로 초기화
		}
		
		// 입력
		for (int i = 0; i < N; i++) {
			for (int j = 0; j < N; j++) {
				cin >> pan[i][j];
			}
		}

		houseNum = 1;
		// K=2 부터 한줄 한줄 검사
		for (int i = 0; i < N; i++) {
			for (int j = 0; j < N; j++) {
				// visit 초기화
				memset(visit, false, sizeof(visit));
				search(i, j);
			}
		}
		cout << "#" << x << " " << houseNum << '\n';
	}
}