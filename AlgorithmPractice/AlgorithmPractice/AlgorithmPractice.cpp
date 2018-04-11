#include "stdafx.h"
#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
#include <string.h>

using namespace std;

struct Info {
	int personNum;
	int time;
};

struct Repair {
	int infoNum;
	int personNum;
};

int T, N, M, K, A, B;
vector<int> aV, bV;

vector<Info> infoV;
queue<Info> infoQ;
queue<Repair> repairQ;

bool comp(const Info &a, const Info &b) {
	if (a.time != b.time)
		return a.time < b.time;
	return a.personNum < b.personNum;
}

int search() {
	int result = -1;
	int userCnt = 1;
	int workTime = infoV[0].time;

	vector<Info> infoDesk(10);
	vector<Info> repairDesk(10);

	// queue에 모두 넣어주기
	for (int i = 0; i < K; i++) infoQ.push(infoV[i]);

	// user가 모두 작업을 완료할 때 까지 반복
	while (userCnt <= K) {
		// Info Desk 작업 반복
		for (int i = 0; i < N; i++) {
			// 이미 작업 중인 것들은 시간 - 1 해주고, 0이면 repairQ에 Info 받은 위치, 유저 번호 저장
			if (infoDesk[i].time > 0) {
				infoDesk[i].time--;
				if (infoDesk[i].time == 0) {
					repairQ.push({ i, infoDesk[i].personNum });
				}
			}
			// Info Desk가 비었을 경우, 대기자가 있고 대기자가 작업소에 도착했을 경우에만 InfoDesk에 넣어주기
			if (infoDesk[i].time == 0 && infoQ.size() > 0 && infoQ.front().time <= workTime) {
				infoDesk[i] = { infoQ.front().personNum, aV[i] };
				infoQ.pop();
			}
		}

		// Repair Desk 작업 반복
		for (int i = 0; i < M; i++) {
			// Info와 마찬가지로 작업중인 것들 시간 - 1 해주고, 수리 완료 했으면 userCnt 값 증가.
			if (repairDesk[i].time > 0) {
				repairDesk[i].time--;
				if (repairDesk[i].time == 0) {
					userCnt++;
				}
			}

			// repairDesk가 비어있고 repairQ에 사람이 대기 중이라면 repairDesk에 배치시키기
			if (repairDesk[i].time == 0 && !repairQ.empty()) {
				int infoNum = repairQ.front().infoNum;
				int personNum = repairQ.front().personNum;
				repairQ.pop();

				repairDesk[i] = { personNum , bV[i] };
				// 지갑 검사
				if (infoNum + 1 == A && i + 1 == B) {
					(result == -1) ? result += personNum + 1 : result += personNum;
				}
			}
		}
		workTime++;
	}
	return result;
}

int main() {
	cin >> T;
	for (int tc = 1; tc <= T; tc++) {
		// A창구, B창구, K명, 지갑 분실 위치 (A,B)
		cin >> N >> M >> K >> A >> B;

		aV.clear(); bV.clear();
		infoV.clear();

		aV.resize(N); bV.resize(M);
		infoV.resize(K);

		for (int i = 0; i < N; i++) {
			cin >> aV[i];
		}
		for (int i = 0; i < M; i++) {
			cin >> bV[i];
		}
		for (int i = 0; i < K; i++) {
			cin >> infoV[i].time;
			infoV[i].personNum = i + 1;
		}
		// 대기 시간 짧은 순으로 정렬
		sort(infoV.begin(), infoV.end(), comp);
		// 검사
		cout << "#" << tc << " " << search() << '\n';
	}
}