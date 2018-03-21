	#include "stdafx.h"
	#include <iostream>
	#include <vector>
	#include <algorithm>
	using namespace std;

	int main()
	{
		int n;
		cin >> n;
		vector<int> arr(n+1);

		arr[1] = 1;
		arr[2] = 2;
		arr[3] = 3;

		for (int i = 4; i <= n; i++) {
			arr[i] = (arr[i - 1] + arr[i - 2]) % 10007;
		}

		cout << arr[n] % 10007 << endl;
		return 0;
	}