#include "stdafx.h"
#include <iostream>
#include <utility>
#include <queue>

using namespace std;

queue<pair<int, int>> tomatoQ;
int board[1001][1001];
int check[1001][1001];
int nH[4] = { 1,-1,0,0 };
int nW[4] = { 0,0,1,-1 };

void ripe(int h, int w) {

	while (!tomatoQ.empty())
	{
		int cH = tomatoQ.front().first;
		int cW = tomatoQ.front().second;
		tomatoQ.pop();

		for (int i = 0; i < 4; i++)
		{
			int nextH = cH + nH[i];
			int nextW = cW + nW[i];
			if (board[nextH][nextW] == 0 && check[nextH][nextW] == -1)
			{
				if (nextH >= 0 && nextW >= 0 && nextH < h && nextW < w)
				{
					check[nextH][nextW] = check[cH][cW] + 1;
					tomatoQ.push(make_pair(nextH, nextW));
				}
			}
		}
	}
}

int main()
{
	int h, w;
	cin >> w >> h;

	for (int i = 0; i < h; i++)
	{
		for (int j = 0; j < w; j++)
		{
			cin >> board[i][j];
			check[i][j] = -1;
			if (board[i][j] == 1) {
				check[i][j] = 0;
				tomatoQ.push(make_pair(i, j));
			}
		}
	}

	ripe(h, w);

	int day = 0;
	for (int i = 0; i < h; i++) {
		for (int j = 0; j < w; j++) {
			if (board[i][j] == 0 && check[i][j] == -1) {
				cout << -1 << "\n";
				return 0;
			}
			if (day < check[i][j]) {
				day = check[i][j];
			}
		}
	}

	cout << day << endl;
}