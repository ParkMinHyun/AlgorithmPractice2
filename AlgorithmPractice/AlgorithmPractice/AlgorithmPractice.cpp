#include "stdafx.h"
#include <iostream>
#include <vector>

using namespace std;

int min = 999999999;
int price[4], arr[13];

void search(int month, int cost) {
	if (month >= 12) {
		if (cost < min) {
			min = cost;
		}
		return;
	}

	search(month + 1, cost + arr[month] * price[0]);
	search(month + 1, cost + price[1]);
	search(month + 3, cost + price[2]);
	search(month + 12, cost + price[3]);
}

int main() {
	int N;
	cin >> N;

	for (int testCase = 1; testCase <= N; testCase++) {
		min = 999999999;

		for (int i = 0; i < 4; i++)
			cin >> price[i];
		for (int i = 0; i < 12; i++)
			cin >> arr[i];

		search(0, 0);
		cout << "#" << testCase << ":" << min << '\n';
	}
}