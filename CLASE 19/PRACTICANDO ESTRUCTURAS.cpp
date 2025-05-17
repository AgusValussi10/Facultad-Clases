#include <stdio.h>
#define ELEM 2  // Cantidad de estudiantes

// Estructura para representar un estudiante
struct Estudiante {
	char nombre[30];
	int edad;
	float promedio; // Nota del estudiante
};

int main() {
	struct Estudiante estudiantes[ELEM];
	int i, j;
	float refPromedio;
	int mayores = 0, menores = 0, iguales = 0;
	struct Estudiante aux;
	
	// Ingreso de datos
	for (i = 0; i < ELEM; i++) {
		printf("Ingrese el nombre del estudiante %d: ", i + 1);
		scanf("%s", estudiantes[i].nombre);
		
		printf("Ingrese la edad del estudiante %d: ", i + 1);
		scanf("%d", &estudiantes[i].edad);
		
		printf("Ingrese el promedio del estudiante %d: ", i + 1);
		scanf("%f", &estudiantes[i].promedio);
	}
	
	// Mostrar la lista ordenada
	printf("\nLISTA DE ESTUDIANTES ORDENADA POR PROMEDIO (MAYOR A MENOR):\n");
	printf("%-4s %-15s %-6s %-8s\n", "N°", "Nombre", "Edad", "Promedio");
	printf("--------------------------------------------\n");
	for (i = 0; i < ELEM; i++) {
		printf("%-4d %-15s %-6d %-8.2f\n",
			   i + 1,
			   estudiantes[i].nombre,
			   estudiantes[i].edad,
			   estudiantes[i].promedio);
	}

	return 0;
}
