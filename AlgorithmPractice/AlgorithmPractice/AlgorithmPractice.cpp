#include "stdafx.h"
#include <cstdio>
#include <iostream>
#include <cmath>

using namespace std;


void hanoi(int x, int y, int N) {
	if (N == 0) {
		return;
	}

	hanoi(x, 6 - x - y, N - 1);
	cout << x << " " << y << '\n';
	hanoi(6 - x - y, y, N - 1);
}
int main() {
	int N;
	cin >> N;
	cout << pow(2, N) - 1 << '\n';
	hanoi(1, 3, N);
	return 0;
}