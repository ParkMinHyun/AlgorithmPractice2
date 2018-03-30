#include "stdafx.h"
#include <iostream>
#include <cstdio>
#include <algorithm>
#include <vector>
#include <string>

using namespace std;

vector<string> arr;
vector<int> sum;

int main() {
	int start = 0, num, result;
	string str;
	cin >> str;

	int strLen = str.size();
	for (int i = 0; i < strLen; i++) {
		if (str[i] == '-') {
			arr.push_back(str.substr(start, i-start));
			start = i + 1;
		}
	}
	arr.push_back(str.substr(start, strLen));

	sum.resize(arr.size());
	for (int i = 0; i < arr.size(); i++) {
		num = 0;
		auto it = find(arr[i].begin(), arr[i].end(), '+');
		if (it != arr[i].end()) {
			for (int j = 0; j < arr[i].size(); j++) {
				if (arr[i][j] == '+') {
					sum[i] += num;
					num = 0;
				}
				else {
					num *= 10;
					num += arr[i][j] - '0';
				}
			}
			sum[i] += num;
		}
		else {
			sum[i] = atoi(arr[i].c_str());
		}
	}

	result = sum[0];
	for (int i = 1; i < sum.size(); i++) {
		result -= sum[i];
	}

	cout << result << '\n';
	return 0;
}