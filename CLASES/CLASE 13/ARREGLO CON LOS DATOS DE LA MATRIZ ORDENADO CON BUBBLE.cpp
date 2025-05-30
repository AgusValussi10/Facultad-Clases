#include <stdio.h>

int main() {
	int i, j, k = 0, temp;
	
	// Matriz original de 5x2
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
	
	// Ordenar el arreglo con Bubble Sort
	for (i = 0; i < 10 - 1; i++) {
		for (j = 0; j < 10 - i - 1; j++) {
			if (arreglo[j] > arreglo[j + 1]) {
				// Intercambiar
				temp = arreglo[j];
				arreglo[j] = arreglo[j + 1];
				arreglo[j + 1] = temp;
			}
		}
	}
	
	// Imprimir el arreglo ordenado
	printf("\nArreglo ordenado:\n");
	for (i = 0; i < 10; i++) {
		printf("%d ", arreglo[i]);
	}
	printf("\n");
	
	return 0;
}
