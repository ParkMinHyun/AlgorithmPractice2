#include "stdafx.h"
#include <cstdio>
#include <iostream>

using namespace std;

int main() {

	int M, W, I, sum = 0;
	cin >> M >> W >> I;

	while (M >= 2 && W >= 1 && M + W >= I + 3) {
		M -= 2;
		W -= 1;
		sum++;
	}

	cout << sum;
}