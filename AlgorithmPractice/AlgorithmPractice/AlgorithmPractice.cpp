#include "stdafx.h"
#include <iostream>
#include <vector>
#include <stack>
#include <string>

using namespace std;
int main() {
	string str;
	long long sum = 0;

	stack<char> strStack;
	cin >> str;

	int strLen = str.size();
	for (int i = 0; i < strLen; i++) {
		if (str[i] == '(')
			strStack.push('(');
		else {
			strStack.pop();

			(str[i - 1] == '(') ? sum += strStack.size() : sum++;
		}
	}
	cout << sum;
}