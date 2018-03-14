#include "stdafx.h"
#include <iostream>
#include <vector>
#include <stack>
#include <string>

using namespace std;
int main() {
	string str;
	long long sum = 0;

	stack<string> strStack;
	cin >> str;

	int strLen = str.size();
	for (int i = 0; i < strLen; i++) {

		if (i != strLen - 1) {
			if (str[i] == '(' && str[i + 1] == ')') {
				sum += strStack.size();
				i++;
				continue;
			}
		}
		if (str[i] == '(') {
			strStack.push("(");
		}
		else if (str[i] == ')') {
			if (strStack.size() != 0){
				sum++;
				strStack.pop();
			}
		}
	}
	cout << sum;
}