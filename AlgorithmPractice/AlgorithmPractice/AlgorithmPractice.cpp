#include "stdafx.h"
#include <iostream>
#include <queue>
#include <vector>
#include <algorithm>
#include <string>

using namespace std;

int N, num, start, des;
vector<int> a(4);

int converNum(vector<int> arr) {
	return ((arr[0] * 10 + arr[1]) * 10 + arr[2]) * 10 + arr[3];
}

vector<int> convertArray(int num) {

	vector<int> tA(4);
	for (int i = 3; i >= 0; i--) {
		tA[i] = num % 10;
		num /= 10;
	}
	return tA;
}

void bfs() {

	num = converNum(a);

	vector<bool> visit(10000);
	queue<pair<int, string>> sQ;
	sQ.push(make_pair(num,""));

	while (!sQ.empty()) {
		int digit = sQ.front().first;
		string str = sQ.front().second;

		visit[digit] = true;
		sQ.pop();

		if (!visit[(2 * digit) % 10000]) {
			sQ.push(make_pair((2 * digit) % 10000, str+"D"));
		}

		int tempN = digit - 1;
		if (tempN == -1) {
			tempN = 9999;
		}
		if (!visit[tempN]) {
			sQ.push(make_pair(tempN, str + "S"));
		}

		vector<int> tempA = convertArray(digit);

		rotate(tempA.begin(), tempA.begin() + 1, tempA.end()); 
		if (!visit[converNum(tempA)]) {
			sQ.push(make_pair(converNum(tempA), str + "L"));
		}

		rotate(tempA.rbegin(), tempA.rbegin() + 2, tempA.rend());
		if (!visit[converNum(tempA)]) {
			sQ.push(make_pair(converNum(tempA), str + "R"));
		}
	}
}

int main() {

	cin >> N;

	while (N--) {
		cin >> start >> des;
		
		a = convertArray(start);

		bfs();
	}

	return 0;
}