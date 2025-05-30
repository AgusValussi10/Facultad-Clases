#include <stdio.h> // Librería necesaria para utilizar printf() y scanf()

int main(){
	
	int numeros[5] = {3, 7, 9, 1, 4};
	int buscando = 9;
	int encontrado = 0;
	for(int i = 0; i < 5; i++){
		if(numeros[i] == buscando){
			printf("Encontrado en la posicion %d\n", i);
			encontrado = 1;
			break;
		}
	}
	if (!encontrado){
		printf("No encontrado.\n");
	}
	return 0;
}
