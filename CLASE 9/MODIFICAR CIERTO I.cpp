#include <stdio.h> // Librería necesaria para utilizar printf() y scanf()

int main(){
	
	int numeros[] = {10, 20, 30, 40, 50};
	int size = sizeof(numeros) / sizeof(numeros[0]);
	
	printf("Arreglo Original:\n");
	for (int i = 0; i < size; i++){
		printf("numeros[%d] = %d\n", i, numeros[i]);
	}
	
	for(int i = 0; i < size; i++){
		if (i == 2){
			numeros[i] = 100;
		}
	}
	
	printf("\nArreglo modificado:\n");
	for (int i = 0; i < size; i++){
		printf("numeros[%d] = %d\n", i, numeros[i]);
	}
	
	return 0;
}
