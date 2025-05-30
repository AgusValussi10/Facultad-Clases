// Dada una matriz cuadrada de numeros enteros de 4x4 se pide:
// A) Cargar la matriz. Mostrar el resultado en forma de matriz (la matriz se carga usando sentencia repetitiva). 
// Las dimensiones se deben especificar con DEFINE.
// B) Cargar los numeros divisibles por 4 de la matriz en un arreglo, mostrar el arreglo por pantalla. 
// Usar una funcion para determinar si un numero es divisible por 4
// C) Indicar cuantos numeros se cargaron en el arreglo.
// D) Ordenar el arreglo de menor a mayor, mostrar por pantalla el arreglo ordenado, usar un procedimiento para ordenar.
// E) A partir del arreglo, crear una cadena formada por vocales, si el numero es 1, 
// corresponde la vocal A, el numero 4 la vocal E, el numero 8 vocal I, el numero 12 vocal 0 y el numero 16 vocal U.
// F) Usar una funcion de string para determinar la longitud de la cadena.
// G) En caso de que la cadena tenga elementos mostrar por pantalla y verificar si es un palindromo. Usar procedimiento.

#include <stdio.h>
#include <string.h>

#define DIM 4
#define TAM (DIM * DIM)

// A) Cargar matriz
void cargarMatriz(int matriz[DIM][DIM]) {
	for (int i = 0; i < DIM; i++)
		for (int j = 0; j < DIM; j++) {
		printf("Ingrese el elemento [%d][%d]: ", i, j);
		scanf("%d", &matriz[i][j]);
	}
}

// Mostrar matriz
void mostrarMatriz(int matriz[DIM][DIM]) {
	printf("Matriz cargada:\n");
	for (int i = 0; i < DIM; i++) {
		for (int j = 0; j < DIM; j++)
			printf("%d\t", matriz[i][j]);
		printf("\n");
	}
}

// B) ¿Es divisible por 4?
int esDivisiblePor4(int numero) {
	return numero % 4 == 0;
}

// B1) Cargar arreglo con divisibles
void cargarDivisibles(int matriz[DIM][DIM], int arreglo[], int *index) {
	for (int i = 0; i < DIM; i++)
		for (int j = 0; j < DIM; j++)
			if (esDivisiblePor4(matriz[i][j]))
				arreglo[(*index)++] = matriz[i][j];
}

// C) Contar números válidos
int contarDivisibles(int arreglo[], int size) {
	int count = 0;
	for (int i = 0; i < size; i++)
		if (arreglo[i] != 0)
			count++;
	return count;
}

// D) Ordenar de menor a mayor
void ordenarArreglo(int arreglo[], int size) {
	for (int i = 0; i < size - 1; i++)
		for (int j = 0; j < size - i - 1; j++)
			if (arreglo[j] > arreglo[j + 1]) {
		int temp = arreglo[j];
		arreglo[j] = arreglo[j + 1];
		arreglo[j + 1] = temp;
	}
}

// E) Crear cadena de vocales
void crearCadenaVocales(int arreglo[], int size, char cadena[]) {
	int index = 0;
	for (int i = 0; i < size; i++) {
		switch (arreglo[i]) {
		case 1: cadena[index++] = 'A'; break;
		case 4: cadena[index++] = 'E'; break;
		case 8: cadena[index++] = 'I'; break;
		case 12: cadena[index++] = 'O'; break;
		case 16: cadena[index++] = 'U'; break;
		}
	}
	cadena[index] = '\0';
}

// F) Longitud de cadena
int longitudCadena(char cadena[]) {
	return strlen(cadena);
}

// G) ¿Es palíndromo?
int esPalindromo(char cadena[]) {
	int len = strlen(cadena);
	for (int i = 0; i < len / 2; i++)
		if (cadena[i] != cadena[len - 1 - i])
			return 0;
	return 1;
}

// ----------- MAIN -------------------

int main() {
	int matriz[DIM][DIM];
	int arreglo[TAM] = {0};
	char cadena[TAM];
	int index = 0;
	
	cargarMatriz(matriz); // A
	mostrarMatriz(matriz); // A1
	
	cargarDivisibles(matriz, arreglo, &index); // B
	
	printf("Numeros divisibles por 4:\n");
	for (int i = 0; i < index; i++)
		printf("%d ", arreglo[i]);
	printf("\n");
	
	int count = contarDivisibles(arreglo, index);
	printf("Cantidad de numeros divisibles por 4: %d\n", count);
	
	ordenarArreglo(arreglo, index);
	
	printf("Arreglo ordenado:\n");
	for (int i = 0; i < index; i++)
		printf("%d ", arreglo[i]);
	printf("\n");
	
	crearCadenaVocales(arreglo, index, cadena);
	
	int longitud = longitudCadena(cadena);
	
	if (longitud > 0) {
		printf("Cadena de vocales: %s\n", cadena);
		if (esPalindromo(cadena))
			printf("La cadena es un palindromo.\n");
		else
			printf("La cadena NO es un palindromo.\n");
	}
	
	return 0;
}

/*
============================================================
📘 RESUMEN IMPORTANTE PARA ESTUDIO DE ESTE CÓDIGO
============================================================

✔ MATRICES:
- Se trabaja con una matriz cuadrada definida con #define.
- Se recorre con dos bucles for anidados para cargar y mostrar.

✔ FUNCIONES:
- Cada parte del problema se resuelve con funciones separadas para mayor claridad y reutilización.
- Las funciones se enfocan en una sola tarea: cargar, mostrar, verificar, contar, ordenar, transformar, etc.

✔ DIVISIBILIDAD:
- Se usa una función `esDivisiblePor4()` para mantener lógica limpia y reutilizable.

✔ ARREGLO AUXILIAR:
- Se guarda sólo lo necesario (números divisibles por 4).
- Se usa un índice (`index`) pasado por referencia para seguir la posición de inserción.

✔ ORDENAMIENTO:
- Se implementa Bubble Sort, sencillo y adecuado para arreglos pequeños.

✔ TRANSFORMACIÓN A CADENA:
- Ciertos números se transforman en vocales usando un switch.
- Se genera una cadena de caracteres terminada en '\0'.

✔ PALÍNDROMO:
- Se compara cada letra desde ambos extremos de la cadena.
- Si coinciden todas, la cadena es un palíndromo.

✔ STRINGS:
- Uso de funciones de `<string.h>`, como `strlen()`, para manejar cadenas.

✔ BUENAS PRÁCTICAS:
- Uso de constantes con `#define`.
- Separación de lógica en funciones.
- Comentarios claros y estructura ordenada. */