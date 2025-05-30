#include <stdio.h>

int main() {
	int arreglo[10];
	int matriz[3][3];
	
	// Solicitar al usuario los 10 elementos del arreglo
	printf("Ingrese 10 numeros:\n");
	for (int i = 0; i < 10; ++i) {
		printf("Elemento %d: ", i + 1);
		scanf("%d", &arreglo[i]);
	}
	
	// Llenar la matriz 3x3 con los primeros 9 elementos
	int k = 0;
	for (int i = 0; i < 3; ++i) {
		for (int j = 0; j < 3; ++j) {
			matriz[i][j] = arreglo[k];
			k++;
		}
	}
	
	// Mostrar la matriz
	printf("\nMatriz 3x3:\n");
	for (int i = 0; i < 3; ++i) {
		for (int j = 0; j < 3; ++j) {
			printf("%d ", matriz[i][j]);
		}
		printf("\n");
	}
	
	// Mostrar el elemento no usado
	printf("Elemento no usado: %d\n", arreglo[9]);
	
	return 0;
}
