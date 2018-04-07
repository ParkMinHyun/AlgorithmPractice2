#include "stdafx.h"
#include <iostream>
#include <cstdio>
#include <vector>
#include <algorithm>
#include <iostream>

// 출처: http://simsimjae.tistory.com/41 [흔한 컴공의 코딩 블로그]

using namespace std;

int input[1001];
int dp[1001];

int main()
{
	int n;
	cin >> n;
	for (int i = 0; i<n; i++){
		cin >> input[i];
	}

	dp[0] = 1;
	for (int i = 0; i<n; i++)
	{
		int maxx = 0;
		for (int j = i - 1; j >= 0; j--)
		{
			if (input[i] > input[j])
			{
				maxx = max(maxx, dp[j]);
			}
		}
		dp[i] = maxx + 1;
	}

	int ret = -1;
	for (int i = 0; i<n; i++){
		ret = max(dp[i], ret);
	}

 	cout << ret << endl;


	return 0;
}

