#include "stdafx.h"
#include <iostream>
#include <cstdio>
#include <vector>
#include <algorithm>
#include <string>
using namespace std;

int L, C;
vector<string> arr;

void bruteforce(int pos, string str) {

	if (str.size() == L) {
		int a= 0, b= 0;
		for (int i = 0; i < L; i++) {
			if (str[i] == 'a' || str[i] == 'e' || str[i] == 'i' || str[i] == 'o' || str[i] == 'u') {
				a++;
				continue;
			}
			b++;
		}

		if (a < 1 || b < 2) {
			return;
		}
		cout << str << '\n';
	}

	for (int i = pos + 1; i < C; i++) {
		bruteforce(i, str + arr[i]);
	}
}

int main() {
	cin >> L >> C;

	arr.resize(C);
	for (int i = 0; i < C; i++) {
		cin >> arr[i];
	}

	sort(arr.begin(), arr.end());

	for (int i = 0; i < C; i++) {
		bruteforce(i, arr[i]);
	}
}