#include "stdafx.h"
#include <iostream>
#include <cstdio>
#include <vector>
#include <string>
#include <queue>

using namespace std;

int N, sum;

bool row[15];             // row에 대한 세로 예외 
bool dia1[30], dia2[30];  // 대각선 두 방향 예외

void dfs(int y)
{
	if (y == N)
	{
		sum++;
		return;
	}
	 
	for (int i = 0; i < N; i++)
	{
		if (row[i] || dia1[y + i] || dia2[N - i + y - 1])
			continue;

		row[i] = true;
		dia1[y + i] = true;
		dia2[N - 1 + y - i] = true;

		dfs(y + 1);

		row[i] = false;
		dia1[y + i] = false;
		dia2[N - 1 + y - i] = false;
	}
}

int main()
{
	cin >> N;
	dfs(0);
	cout << sum;
	return 0;
}
