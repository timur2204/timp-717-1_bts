#include <stdio.h>

int main() {
	int n, res = 0, count_l = 0, count_r = 0;
	char x = 0;
	scanf("%d", &n);
	int i;
	for (i = 0; i < 2 * n; i++) {
		x = getchar();
		if (x == '(') {
			if (i == 1) {
				res = 1;
			}
			count_l++;
		}
		else if (x == ')') {
			count_r++;
		}
	}
	if (res == 1) {
		if (count_l == count_r) {
			printf("%d", 1);
		}
		else {
			printf("%d", 0);
		}
	}
	else {
		printf("%d", 0);
	}
}
