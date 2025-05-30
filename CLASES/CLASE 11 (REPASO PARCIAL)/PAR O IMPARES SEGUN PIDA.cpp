// Realizar un programa que pida al usuario dos numeros y una letra "I", "P" o "T", el programa presentara los numeros pares si se pulsa la letra P o los impares si se usa I.
// Desde los numeros que se introdujo primero hasta el segundo, si se utiliza otra letra el programa no muestra ningun numero.

#include <cstdio>
#include <stdio.h>

int main() {
	
	int limiteinf, limitesup;
	char parimpar;
	
	printf("Ingrese un numero, el mismo fucionara como LIMITE INFERIOR: ");
	scanf("%d", &limiteinf);
	if (limiteinf < 0){
		do{
			printf("Ingrese un numero mayor a 0: ");
			scanf("%d", &limiteinf);
		}while (limiteinf <= 0);
	}
	printf("Ingrese un numero, el mismo fucionara como LIMITE SUPERIOR: ");
	scanf("%d", &limitesup);
	if (limiteinf >= limitesup){
		do{
			printf("Ingrese un numero mayor a %d: ", limiteinf);
			scanf("%d", &limitesup);
		}while (limitesup < limiteinf);
	}
	printf("\nIngrese la letra I para mostrar los numeros IMPARES\n");
	printf("Ingrese la letra P para mostrar los numeros PARES\n");
	printf("Ingrese la letra T para mostrar todos los numeros\n");
	printf("Opcion: ");
	scanf(" %c", &parimpar);
	printf("\n");
	
	for (int i = limiteinf ; i <= limitesup ; i++){
		
		if (parimpar == 'i' || parimpar == 'I'){
			if (i % 2 != 0){
				printf("Numero Impar: %d\n", i);
			}
		}
		if (parimpar == 'p' || parimpar == 'P'){
			if (i % 2 == 0){
				printf("Numero Par: %d\n", i);
			}
		}
		if (parimpar == 't' || parimpar == 'T'){
				printf("Numero: %d\n", i);
		}
		else {
			printf("Opción inválida.\n");
			break;
		}
	}
	
	return 0;
}

