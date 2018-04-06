#include "stdafx.h"
#include <iostream>
#include <cstdio>
#include <string>

using namespace std;

int n, m, result;
string a[50], b[50];

int main() {
	cin >> n >> m;
	for (int i = 0; i < n; i++) {
		cin >> a[i];
	}
	for (int i = 0; i < n; i++) {
		cin >> b[i];
	}

	for (int i = 0; i < n - 2; i++) {
		for (int j = 0; j < m - 2; j++) {
			if (a[i][j] == b[i][j]) {
				continue;
			}
			for (int k = i; k < i + 3; k++){
				for (int l = j; l < j + 3; l++) {
					a[k][l] = '1' + '0' - a[k][l];
				}
			}
			result++;
		}
	}

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			if (a[i][j] != b[i][j]) {
				result = -1;
			}
		}
	}

	cout << result;
	return 0;
}