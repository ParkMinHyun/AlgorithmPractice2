#include "stdafx.h"
#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
#include <string.h>
#include <climits>

using namespace std;

int priceMin;
int N, price[4], month[12];

void dfs(int curMonth, int sum) {
	if (curMonth >= 12) {
		priceMin = min(sum, priceMin);
		return;
	}

	dfs(curMonth + 1, sum + (price[0] * month[curMonth]));	// 하루
	dfs(curMonth + 1, sum + price[1]);						// 한달
	dfs(curMonth + 3, sum + price[2]);					    // 세달
}

int main()
{
	cin >> N;
	for (int a = 1; a <= N; a++) {

		for (int i = 0; i < 4; i++) {
			cin >> price[i];
		}
		for (int i = 0; i < 12; i++) {
			cin >> month[i];
		}
		
		priceMin = INT_MAX;
		dfs(0, 0);
		priceMin = min(priceMin, price[3]);
		cout << "#" << a << ' ' << priceMin << '\n';
	}
}