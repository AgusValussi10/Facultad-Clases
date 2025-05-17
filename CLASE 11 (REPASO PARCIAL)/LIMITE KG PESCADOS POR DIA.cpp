// Suponga que el gobierno impone a los pescadores un limite a los kilos de pesca que puede recojer en un dia.
// Desarrolle un programa al que se le vayan dando los pesos de lo que va pescando y muestre el total de KG hasta ese momento.
// Cuando supere el maximo se debe dar la alarma y terminar el programa.
// Tambien debe terminar el programa si se intrudce un 0 como KG ingresados.
// Usar sentencia WHILE. 

#include <cstdio>
#include <stdio.h>
int main() {
	
	float limitediario;
	printf("LIMITE DIARIO = ");
	scanf("%f", &limitediario);
	printf("*********************************************************\n");
	printf("*\tEL LIMITE DIARIO DEL DIA DE HOY SON %.0f KG\t*", limitediario);
	printf("\n*********************************************************\n");
	
	float totalpescado = 0, pescado;
	while (totalpescado <= limitediario){
		printf("Ingrese los KG pescados: ");
		scanf("%f", &pescado);
		if (pescado <= 0){
			printf("NUMERO INCORRECTO");
			return 0;
		}
		totalpescado = pescado + totalpescado;
		
		if (totalpescado > limitediario){
			printf("ALERTA - LIMITE DIARIO SUPERADO\n");
			float exceso = totalpescado - limitediario;
			printf("Usted se excedió del límite por %.2f KG\n", exceso);
			return 0;
				
	}
	
	return 0;
}
