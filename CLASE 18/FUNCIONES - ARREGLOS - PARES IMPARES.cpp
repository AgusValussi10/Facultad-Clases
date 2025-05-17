// Dise�ar un programa que permita 
// a) Cargar un elemento entero de 10 elementos
// b) Hacer la carga del arreglo en la etapa de declaracion
// c) Mostrar el contenido del arreglo usando un procedimiento
// d) Indicar cuantos numeros pares tiene el arreglo. usar una funcion para determinar si el numero es par o no

#include <stdio.h> // Biblioteca est�ndar

// ---------- Prototipos de funciones ----------
void mostrarArreglo(int arr[], int tam);    // Procedimiento para mostrar el arreglo
int esPar(int numero);                      // Funci�n para saber si un n�mero es par
int contarPares(int arr[], int tam);        // Funci�n para contar los pares en el arreglo

int main() {
	
	int numeros[10] = {5, 12, 8, 23, 7, 19, 3, 14, 6, 11}; // a) y b) Arreglo cargado directamente en la declaraci�n
	
	printf("Contenido del arreglo:\n");// c) Llamamos al procedimiento para mostrar el contenido del arreglo
	mostrarArreglo(numeros, 10);
	
	int cantidadPares = contarPares(numeros, 10); // d) Llamamos a la funci�n que cuenta los pares
	printf("\nEl arreglo tiene %d numeros pares.\n", cantidadPares);
	
	return 0;
}

// ---------- Desarrollo de funciones ----------
void mostrarArreglo(int arr[], int tam) { // Procedimiento que muestra el contenido del arreglo
	for (int i = 0; i < tam; i++) {
		printf("%d ", arr[i]);
	}
	printf("\n"); // Salto de l�nea al final
}


int esPar(int numero) { // Funci�n que determina si un n�mero es par
	return numero % 2 == 0; // Devuelve 1 si es par, 0 si no lo es
}
int contarPares(int arr[], int tam) { // Funci�n que recorre el arreglo y cuenta cu�ntos n�meros pares tiene
	int contador = 0;
	for (int i = 0; i < tam; i++) {
		if (esPar(arr[i])) { // Usamos la funci�n esPar
			contador++;
		}
	}
	return contador; // Retorna la cantidad de pares
}


