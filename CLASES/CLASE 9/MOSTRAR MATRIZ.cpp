#include <stdio.h> // Librer�a necesaria para utilizar printf() y scanf()

int main(){
	
	int matriz[2][3] = {
		{1,2,3},
		{4,5,6}
	};
	
	for(int fila = 0; fila < 2; fila++){
		for(int col = 0; col < 3;col++){
			printf("%d", matriz[fila][col]);
		}
		printf("\n");
	}
	
	return 0;
}
