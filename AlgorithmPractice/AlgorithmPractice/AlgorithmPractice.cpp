#include "stdafx.h"
#include <iostream>
#include <vector>

using namespace std;

void main() {
	int n, k, num = 0;
	vector<int> coin(10);

	cin >> n >> k;

	for (int i = 0; i < n; i++) 
		cin >> coin[i];

	for (int i = n-1; i >= 0; i--) {
		num += k / coin[i];
		k %= coin[i];
	}

	cout << num << '\n';
}