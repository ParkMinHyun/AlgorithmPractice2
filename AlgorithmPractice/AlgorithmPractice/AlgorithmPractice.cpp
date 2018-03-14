#include "stdafx.h"
#include <stdio.h>
#include <stdlib.h>

#pragma warning(disable: 4996)

int main() {

	int N, B, C;
	long long sum = 0;
	scanf("%d", &N);

	int *room = (int*)malloc(sizeof(int)*N + 1);

	for (int i = 0; i < N; i++) {
		scanf("%d", &room[i]);
	}

	scanf("%d %d", &B, &C);

	for (int i = 0; i < N; i++) {
		room[i] -= B;
		sum++;

		if (room[i] > 0) {
			if (room[i] % C == 0)
				sum += room[i] / C;
			else
				sum += room[i] / C + 1;
		}
	}
	printf("%d\n", sum);
}