#include "stdafx.h"
#include <iostream>
#include <vector>
#include <string.h>
#include <set>

using namespace std;

int T, N, M, K, miNum, nDir;

// X상하좌우
int mY[5] = { 0, -1, 1, 0,  0 };
int mX[5] = { 0,  0, 0, -1, 1 };

struct Node {
	int y;
	int x;
	int num;
	int dir;
	bool status;
};

vector<Node> v;

// 미생물 수 파악
int getMiNum() {
	miNum = 0;
	for (int i = 0; i < v.size(); i++) miNum += v[i].num;
	return miNum;
}

void search() {

	int vSize = v.size();
	for (int i = 0; i < vSize; i++) {

		// 상태가 이미 변경된 군집이면 skip
		if (v[i].status || v[i].num == 0) {
			continue;
		}

		v[i].y += mY[v[i].dir];
		v[i].x += mX[v[i].dir];

		// 벽에 부딪혔을 때 군집 수 1/2 + 방향 반대로 바꾸기
		if (v[i].y == 0 || v[i].x == 0 || v[i].y == N - 1 || v[i].x == N - 1) {
			v[i].num /= 2;
			switch (v[i].dir)
			{
				case 1: nDir = 2; break;
				case 2: nDir = 1; break;
				case 3: nDir = 4; break;
				case 4: nDir = 3; break;
				default: break;
			}
			v[i].dir = nDir;
			continue;
		}

		int subMax = v[i].num;
		int subNum = v[i].num;
		int maxGroupIndex = i;
		set<int> groupSet;
		groupSet.insert(i);

		// 현재 군집의 다음 이동할 곳에 다른 군집들도 이동했을 경우
		for (int j = i + 1; j < vSize; j++) {
			// i가 아닌 다른 군집들 중, 상태 체크가 안됐으면서 이동할 위치가 현재 군집 위치와 같을 경우
			if (!v[j].status && 
				v[i].y == v[j].y + mY[v[j].dir] && 
				v[i].x == v[j].x + mX[v[j].dir]) {

				v[j].y += mY[v[j].dir];
				v[j].x += mX[v[j].dir];
				// 만났다는것을 표시하고 index set에 넣어주기
				v[j].status = true;
				groupSet.insert(j);
				// 미생물 수 더해주고, 최대 값 파악하기
				subNum += v[j].num;
				if (subMax <= v[j].num) {
					subMax = v[j].num;
					maxGroupIndex = j;
				}
			}
		}

		// 군집이 만났을 경우
		if (groupSet.size() > 0) {
			for (int pos : groupSet) {
				(pos == maxGroupIndex) ? v[pos].num = subNum : v[pos].num = 0;
			}
		}
	}
}

int main() {
	cin >> T;

	for (int x = 1; x <= T; x++) {
		cin >> N >> M >> K;

		// 입력
		v.clear();
		for (int i = 0; i < K; i++) {
			int y, x, num, dir;
			cin >> y >> x >> num >> dir;
			v.push_back({ y,x,num,dir,false });
		}

		for (int i = 0; i < M; i++) {
			// 상태 모두 false로 만들어주기
			for (int j = 0; j < v.size(); j++) {
				v[j].status = false;
			}
			// 검사
			search();
		}

		cout << "#" << x << " " << getMiNum() << '\n';
	}
}