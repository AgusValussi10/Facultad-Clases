#include <stdio.h>

int main() {
	int i, j;
	int matriz[5][2] = {{0,0}, {1,2}, {2,4}, {3,6}, {4,8}};
	
	for (j = 0; j < 2; j++) {
		for (i = 0; i < 5; i++) {
			printf("%d\t", matriz[i][j]);
		}
		printf("\n");
	}
	
	return 0;
}
