// Los padres de una ni�a le prometieron dar 10 dolares cuando cumpliera 12 a�os de edad y duplicar el regalo en cada cumplea�os subsiguiente hasta que el regalo cumpliera 1000 dolares.
// Escriba un programa para determinar que edad tendria la ni�a cuando se le de la ultima cantidad, y la cantidad total recibida.

#include <stdio.h>

int main() {
	float regalo = 10;
	int edad = 12;
	float total = 0;
	
	while (regalo <= 1000) {
		total += regalo;           // Acumular el regalo de ese a�o
		regalo *= 2;               // Duplicar el regalo para el pr�ximo a�o
		edad++;                    // Sumar un a�o
	}
	
	// Mostrar resultados
	printf("La ni�a tendr� %d a�os cuando reciba el �ltimo regalo.\n", edad);
	printf("El total recibido hasta ese momento es: %.2f d�lares.\n", total);
	
	return 0;
}
