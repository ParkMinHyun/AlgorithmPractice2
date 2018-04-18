#include "stdafx.h"
#include <iostream>
#include <cstdio>
#include <algorithm>
#include <string>
#include <cmath>

/*
* Time complexity: O(N)
* Space complexity: O(N)
*/

using namespace std;

struct INFO
{
	int x;
	int y;
	int dis;
	string name;
	int coupon;
};

INFO info[100001];

int uX, uY, N;

int getDis(int x1, int y1, int x2, int y2)
{
	return sqrt((x2 - x1)*(x2 - x1) + (y2 - y1)*(y2 - y1));
}

bool comp(const INFO &a, const INFO &b)
{
	if (a.dis != b.dis) {
		return a.dis < b.dis;
	}

	else if (a.dis == b.dis && a.coupon != b.coupon) {
		return a.coupon > b.coupon;
	}

	else {
		return a.name < b.name;
	}
}

int main()
{
	int uX, uY, N, inputX, inputY, inputName, inputCoupon;
	cin >> uX >> uY >> N;

	for (int i = 0; i < N; i++) {
		cin >> inputX >> inputY >> inputName >> inputCoupon;
		info[i].x = inputX;
		info[i].y = inputY;
		info[i].dis = (getDis(uX, uY, inputX, inputY) / 100) * 100;
		info[i].name = inputName;
		info[i].coupon = inputCoupon;
	}
	sort(info, info + N, comp);

	cout << '\n';
	for (int i = 0; i < N; i++) {
		cout << info[i].x << ' ' << info[i].y << ' ' << info[i].name << ' ' << info[i].coupon << '\n';
	}

	return 0;
}