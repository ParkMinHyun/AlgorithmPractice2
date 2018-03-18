#include "stdafx.h"
#include <iostream>
#include <utility>
#include <queue>

using namespace std;

queue<pair<int, int>> pathQ;
int board[101][101];
int check[101][101];
int nH[4] = { 1,-1,0,0 };
int nW[4] = { 0,0,1,-1 };

void checkPath(int h, int w) {

	while (!pathQ.empty())
	{
		int cH = pathQ.front().first;
		int cW = pathQ.front().second;
		pathQ.pop();

		for (int i = 0; i < 4; i++)
		{
			int nextH = cH + nH[i];
			int nextW = cW + nW[i];
			if (board[nextH][nextW] == 1)
			{
				if (nextH >= 0 && nextW >= 0 && nextH < h && nextW < w)
				{
					if (check[nextH][nextW] == 999999 || check[nextH][nextW] > check[cH][cW] + 1) {
						check[nextH][nextW] = check[cH][cW] + 1;
						pathQ.push(make_pair(nextH, nextW));
					}
				}
			}
		}
	}
}

int main()
{
	int h, w;
	cin >> h >> w;

	for (int i = 0; i < h; i++)
	{
		for (int j = 0; j < w; j++)
		{
			scanf_s("%1d", &board[i][j]);
			if (board[i][j] == 1) {
				check[i][j] = 999999;
			}
		}
	}

	pathQ.push(make_pair(0, 0));
	check[0][0] = 1;

	checkPath(h, w);

	cout << check[h - 1][w - 1] << endl;
}