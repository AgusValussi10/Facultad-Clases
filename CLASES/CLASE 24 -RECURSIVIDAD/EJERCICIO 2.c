/* 
    Escriba una definición recursiva de una función que tiene un parámetro n de tipo entero y que 
    devuelve el n-ésimo número de Fibonacci. Los números de Fibonacci se definen de la siguiente 
    manera: 
    F0 = 1 
    F1 = 1 
    Fi+2 = Fi + Fi+1 
*/

#include <stdio.h>  // Librería estándar para entrada y salida (printf, scanf)

// Función recursiva que calcula el n-ésimo número de Fibonacci
int fibonacci(int n) {
	// Caso base 1: el término 0 de la serie es 0
	if (n == 0)
		return 0;
	// Caso base 2: el término 1 de la serie es 1
	else if (n == 1)
		return 1;
	// Paso recursivo: se suman los dos términos anteriores
	else
		return fibonacci(n - 1) + fibonacci(n - 2);
}

int main() {
	int n;  // Variable para almacenar el número ingresado por el usuario
	
	// Solicita al usuario el valor de n
	printf("Ingresa el valor de n: ");
	scanf("%d", &n);  // Lee el valor ingresado
	
	// Llama a la función recursiva y guarda el resultado
	int resultado = fibonacci(n);
	
	// Muestra el resultado
	printf("El %d-ésimo número de Fibonacci es: %d\n", n, resultado);
	
	return 0;  // Fin del programa
}
