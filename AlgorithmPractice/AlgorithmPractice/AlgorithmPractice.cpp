#include "stdafx.h"
#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;

int main()
{
	int des, m, temp, ans;
	vector<bool> disable(10);

	cin >> des >> m;
	for (int i = 0; i < m; i++)
	{
		cin >> temp;
		disable[temp] = true;
	}

	ans = abs(100 - des);

	for (int i = 0; i <= 1000000; i++)
	{
		if (i == 5455) {
			int a = 3;
		}
		bool can = true;
		int temp = i, len = 0;
		while (temp)
		{
			if (disable[temp % 10]) {
				can = false;
			}
			temp /= 10; 
			len++;
		}
		if (i == 0) {
			len = 1;
			if (disable[0]) {
				can = false;
			}
		}
		if (can) {
			ans = min(ans, abs(des - i) + len);
		}
	}
	cout << ans << endl;
	return 0;
}