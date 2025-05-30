#include <stdio.h>
int main() {
	int i, j, k = 0;
	
	// Matriz original 
	int matriz[5][2] = {{0,0}, {1,2}, {2,4}, {3,6}, {4,8}};
	
	// Arreglo de 10 posiciones
	int arreglo[10];
	
	// Copiar los elementos de la matriz al arreglo
	for (i = 0; i < 5; i++) {
		for (j = 0; j < 2; j++) {
			arreglo[k] = matriz[i][j];
			k++;
		}
	}
	
	printf("Matriz original:\n");
	for (i = 0; i < 5; i++) {
		for (j = 0; j < 2; j++) {
			printf("%d\t", matriz[i][j]);
		}
		printf("\n");
	}
	
	// Imprimir el arreglo resultante
	printf("\nArreglo con los datos de la matriz:\n");
	for (i = 0; i < 10; i++) {
		printf("%d ", arreglo[i]);
	}
	printf("\n");
	
	return 0;
}
