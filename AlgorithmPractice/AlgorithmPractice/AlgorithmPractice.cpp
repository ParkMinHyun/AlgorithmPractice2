#include "stdafx.h"
#include <iostream>
#include <algorithm>
using namespace std;

int main()
{

	int n;
	cin >> n;

	int arr[10000];

	for (int i = 0; i < n; i++) {
		cin >> arr[i];
	}

	if (next_permutation(arr, arr + n)) {
		for (int i = 0; i < n; i++) {
			printf("%d ", arr[i]);
		}
	}
	else {
		cout << -1 << endl;
	}

	return 0;
}