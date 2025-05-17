#include <stdio.h> // Librería necesaria para utilizar printf() y scanf()

int main(){
	
	int A[10], B[10], C[10]; // Arreglos para almacenar los valores
	int a, b, c;
	
	// Entrada de valores para el arreglo A
	for(a = 0; a < 10; a++){
		printf("Ingrese un valor entero para A[%d]: ", a);
		scanf("%d", &A[a]);
	}
	
	printf("\n");
	
	// Entrada de valores para el arreglo B
	for(b = 0; b < 10; b++){
		printf("Ingrese un valor entero para B[%d]: ", b);
		scanf("%d", &B[b]);
	}
	
	// Sumar los valores correspondientes de A y B y almacenar en C
	for(c = 0; c < 10; c++){
		C[c] = A[c] + B[c]; // Sumar los elementos de A y B
	}
	
	// Mostrar los valores de A, B y C como una matriz con tabulaciones
	printf("\nMatriz de los valores de A, B y C (suma):\n");
	for(c = 0; c < 10; c++){
		printf("A[%d] = %d\tB[%d] = %d\tC[%d] = %d\n", c, A[c], c, B[c], c, C[c]);  
		// Imprime los valores de A, B y C con el índice correspondiente, separados por tabulaciones
	}
	
	return 0;
}
