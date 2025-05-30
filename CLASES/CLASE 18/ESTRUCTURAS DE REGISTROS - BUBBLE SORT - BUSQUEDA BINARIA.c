#include <stdio.h> // Inclusi�n de la biblioteca est�ndar para entrada/salida
#define ELEM 5     // Definimos una constante ELEM con valor 5 (cantidad de amigos a ingresar)

// Definici�n de la estructura que representa un amigo
struct estructura_amigo {
	char nombre[30];    // Nombre del amigo (m�x. 29 caracteres + '\0')
	char apellido[40];  // Apellido del amigo (m�x. 39 caracteres + '\0')
	char telefono[15];  // Tel�fono como cadena de caracteres
	int edad;           // Edad del amigo
	int dni;            // DNI del amigo
};

int main() {
	struct estructura_amigo amigo[ELEM]; // Arreglo de estructuras para almacenar los datos
	int i, j, b;                          // Variables auxiliares para iteraci�n y b�squeda
	int mayores = 0, menores = 0, iguales = 0; // Contadores para clasificar edades
	int edadReferencia;                  // Edad que servir� de referencia para comparaci�n
	struct estructura_amigo aux;         // Variable auxiliar para el ordenamiento
	
	// Carga de datos de los amigos
	for (i = 0; i < ELEM; i++) {
		printf("Ingrese el nombre del amigo %d: ", i + 1);
		scanf("%s", amigo[i].nombre); // Se lee una palabra (sin espacios)
		
		printf("Ingrese el apellido del amigo %d: ", i + 1);
		scanf("%s", amigo[i].apellido); // Tambi�n sin espacios
		
		printf("Ingrese el n�mero de tel�fono del amigo %d: ", i + 1);
		scanf("%s", amigo[i].telefono); // Tel�fono como cadena (permite guiones o s�mbolos)
		
		printf("Ingrese el DNI del amigo %d: ", i + 1);
		scanf("%d", &amigo[i].dni); // Lectura de n�mero entero
		
		printf("Ingrese la edad del amigo %d: ", i + 1);
		scanf("%d", &amigo[i].edad); // Lectura de n�mero entero
	}
	
	// Ordenamiento de la lista con la funci�n BUBBLE SORT
	// Ordenamiento de la lista de amigos por DNI en orden descendente (mayor a menor)
	for (i = 0; i < ELEM - 1; i++) {
		for (j = 0; j < ELEM - i - 1; j++) {
			if (amigo[j].dni < amigo[j + 1].dni) {
				// Intercambio usando variable auxiliar
				aux = amigo[j];
				amigo[j] = amigo[j + 1];
				amigo[j + 1] = aux;
			}
		}
	}
	
	// Impresi�n de la lista ordenada
	printf("\nLISTA DE AMIGOS ORDENADA POR DNI (MAYOR A MENOR):\n");
	printf("%-4s %-10s %-15s %-15s %-15s %-4s\n", "N�", "DNI", "NOMBRE", "APELLIDO", "TELEFONO", "EDAD");
	printf("-----------------------------------------------------------------------------\n");
	for (i = 0; i < ELEM; i++) {
		// Impresi�n formateada de cada amigo
		printf("%-4d %-10d %-15s %-15s %-15s %-4d\n",
			   i + 1,
			   amigo[i].dni,
			   amigo[i].nombre,
			   amigo[i].apellido,
			   amigo[i].telefono,
			   amigo[i].edad);
	}
	
	// B�squeda de un amigo por su DNI (binaria)
	printf("\nIngrese DNI para buscar: ");
	scanf("%d", &b); // Se ingresa el DNI a buscar
	
	int inicio = 0, fin = ELEM - 1, medio;
	int encontrado = 0;
	
	// B�squeda binaria de un amigo por su DNI en un arreglo ordenado en orden descendente
	while (inicio <= fin) {
		medio = (inicio + fin) / 2; // Calcula el �ndice del medio del rango actual
		
		if (amigo[medio].dni == b) {
			// Si el DNI en la posici�n media coincide con el buscado
			encontrado = 1; // Marca como encontrado
			break;          // Sale del bucle
		} else if (amigo[medio].dni < b) {
			// Como el arreglo est� en orden descendente,
			// si el valor medio es menor que el buscado,
			// el valor debe estar a la izquierda
			fin = medio - 1;
		} else {
			// Si el valor medio es mayor, buscar en la parte derecha
			inicio = medio + 1;
		}
	}
	
	// Mostrar resultado de la b�squeda
	if (encontrado) {
		// Si se encontr� el amigo con ese DNI
		printf("DNI encontrado: %d\n", amigo[medio].dni);
		printf("Nombre: %s %s | Tel�fono: %s | Edad: %d\n",
			   amigo[medio].nombre, amigo[medio].apellido, amigo[medio].telefono, amigo[medio].edad);
	} else {
		// Si no se encontr� ning�n amigo con ese DNI
		printf("No se encontr� el DNI %d\n", b);
	}
	
	// Comparaci�n con una edad de referencia
	printf("\nIngrese una edad de referencia: ");
	scanf("%d", &edadReferencia);
	
	for (i = 0; i < ELEM; i++) {
		if (amigo[i].edad > edadReferencia) {
			mayores++;
		} else if (amigo[i].edad < edadReferencia) {
			menores++;
		} else {
			iguales++;
		}
	}
	
	// Resultados de la comparaci�n por edad
	printf("\nN�mero de amigos mayores a %d a�os: %d\n", edadReferencia, mayores);
	printf("N�mero de amigos menores a %d a�os: %d\n", edadReferencia, menores);
	if (iguales > 0){
		printf("N�mero de amigos con %d a�os: %d\n", edadReferencia, iguales);
	}
	
	return 0; // Fin del programa
}
