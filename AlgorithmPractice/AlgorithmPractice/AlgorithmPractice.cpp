#include "stdafx.h"
#include <iostream>
#include <cstdio>
#include <algorithm>
#include <string>
#include <cmath>

/*
* Time complexity: O(N2)
* Space complexity: O(N)
*/

using namespace std;

typedef struct _INFO_
{
	int x;
	int y;
	int dis;
	string name;
	int coupon;
}INFO;

INFO info[100001];
INFO temp[100001];

int uX, uY, N;

int GetDistanc(int x1, int y1, int x2, int y2)
{
	return sqrt((x2 - x1)*(x2 - x1) + (y2 - y1)*(y2 - y1));
}

bool comp(const INFO &a, const INFO &b)
{
	if (a.dis != b.dis)
		return a.dis < b.dis;


	else if (a.dis == b.dis && a.coupon != b.coupon) {
		return a.coupon > b.coupon;
	}

	else {
		if (a.name > b.name)
			return false;
		return true;
	}
}

int main()
{
	int uX, uY, N;
	cin >> uX >> uY >> N;

	for (int i = 0; i < N; i++) {
		cin >> info[i].x >> info[i].y >> info[i].name >> info[i].coupon;
		temp[i].x = info[i].x;
		temp[i].y = info[i].y;
		temp[i].dis = (GetDistanc(uX, uY, temp[i].x, temp[i].y) / 100) * 100;
		temp[i].name = info[i].name;
		temp[i].coupon = info[i].coupon;
	}
	sort(temp, temp + N, comp);

	cout << '\n';
	for (int i = 0; i < N; i++) {
		int searchNum;
		for (int j = 0; j < N; j++) {
			if (info[j].name == temp[i].name) {
				searchNum = j;
			}
		}
		cout << info[searchNum].x << ' ' << info[searchNum].y << ' '
			<< info[searchNum].name << ' ' << info[searchNum].coupon << '\n';
	}

	return 0;

}