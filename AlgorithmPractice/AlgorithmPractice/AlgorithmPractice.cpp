#include "stdafx.h"
#include <cstdio>
#include <iostream>
using namespace std;

int main() {
	bool negative = false;
	char ch;
	int sum, next;

	// input
	scanf_s("%d", &sum);
	while (true) {
		scanf_s("%c", &ch);
		scanf_s("%d", &next);

		if (ch == '-') negative = true;
		else if (ch != '+') break;

		if (negative) sum -= next;
		else sum += next;
	}

	// output
	printf("%d", sum);

	return 0;
}