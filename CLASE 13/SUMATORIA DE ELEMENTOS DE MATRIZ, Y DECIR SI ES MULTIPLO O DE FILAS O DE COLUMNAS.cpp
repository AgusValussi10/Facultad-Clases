#include <stdio.h>

int main() {
	int i, j, k = 0, temp;
	
	// Matriz original de 5x2
	int matriz[5][2] = {{0,0}, {1,2}, {2,4}, {3,6}, {4,8}};
	int filas = 5;
	int columnas = 2;
	
	// Calcular la sumatoria
	int suma = 0;
	for (i = 0; i < filas; i++) {
		for (j = 0; j < columnas; j++) {
			suma += matriz[i][j];
		}
	}
	
	printf("Sumatoria de los elementos de la matriz: %d\n", suma);
	
	// Verificar múltiplos
	if (suma % filas == 0) {
		printf("La suma ES múltiplo de la cantidad de FILAS (%d).\n", filas);
	} else {
		printf("La suma NO es múltiplo de la cantidad de FILAS (%d).\n", filas);
	}
	
	if (suma % columnas == 0) {
		printf("La suma ES múltiplo de la cantidad de COLUMNAS (%d).\n", columnas);
	} else {
		printf("La suma NO es múltiplo de la cantidad de COLUMNAS (%d).\n", columnas);
	}
	
	return 0;
}
