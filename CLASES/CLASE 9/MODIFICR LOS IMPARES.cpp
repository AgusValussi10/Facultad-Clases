#include <stdio.h> // Librería necesaria para utilizar printf() y scanf()

int main(){
	
	int numeros[] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14, 15, 16, 17, 18, 98};
	
	printf("Arreglo Original:\n");
	for (int i = 0; i < 19; i++){
		printf("Numeros[%d] = %d\n", i, numeros[i]);
	}
	
	printf("\n");
	
	printf("Arreglo Modificado:\n");
	for(int i = 0; i < 19; i++){
		if (numeros[i] % 2 != 0) {
			printf("Impares[%i] = %d\n", i, numeros[i] * 2);
		}
	}
	
	return 0;
}
