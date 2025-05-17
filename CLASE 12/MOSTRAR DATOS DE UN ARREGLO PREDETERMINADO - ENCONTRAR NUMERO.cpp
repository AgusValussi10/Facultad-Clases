// Cargar un elemento de tipo entero de 10 elementos en etapa de definicion. Mostrar el contenido del arreglo usando la sentencia FOR. 
// Los eelementos se deben mostrar uno al lado del otro separados por dos guiones medio.
// Al programa anterior agregar la suma de sus elementos. Mostrar el resultado. Calcular el promedio.
// Mostrar los elementos que son mayores a la mitad del promedio.
// Ingresar una posicion por teclado e indicar que elemento se encuentra en dicha posicion.
// Ingresar un valor por teclado e indiciar si es un elemento que pertenece al arreglo.

#include <cstdio>

int main() {
	// Definición y carga del arreglo con 10 enteros
	int arreglo[10] = {5, 8, 12, 3, 9, 15, 4, 7, 1, 10};
	int suma = 0;
	
	// Mostrar el contenido del arreglo y calcular la suma
	printf("Arreglo: ");
	for (int i = 0; i < 10; i++) {
		printf("%d", arreglo[i]);
		if (i < 9) {
			printf("--"); // Separador entre elementos
		}
		suma += arreglo[i];
	}
	
	// Calcular suma y promedio
	float promedio = suma / 10.0f;
	float mitad_promedio = promedio / 2.0f;
	
	printf("\nSuma: %d\n", suma);
	printf("Promedio: %.2f\n", promedio);
	printf("Mitad del promedio: %.2f\n", mitad_promedio);
	
	// Mostrar los elementos mayores a la mitad del promedio
	printf("Elementos > mitad del promedio: ");
	for (int i = 0; i < 10; i++) {
		if (arreglo[i] > mitad_promedio) {
			printf("%d--", arreglo[i]);
		}
	}
	printf("\n\n");
	
	// 1) Ingresar posición y mostrar elemento
	int pos;
	printf("Ingrese una posición (0 a 9): ");
	if (scanf("%d", &pos) != 1) {
		printf("Entrada inválida.\n");
		return 1;
	}
	if (pos >= 0 && pos < 10) {
		printf("En la posición %d se encuentra el elemento: %d\n\n", pos, arreglo[pos]);
	} else {
		printf("Posición fuera de rango.\n\n");
	}
	
	// 2) Ingresar un valor y verificar si pertenece al arreglo
	int valor, encontrado = 0;
	printf("Ingrese un valor a buscar en el arreglo: ");
	if (scanf("%d", &valor) != 1) {
		printf("Entrada inválida.\n");
		return 1;
	}
	
	for (int i = 0; i < 10; i++) {
		if (arreglo[i] == valor) {
			encontrado = true;
			break;
		}
	}
	
	if (encontrado == 1) {
		printf("El valor %d SI pertenece al arreglo.\n", valor);
	} else {
		printf("El valor %d NO pertenece al arreglo.\n", valor);
	}
	
	return 0;
}
