#include <cstdio>  // Para funciones de entrada/salida como printf y scanf

int main() {
	int arreglo[10];        // Arreglo donde se guardarán los 10 números ingresados
	int matriz[3][3];       // Matriz 3x3 para almacenar los primeros 9 números del arreglo
	
	int i = 0;
	int errores_totales = 0;        // Contador de errores totales al ingresar números
	int errores_consecutivos = 0;   // Contador de errores consecutivos
	
	// Solicita al usuario ingresar 10 números válidos entre 1 y 100
	printf("Ingrese 10 numeros entre 1 y 100:\n");
	while (i < 10) {
		int num;
		printf("Elemento %d: ", i + 1);
		scanf("%d", &num);
		
		// Si el número está dentro del rango válido, se guarda
		if (num >= 1 && num <= 10) {
			arreglo[i] = num;
			i++;
			errores_consecutivos = 0;  // Reinicia errores consecutivos
		} else {
			errores_totales++;        // Aumenta el total de errores
			errores_consecutivos++;   // Aumenta el contador de errores seguidos
			
			// Si se ingresan 3 errores consecutivos, el cuarto valor será 1 automático
			if (errores_consecutivos >= 4) {
				printf("Se han ingresado 3 valores incorrectos consecutivos. Asignando 1 automáticamente.\n");
				arreglo[i] = 1;
				i++;
				errores_consecutivos = 0;  // Reinicia errores consecutivos
			} else {
				printf("Numero fuera de rango. Intente de nuevo.\n");
			}
		}
	}
	
	// Muestra el contenido del arreglo, un número por línea
	printf("\nArreglo cargado:\n");
	for (int j = 0; j < 10; ++j) {
		printf("%d\n", arreglo[j]);
	}
	
	// Muestra la cantidad total de errores cometidos al ingresar números
	printf("Cantidad total de ingresos incorrectos: %d\n", errores_totales);
	
	// Llena la matriz 3x3 con los primeros 9 valores del arreglo
	int k = 0;
	for (int i = 0; i < 3; ++i) {
		for (int j = 0; j < 3; ++j) {
			matriz[i][j] = arreglo[k];
			k++;
		}
	}
	
	// Crea una cadena de caracteres con letras que representan los números del arreglo
	char cadena[11];  // 9 caracteres visibles + '\0' para el fin de cadena
	for (int j = 0; j < 10; ++j) {
		switch (arreglo[j]) {
		case 1: cadena[j] = 'A'; break;  // 1 se convierte en A
		case 2: cadena[j] = 'E'; break;  // 2 en E
		case 3: cadena[j] = 'I'; break;  // 3 en I
		case 4: cadena[j] = 'O'; break;  // 4 en O
		case 5: cadena[j] = 'U'; break;  // 5 en U
		default: cadena[j] = '_'; break; // Otros números se representan con guión bajo
		}
	}
	cadena[10] = '\0';  // Fin de cadena
	
	// Muestra la cadena generada
	printf("\nCadena generada a partir del arreglo:\n%s\n", cadena);
	
	// Contadores de vocales
	int total_vocales = 0;
	int cont_A = 0, cont_E = 0, cont_I = 0, cont_O = 0, cont_U = 0;
	
	// Recorre la cadena y cuenta las vocales
	for (int i = 0; i < 10; ++i) {
		switch (cadena[i]) {
		case 'A': cont_A++; total_vocales++; break;
		case 'E': cont_E++; total_vocales++; break;
		case 'I': cont_I++; total_vocales++; break;
		case 'O': cont_O++; total_vocales++; break;
		case 'U': cont_U++; total_vocales++; break;
		}
	}
	
	// Si hay vocales, se muestran las cantidades
	if (total_vocales > 0) {
		printf("\nCantidad total de vocales en la cadena: %d\n", total_vocales);
		printf("Cantidad de A: %d\n", cont_A);
		printf("Cantidad de E: %d\n", cont_E);
		printf("Cantidad de I: %d\n", cont_I);
		printf("Cantidad de O: %d\n", cont_O);
		printf("Cantidad de U: %d\n", cont_U);
	} else {
		// Si no hay ninguna vocal válida, se informa que la cadena está vacía
		printf("\nLa cadena está vacía (sin vocales válidas).\n");
	}
	
	return 0;  // Fin del programa
}
