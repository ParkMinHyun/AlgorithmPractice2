#include "stdafx.h"
#include <iostream>
#include <cstdio>
#include <vector>
#include <string>
using namespace std;

/*
* Time complexity: O(N)
* Space complexity: O(N)
*/

int main()
{
	int N;
	string str;

	cin >> N;
	for (int i = 0; i < N; i++) {
		cin >> str;

		int cnt = 1;
		for (int i = 0; i < str.length() - 1; i++) {
			// 같지 않았을 경우 
			if (str[i] != str[i + 1]) {
				cout << cnt << str[i];
				cnt = 1;
				continue;
			}
			cnt++;
		}
		cout << cnt << str[str.length() - 1] << '\n';
	}
	return 0;
}