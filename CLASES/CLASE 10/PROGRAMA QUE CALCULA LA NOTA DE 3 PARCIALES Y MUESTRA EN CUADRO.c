#include <cstdio>
#include <stdio.h>
int main() {
	
	float nota1, nota2, nota3, notafinal;
	char seguir;
	
	do{
		printf("Este es un programa que calcula la nota final de los 3 parciales y da la nota final del alumno\n");
		printf("Ingrese la primer nota: ");
		scanf("%f", &nota1);
		if (nota1 < 0 || nota1 > 10){
			printf("Error, numero ingresado incorrecto");
			return 0;
		}
		printf("Ingrese la segunda nota: ");
		scanf("%f", &nota2);
		if (nota2 < 0 || nota2 > 10){
			printf("Error, numero ingresado incorrecto");
			return 0;
		}
		printf("Ingrese la tercer nota: ");
		scanf("%f", &nota3);
		if (nota3 < 0 || nota3 > 10){
			printf("Error, numero ingresado incorrecto");
			return 0;
		}
		printf("\n");
		printf("\t\t*********************************\n");
		printf("\t\t* Programa que calcula la nota\t*\n");
		printf("\t\t* Notas Ingresadas\t\t*\n");
		printf("\t\t* \t%.2f\t\t\t*\n", nota1);
		printf("\t\t* \t\t%.2f\t\t*\n", nota2);
		printf("\t\t* \t\t\t%.2f\t*\n", nota3);
		printf("\t\t* ----------------------------- *\n");
		printf("\t\t* Calculo de la nota\t\t*");
		// CALCULAR PONDERACION DE LAS NOTAS
		nota1 = nota1 * 0.25;
		nota2 = nota2 * 0.30;
		nota3 = nota3 * 0.45;
		printf("\n\t\t* 1° Nota = %.2f\t\t*", nota1);
		printf("\n\t\t* 2° Nota = %.2f\t\t*", nota2);
		printf("\n\t\t* 3° Nota = %.2f\t\t*", nota3);
		// CALCULAR LA NOTA FINAL
		notafinal = (nota1 + nota2 + nota3);
		printf("\n\t\t* Nota Final: %.2f\t\t*\n", notafinal);
		printf("\t\t* ----------------------------- *\n");
		// INDICAR APROBADO O DESAPROBADO DE LA MATERIA
		if (notafinal >= 6){
			printf("\t\t* Materia Aprobada\t\t*");
		}
		else{
			printf("\t\t* Materia Desaprobada\t\t*");
		}
		printf("\n\t\t*********************************\n");
		
		printf("\nDesea ingresar otra nota? (S/N)\n");
		printf("Opcion: ");
		scanf(" %c", &seguir);
		
	} while (seguir == 'S' || seguir == 's');
	
	return 0;
}

