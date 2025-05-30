#include <stdio.h>    // Para printf y scanf
#include <conio.h>    // Para getch (entornos tipo Dev-C++)
#include <ctype.h>    // Para tolower (opcional)

int main()
{
	char cadena[5] = {'h', 'o', 'l', 'a', '0'};  // Primera cadena fija
	char cad1[5];            // Segunda cadena (caracteres ingresados)
	char car;                // Carácter temporal para getch
	char buscado;            // Carácter a buscar en ambas cadenas
	int i, cont1 = 0, cont2 = 0;  // Contadores de ocurrencias
	
	char nombre[10], apellidos[10];  // Datos personales
	
	// Mostrar caracteres de la primera cadena
	printf("Cadena fija:\n");
	for (i = 0; i < 5; i++) {
		printf("carácter %d: %c\n", i, cadena[i]);
	}
	
	// Pedir al usuario su nombre
	printf("\nIntroduce tu nombre: ");
	scanf("%s", nombre);  // Lee hasta espacio
	
	// Pedir apellidos
	printf("Introduce tus apellidos: ");
	scanf("%s", apellidos);
	
	// Mostrar nombre completo
	printf("Usted es %s %s\n", nombre, apellidos);
	
	// Captura de 5 caracteres con getch()
	printf("\nIntroduce 5 caracteres uno por uno:\n");
	for (i = 0; i < 5; i++) {
		printf("Caracter %d: ", i + 1);
		car = getch();         // Captura sin necesidad de Enter
		printf("%c\n", car);   // Muestra el carácter capturado
		cad1[i] = car;
	}
	
	// Mostrar cadena ingresada
	printf("\nCadena ingresada con getch:\n");
	for (i = 0; i < 5; i++) {
		printf("carácter %d: %c\n", i, cad1[i]);
	}
	
	// Ingresar el carácter a buscar
	printf("\nIntroduce un carácter para buscar en ambas cadenas: ");
	scanf(" %c", &buscado);  // Espacio antes de %c para limpiar búfer
	
	// Contar ocurrencias en cadena fija
	for (i = 0; i < 5; i++) {
		if (cadena[i] == buscado)
			cont1++;
	}
	
	// Contar ocurrencias en cadena ingresada
	for (i = 0; i < 5; i++) {
		if (cad1[i] == buscado)
			cont2++;
	}
	
	// Mostrar resultados
	printf("\nEl carácter '%c' aparece:\n", buscado);
	printf("- %d veces en la primera cadena (cadena fija)\n", cont1);
	printf("- %d veces en la segunda cadena (cadena ingresada)\n", cont2);
	
	if (cont1 > cont2)
		printf("=> Aparece más veces en la primera cadena.\n");
	else if (cont2 > cont1)
		printf("=> Aparece más veces en la segunda cadena.\n");
	else
		printf("=> Aparece la misma cantidad de veces en ambas cadenas.\n");
	
	getch();  // Espera antes de finalizar
	return 0;
}
