#include <cstdio>  // Para printf

int main() {
	int arreglo[10] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
	int matriz[3][3];
	
	int k = 0;
	
	// Llenar la matriz con los primeros 9 elementos
	for (int i = 0; i < 3; ++i) {
		for (int j = 0; j < 3; ++j) {
			matriz[i][j] = arreglo[k];
			k++;
		}
	}
	
	// Imprimir la matriz
	printf("Matriz 3x3:\n");
	for (int i = 0; i < 3; ++i) {
		for (int j = 0; j < 3; ++j) {
			printf("%d ", matriz[i][j]);
		}
		printf("\n");
	}
	
	// Imprimir el elemento no usado
	printf("Elemento no usado: %d\n", arreglo[9]);
	
	// Mostrar la diagonal principal (i == j)
	printf("Elementos de la diagonal principal: ");
	for (int i = 0; i < 3; ++i) {
		printf("%d ", matriz[i][i]);
	}
	printf("\n");
	
	return 0;
}
