#include "stdafx.h"
#include <iostream>
#include <string>

using namespace std;

int main() {

	string str;
	getline(cin, str);

	int len = str.size();
	for (int i = 0; i < len; i++) {
		if (str[i] >= 'A' && str[i] <= 'Z') {
			for (int j = 1; j <= 13; j++) {
				if (str[i] + 1 > 'Z')
					str[i] = 'A';
				else
					str[i] ++;
			}
		}

		else if (str[i] >= 'a' && str[i] <= 'z') {
			for (int j = 1; j <= 13; j++) {
				if (str[i] + 1> 'z')
					str[i] = 'a';
				else
					str[i] ++;
			}

		}
	}

	cout << str << endl;

}