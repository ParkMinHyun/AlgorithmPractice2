#include "stdafx.h"
#include <iostream>
#include <cstdio>
#include <algorithm>
#include <string>

using namespace std;

string str;
int len, sum;

int main() {
	cin >> str;
	len = str.size();

	sort(str.begin(), str.end());

	for (int i = 0; i < len; i++) {
		sum += str[i] - '0';
	}

	if (str[0] == '0' && sum % 3 == 0) {
		reverse(str.begin(), str.end());
		cout << str;
	}
	else {
		cout << -1;
	}
}