#include "stdafx.h"
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;
vector<int> sum(1000);
int k;

int main();
int answer();

void setSum() {

	int subSum = 0;
	for (int i = 1; i < 1000; i++) {
		subSum += i;
		sum[i-1] = subSum;
	}
}

int main()
{
	int T; 
	cin >> T;

	setSum();
	for (int i = 0; i<T; i++)
	{
		cin >> k;
		cout << answer() << endl;
	}
	return 0;
}

int answer() {

	for (int i = 0; sum[i] < k; i++) {
		for (int j = 0; sum[j] < k; j++) {
			for (int h = 0; sum[h] < k; h++) {
				if (sum[i] + sum[j] + sum[h] == k) {
					return 1;
				}
			}
		}
	}
	return 0;
}