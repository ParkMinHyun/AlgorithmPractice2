#include "stdafx.h"
#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
#include <cmath>
#include <string.h>

using namespace std;

struct Node {
	int y;
	int x;
	int time;
};

int T, N;
int map[11][11];
vector<Node> user;
vector<Node> stairType;
vector<int> tempStairInfo[2];
int nMin;

int getDistance(int uY, int uX, int sY, int sX) {
	return abs(uY - sY) + abs(uX - sX);
}

int cal() {

	vector<int> stairInfo[2];
	stairInfo[0] = tempStairInfo[0];
	stairInfo[1] = tempStairInfo[1];

	// 오름차순 정렬
	sort(stairInfo[0].begin(), stairInfo[0].end());
	sort(stairInfo[1].begin(), stairInfo[1].end());

	int nMax[2] = { 1, 1 };
	// 2개의 계단에 대해 각각 stair 계산;
	for (int i = 0; i < 2; i++) {
		queue<int> q;

		while (!stairInfo[i].empty()) {

			nMax[i] ++;
			for (int j = 0; j < stairInfo[i].size(); j++) {
				// 계단이 차있을 때
				if (q.size() == 3) {
					// 차있는 것들 다 빼주기
					for (int k = 0; k < q.size(); k++) {
						stairInfo[i][k] -= 1;
						// 다 내려왔으면 pop 해주고 stairInfo에서 제거해주기
						if (stairInfo[i][k] == -stairType[i].time) {
							q.pop();
							stairInfo[i].erase(stairInfo[i].begin());
							k--;
						}
					}
					// 계단 안온 것들 -- 해주기 (대기 아닌 것들 만)
					for (int h = q.size(); h < stairInfo[i].size(); h++) {
						if (stairInfo[i][h] != 0) {
							stairInfo[i][h] -= 1;
							if (stairInfo[i][h] == 0) {
								if (q.size() != 3) {
									q.push(0);
									continue;
								}
							}
						}
					}
					// 다 작업해줬으니 break; 
					break;
				}

				else {
					stairInfo[i][j] -= 1;
					if (stairInfo[i][j] == -stairType[i].time) {
						stairInfo[i].erase(stairInfo[i].begin() + j);
						if (!q.empty())
							q.pop();
						j--;
					}
					else if (stairInfo[i][j] == 0) {
						q.push(0);
						if (q.size() == 3) {
							for (int k = j + 1; k < stairInfo[i].size(); k++) {
								if (stairInfo[i][k] - 1 >= 0) {
									stairInfo[i][k] -= 1;
								}
							}
							break;
						}
					}
				}
			}
		}
	}
	return max(nMax[0], nMax[1]);
}

void search(int cnt) {
	if (cnt == user.size()) {
		nMin = min(nMin, cal());
		return;
	}

	tempStairInfo[0].push_back(getDistance(user[cnt].y, user[cnt].x, stairType[0].y, stairType[0].x));
	search(cnt + 1);
	tempStairInfo[0].erase(tempStairInfo[0].begin() + tempStairInfo[0].size() - 1);

	tempStairInfo[1].push_back(getDistance(user[cnt].y, user[cnt].x, stairType[1].y, stairType[1].x));
	search(cnt + 1);
	tempStairInfo[1].erase(tempStairInfo[1].begin() + tempStairInfo[1].size() - 1); 
}

int main() {
	cin >> T;

	for (int tc = 1; tc <= T; tc++) {
		cin >> N;

		// 초기화
		nMin = 999999999;
		user.clear();
		stairType.clear();
		for (int i = 0; i < 2; i++) tempStairInfo[i].clear();

		// 입력
		for (int i = 0; i < N; i++) {
			for (int j = 0; j < N; j++) {
				cin >> map[i][j];
				if (map[i][j] != 0 && map[i][j] != 1) {
					stairType.push_back({ i,j,map[i][j] });
				}
				if (map[i][j] == 1) {
					user.push_back({ i, j,0 });
				}
			}
		}

		search(0);

		cout << "#" << tc << " " << nMin << '\n';
	}
}