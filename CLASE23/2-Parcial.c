/*
Cargar el siguiente texto en una cadena en etapa de declaracion. 
Cada palabra estara separada por el simbolo -  y toda oracion por el simbolo *. 
Definir la dimension de la cadena usando DEFINE.
Usar una funcion predeterminada para indicar la longitud de la cadena, mostrar el resultado por pantalla. 
Mostrar la cadena considerando una oracion debajo de la otra seperado por una linea en blanco. Indicar cuantas vocales en total tiene el texto.
Usar una funcion predefinida para determinar si la letra de la cadena corresponde a una vocal 1 = A, 2 = E, 3 = i, 4 = O, 5 = U
Usar una funcion normal para determinar si la letra ingresada por teclado corresponde a una que se  encuentra en la cadena.
Indicar cual es la oracion mas larga y cual la mas corta en cantidad de caracteres.
"Hoy es Miercoles. Hoy es el repaso de Programacion 1. Estudio programacion." */

#include <stdio.h>
#include <string.h>
#include <ctype.h>  // <- Esta línea es la que evita el error con 'tolower'

#define TAM 200  // Dimensión adecuada para contener el texto completo

// Cargar el texto formateado: palabras con '-', oraciones con '*'
void cargarCadena(char *cadena) {
	// Texto del enunciado transformado al formato requerido
	strcpy(cadena, "Hoy-es-Miercoles*Hoy-es-el-repaso-de-Programacion-1*Estudio-programacion");
}

// Mostrar la cadena con una oración por línea y una línea en blanco entre ellas
void mostrarCadena(char *cadena) {
	char copia[TAM];
	strcpy(copia, cadena); // Hacer copia para no modificar original
	char *token = strtok(copia, "*");
	while (token != NULL) {
		printf("%s\n\n", token);
		token = strtok(NULL, "*");
	}
}


// Obtener longitud total de la cadena usando función predeterminada
int longitudCadena(char *cadena) {
	return strlen(cadena);
}

// Contar todas las vocales (minúsculas o mayúsculas)
int contarVocales(char *cadena) {
	int count = 0;
	for (int i = 0; cadena[i] != '\0'; i++) {
		char c = tolower(cadena[i]);
		if (c == 'a' || c == 'e' || c == 'i' || c == 'o' || c == 'u')
			count++;
	}
	return count;
}

// Determinar si una letra es vocal (según tabla dada)
int esVocal(char c) {
	c = tolower(c);
	return (c == 'a' || c == 'e' || c == 'i' || c == 'o' || c == 'u');
}

// Verificar si la letra ingresada está presente en la cadena
int letraEnCadena(char *cadena, char letra) {
	for (int i = 0; cadena[i] != '\0'; i++) {
		if (tolower(cadena[i]) == tolower(letra)) // sin importar mayúscula/minúscula
			return 1;
	}
	return 0;
}

// Buscar la oración más corta y más larga
void encontrarOraciones(char *cadena, char *masLarga, char *masCorta) {
	char copia[TAM];
	strcpy(copia, cadena); // Usar copia para no modificar cadena original
	
	char *token = strtok(copia, "*");
	int maxLen = 0, minLen = 1000;
	
	while (token != NULL) {
		int len = strlen(token);
		if (len > maxLen) {
			maxLen = len;
			strcpy(masLarga, token);
		}
		if (len < minLen) {
			minLen = len;
			strcpy(masCorta, token);
		}
		token = strtok(NULL, "*");
	}
}

int main() {
	char cadena[TAM];
	cargarCadena(cadena); // Cargar texto formateado
	
	printf("=== TEXTO CARGADO ===\n");
	mostrarCadena(cadena);
	
	int longitud = longitudCadena(cadena);
	printf("Longitud total de la cadena: %d caracteres\n", longitud);
	
	int totalVocales = contarVocales(cadena);
	printf("Cantidad total de vocales en el texto: %d\n", totalVocales);
	
	char letra;
	printf("\nIngrese una letra para verificar si es vocal: ");
	scanf(" %c", &letra);
	
	if (esVocal(letra))
		printf("La letra '%c' es una vocal.\n", letra);
	else
		printf("La letra '%c' NO es una vocal.\n", letra);
	
	if (letraEnCadena(cadena, letra))
		printf("La letra '%c' se encuentra en la cadena.\n", letra);
	else
		printf("La letra '%c' NO se encuentra en la cadena.\n", letra);
	
	char masLarga[TAM], masCorta[TAM];
	encontrarOraciones(cadena, masLarga, masCorta);
	printf("\nOración más larga: %s\n", masLarga);
	printf("Oración más corta: %s\n", masCorta);
	
	return 0;
}

/*
==================================================
?? COMENTARIOS FINALES PARA EL INFORME / APUNTE
==================================================
? La cadena se carga en forma de constante, formateada con símbolos '-' (palabra) y '*' (oración).
? Se usa strlen() para longitud, tolower() para tratar mayúsculas como minúsculas.
? strtok() permite recorrer oraciones sin modificar la original.
? El código incluye búsqueda de vocales, letras ingresadas y longitud relativa de oraciones.
*/


/* 
----------------------------------------------------------
COMENTARIOS FINALES DEL PROGRAMA
----------------------------------------------------------

1. El texto original se carga en una cadena con palabras separadas por '-' y oraciones separadas por '*'.
Ejemplo cargado: "Hoy-es-Miercoles*Hoy-es-el-repaso-de-Programacion-1*Estudio-programacion"

2. Se define la dimensión máxima de la cadena con una macro: #define TAM 300

3. Se usa la función predeterminada 'strlen()' para obtener la longitud total de la cadena.

4. Para mostrar cada oración:
- Se utiliza 'strtok()' con separador '*'
- Se reemplazan los guiones '-' por espacios antes de imprimir cada oración.
- Se agrega una línea en blanco entre cada oración.

5. Para contar vocales:
- Se recorre la cadena carácter por carácter.
- Se usa 'tolower()' para tratar todas las letras en minúscula.
- Se cuentan si son 'a', 'e', 'i', 'o' o 'u'.

6. La función 'esVocal()' devuelve un valor numérico:
- 1 para A, 2 para E, 3 para I, 4 para O, 5 para U
- 0 si no es vocal

7. Se pide al usuario una letra:
- Se verifica si es vocal
- Se verifica si esa letra se encuentra en la cadena

8. Finalmente, se busca la oración más larga y la más corta:
- Se comparan las longitudes de cada oración separada por '*'
- Se imprimen reemplazando '-' por espacios

----------------------------------------------------------
*/