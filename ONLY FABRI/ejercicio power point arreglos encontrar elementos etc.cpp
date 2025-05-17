#include <stdio.h>

int main() {
	// Definición e inicialización del arreglo
	int arreglo[10] = {5, 8, 12, 3, 9, 7, 1, 4, 6, 10};
	int suma = 0;
	float promedio;
	int i;
	
	// Mostrar elementos del arreglo
	printf("Elementos del arreglo:\n");
	for (i = 0; i < 10; i++) {
		printf("%d", arreglo[i]);
		if (i < 9) {
			printf("--");
		}
		suma += arreglo[i];
	}
	
	// Calcular promedio
	promedio = suma / 10.0;
	
	// Mostrar suma y promedio
	printf("\n\nSuma de los elementos: %d\n", suma);
	printf("Promedio de los elementos: %.2f\n", promedio);
	
	// Mostrar elementos mayores a la mitad del promedio
	printf("\nElementos mayores a la mitad del promedio (%.2f):\n", promedio / 2);
	for (i = 0; i < 10; i++) {
		if (arreglo[i] > promedio / 2) {
			printf("%d ", arreglo[i]);
		}
	}
	
	// Ingresar posición por teclado y mostrar el elemento
	int posicion;
	printf("\n\nIngrese una posicion (0-9): ");
	scanf("%d", &posicion);
	
	if (posicion >= 0 && posicion < 10) {
		printf("Elemento en la posicion %d: %d\n", posicion, arreglo[posicion]);
	} else {
		printf("Posicion invalida. Debe estar entre 0 y 9.\n");
	}
	
	// Ingresar un valor y verificar si está en el arreglo
	int valor, encontrado = 0;
	printf("Ingrese un valor a buscar en el arreglo: ");
	scanf("%d", &valor);
	
	for (i = 0; i < 10; i++) {
		if (arreglo[i] == valor) {
			encontrado = 1;
			break;
		}
	}
	
	if (encontrado==1) {
		printf("El valor %d SI se encuentra en el arreglo.\n", valor);
	} else {
		printf("El valor %d NO se encuentra en el arreglo.\n", valor);
	}
	
	return 0;
}
