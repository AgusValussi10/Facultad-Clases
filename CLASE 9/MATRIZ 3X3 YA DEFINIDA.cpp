#include <iostream>
#include <cstdio>
#define SIZE 3

int main() {
	// Matrices predefinidas
	int matriz1[SIZE][SIZE] = {{1, 2, 3}, {4, 5, 6}, {7, 8, 9}};
	int matriz2[SIZE][SIZE] = {{9, 8, 7}, {6, 5, 4}, {3, 2, 1}};
	int resultado[SIZE][SIZE] = {0};
	
	// Mostrar matrices
	printf("Matriz 1:\n");
	for (int fa = 0; fa < SIZE; ++fa) {
		printf("| ");
		for (int ca = 0; ca < SIZE; ++ca) {
			printf("%4d ", matriz1[fa][ca]);
		}
		printf("|\n");
	}
	
	printf("\nMatriz 2:\n");
	for (int fa = 0; fa < SIZE; ++fa) {
		printf("| ");
		for (int ca = 0; ca < SIZE; ++ca) {
			printf("%4d ", matriz2[fa][ca]);
		}
		printf("|\n");
	}
	
	// Multiplicación de matrices
	for (int fa = 0; fa < SIZE; ++fa) {
		for (int ca = 0; ca < SIZE; ++ca) {
			for (int acum = 0; acum < SIZE; ++acum) {
				resultado[fa][ca] += matriz1[fa][acum] * matriz2[acum][ca];
			}
		}
	}
	
	// Mostrar resultado
	printf("\nResultado (Matriz1 x Matriz2):\n");
	for (int fa = 0; fa < SIZE; ++fa) {
		printf("| ");
		for (int ca = 0; ca < SIZE; ++ca) {
			printf("%4d ", resultado[fa][ca]);
		}
		printf("|\n");
	}
	
	return 0;
}
