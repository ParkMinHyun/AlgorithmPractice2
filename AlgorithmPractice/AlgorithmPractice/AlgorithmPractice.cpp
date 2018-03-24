#include "stdafx.h"
#include <iostream>
#include <vector>
#include <queue>
using namespace std;

vector<bool> visit;
bool num[10000];
int result;
queue<pair<int, int>> nQ;

int main() {
	int N, A, B;
	int temp1, temp2, temp3, temp4;

	for (int i = 2; i < 10000; i++) {
		if (!num[i]) {
			for (int j = 2; j * i < 10000; j++) {
				num[i * j] = true;
			}
		}
	}

	cin >> N;
	while (N--) {
		cin >> A >> B;

		result = -1;
		visit.clear();
		visit.resize(10000, false);

		if (A == B) {
			cout << 0 << '\n';
			return 0;
		}
		else if (!num[A]) {

			nQ.push(make_pair(A, 0));
			while (!nQ.empty()) {
				int pos = nQ.front().first;
				int time = nQ.front().second;

				visit[pos] = true;
				nQ.pop();

				if (pos == B) {
					result = time;
					break;
				}

				for (int i = 0; i < 10; i++) {
					if (i != 0) {
						temp1 = i * 1000 + pos % 1000;
						if (!num[temp1] && !visit[temp1]) {
							nQ.push(make_pair(temp1, time + 1));
						}
					}

					temp2 = i * 100 + (pos / 1000) * 1000 + pos % 100;
					temp3 = i * 10 + (pos / 1000) * 1000 + ((pos % 1000) / 100) * 100 + pos % 10;
					temp4 = i + (pos - (pos % 10));

					if (!num[temp2] && !visit[temp2]) {
						nQ.push(make_pair(temp2, time + 1));
					}
					if (!num[temp3] && !visit[temp3]) {
						nQ.push(make_pair(temp3, time + 1));
					}
					if (!num[temp4] && !visit[temp4]) {
						nQ.push(make_pair(temp4, time + 1));
					}
				}
			}
		}

		if (result == -1) {
			cout << "Impossible\n";
		}
		else {
			cout << result << '\n';
		}
	}
	return 0;
}