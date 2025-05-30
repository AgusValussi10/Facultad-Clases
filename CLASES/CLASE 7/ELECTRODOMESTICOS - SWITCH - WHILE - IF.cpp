#include <cstdio>

int main() {
	int averiado = 0, sinrespuesto = 0, endesuso = 0, funcionando = 0, electrodomestico = 0;
	char continuar;
	
	char nombres[50][50];  // Almacena el nombre de hasta 50 electrodomésticos, hasta 50 caracteres
	int estados[50];        // Almacena el estado de hasta 100 electrodomésticos (1 = Averiado, 2 = Sin Respuestos, 3 = En Desuso, 4 = Funcionando)
	
	printf("Analisis de inventario.\n");
	
	while (true) {
		printf("Ingrese el nombre del electrodomestico: ");
		scanf(" %s", &nombres[electrodomestico]);
		
		printf("Ingrese el estado del mismo, (1 = Averiado, 2 = Sin Respuestos, 3 = En Desuso, 4 = Funcionando): ");
		scanf("%d", &estados[electrodomestico]);
		
		if (estados[electrodomestico] == 1) {
			averiado++;
		} 
		else if (estados[electrodomestico] == 2) {
			sinrespuesto++;
		}
		if (estados[electrodomestico] == 3){
			endesuso++;
		}
		else if (estados[electrodomestico] == 4){
			funcionando++;
		}
		
		electrodomestico++; 
		
		printf("¿Desea ingresar otro electrodoméstico? (S para sí, N para no): ");
		scanf(" %c", &continuar); // Espacio antes del %c para evitar salto linea
		
		if (continuar != 'S' && continuar != 's') {
			break;
		}
	}
	
	if (electrodomestico > 0) {
		printf("\nListado de electrodomésticos:\n");
		printf("Orden - Electrodomestico - Estado\n");
		for (int i = 0; i < electrodomestico; i++) {
			printf(" %d. \t%s -\t\t ", i + 1, nombres[i]);
			switch (estados[i]) {
			case 1: 
				printf("Averiado\n");
				break;
			case 2: 
				printf("Sin Respuestos\n");
				break;
			case 3: 
				printf("En Desuso\n");
				break;
			case 4: 
				printf("Funcionando\n");
				break;
			default: 
				printf("Estado desconocido\n");
				break;
			}
		}
		printf("\nTotal de electrodomésticos: %d\n", electrodomestico);
		printf("Total Averiados: %d\n", averiado);
		printf("Total en Desuso: %d\n", endesuso);
		printf("Total Sin Respuestos: %d\n", sinrespuesto);
		printf("Total Funcionando: %d\n", funcionando);
	} 
	
	return 0;
}
