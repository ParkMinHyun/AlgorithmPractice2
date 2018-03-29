#include "stdafx.h"
#include <iostream>
#include <cstdio>
#include <algorithm>
#include <vector>
#include <queue>

using namespace std;

vector<int> arr;
int maxG = 0;

int gcd(int a, int b)
{
	if (a % b == 0)
		return b;
	else
		return gcd(b, a % b);
}

void search(int item, int pos) {

	vector<int> temp;
	queue<pair<vector<int>, int>> q;

	temp.push_back(item);
	q.push(make_pair(temp, pos));

	while (!q.empty()) {
		vector<int> newV = q.front().first;
		int newP = q.front().second;

		q.pop();

		vector<int> num = newV;
		int numSize = num.size();
		if (num.size() != 1) {
			num.push_back(1);
			for (int i = 1; i < numSize + 1; i++) {
				num[i] = gcd(num[i], num[i - 1]);
			}
		}
		else {
			num[0] = 1;
		}

		if (num[numSize - 1] == 1) {
			int newVSize = newV.size();
			maxG = max(maxG, newVSize);
		}

		if (newP + 1 != arr.size()) {
			newV.push_back(arr[newP + 1]);
			q.push(make_pair(newV, newP + 1));
		}
	}
}

int main() {
	int N;
	cin >> N;
	arr.resize(N);
	for (int i = 0; i < N; i++) {
		cin >> arr[i];
	}

	sort(arr.begin(), arr.end());

	for (int i = 0; i < N; i++) {
		search(arr[i], i);
	}

	cout << maxG << '\n';
	return 0;
}