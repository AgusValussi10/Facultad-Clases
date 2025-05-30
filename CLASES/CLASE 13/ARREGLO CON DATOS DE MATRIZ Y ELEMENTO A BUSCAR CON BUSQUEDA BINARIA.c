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
	// Eliminar elementos repetidos
	int unicos[10];  // Arreglo temporal para únicos
	int n_unicos = 0;
	
	unicos[0] = arreglo[0];  // El primer elemento siempre es único
	n_unicos = 1;
	
	for (i = 1; i < 10; i++) {
		if (arreglo[i] != arreglo[i - 1]) {
			unicos[n_unicos] = arreglo[i];
			n_unicos++;
		}
	}
	
	// Imprimir el arreglo sin duplicados
	printf("\nArreglo sin elementos repetidos:\n");
	for (i = 0; i < n_unicos; i++) {
		printf("%d ", unicos[i]);
	}
	printf("\n");
	
	int buscado;
	printf("\nIngrese el número a buscar: ");
	scanf("%d", &buscado);
	
	// Búsqueda binaria
	int inicio = 0, fin = n_unicos - 1, medio;
	int encontrado = 0;
	
	while (inicio <= fin) {
		medio = (inicio + fin) / 2;
		if (unicos[medio] == buscado) {
			encontrado = 1;
			break;
		} else if (unicos[medio] < buscado) {
			inicio = medio + 1;
		} else {
			fin = medio - 1;
		}
	}
	
	// Mostrar resultado
	if (encontrado) {
		printf("Elemento %d encontrado en la posición %d del arreglo sin repetidos.\n", buscado, medio);
	} else {
		printf("Elemento %d no encontrado en el arreglo.\n", buscado);
	}
	
	return 0;
}
