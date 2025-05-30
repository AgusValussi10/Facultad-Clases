#include <stdio.h> // Libreria necesaria para utilizar printf()
#include <conio.h> // Libreria necesaria para utilizar getch()

int main() {
	char opcion;
	int entradas, preciofinal;

	printf("\t\t**************************************\n");
	printf("\t\t*  BIENVENIDO AL ESTADIO CUSCATLAN   *\n");
	printf("\t\t**************************************\n");
	printf("\t\t* Sectores del Estadio               *\n");
	printf("\t\t* A- Sol general                     *\n");
	printf("\t\t* B- Sol preferente                  *\n");
	printf("\t\t* C- Sombra                          *\n");
	printf("\t\t* D- Tribuna                         *\n");
	printf("\t\t* E- Platea                          *\n");
	printf("\t\t**************************************\n");
	printf("\t\tSelecciona la letra del sector del estadio: ");
	scanf("%c", &opcion);

	switch (opcion)
	{
	case 'A':
		printf("\t\tOpcion Sol general elegida. \n");
		printf("\t\tIngrese la cantidad de entradas a obtener: ");
		scanf ("%d", &entradas);
		preciofinal = entradas * 3;
		printf ("\t\tEl precio por el total de entradas es: %d", preciofinal);
		break;
	case 'B':
		printf("\t\tOpcion Sol preferente elegida. \n");
		printf("\t\tIngrese la cantidad de entradas a obtener: ");
		scanf ("%d", &entradas);
		preciofinal = entradas * 5;
		printf ("\t\tEl precio por el total de entradas es: %d", preciofinal);
		break;
	case 'C':
		printf("\t\tOpcion Sombra. \n");
		printf("\t\tIngrese la cantidad de entradas a obtener: ");
		scanf ("%d", &entradas);
		preciofinal = entradas * 8;
		printf ("\t\tEl precio por el total de entradas es: %d", preciofinal);
		break;
	case'D':
		printf("\t\tOpcion Tribuna elegida. \n");
		printf("\t\tIngrese la cantidad de entradas a obtener: ");
		scanf ("%d", &entradas);
		preciofinal = entradas * 15;
		printf ("\t\tEl precio por el total de entradas es: %d", preciofinal);
		break;
	case 'E':
		printf("\t\tOpcion Platea elegida. \n");
		printf("\t\tIngrese la cantidad de entradas a obtener: ");
		scanf ("%d", &entradas);
		preciofinal = entradas * 20;
		printf ("\t\tEl precio por el total de entradas es: %d", preciofinal);
		break;
	default: printf("\n\t\tOpcion Ingresada Incorrecta \n"), printf("\t\tFin del programa");
	
	}
	
}


// GETCHAR y PUTCHAR: permiten la transferencia de 
// caracteres individuales hacia dentro y hacia fuera de la computadora
// GETCHAR, lee un solo carácter desde la entrada estándar (teclado)
// PUTHCAR, imprime un solo carácter en la salida estándar (pantalla)

// GETS y PUTS: permiten la entrada y salida de cadenas de caracteres.
// GETS, toma el almacena el Valor
// PUTS, devuelve el valor ingresado

// PRINTF y SCANF: permiten la transferencia de caracteres individuales, valores numericos y cadenas de caracteres
// SCANF, el operador & es necesario en scanf() para simular las llamadas por referencia, y hace que la funcion trabaje
// internamiente con la direccion de la variable
// PRINTF, texto y cadena de control de tipo son opcionales, depende que se quiere mostrar;
// cadena de control es una cadena de caracteres "%tipo", que indica el tipo de dato a desplegar
// por otro lado, argumento o argumentos es el valor o los valores que se pretende mostrar, y pueden ser variables,
// constantes, expresiones aritmeticas, resultados de funciones o simplemente texto que el programa debe mostrar al usuario
//
// Funcion printf() - Cadena de Control
//
// Cadena de tipo             Descripcion
//     %d            El dato es un entero decinal (int)
//     %i            El dato es un entero 
//     %o            El dato es un entero octal 
//     %x            El dato es un entero hexadecimal
//     %u            El dato es un entero sin signo en decimal (unsigned int)
//     %c            El dato es un caracter (char)
//     %e            El dato es un real escrito con punto decimal con signo (float)
//     %f            El dato es un real (float)
//     %g            El dato es un real (float)
//     %s            El dato es una cadena de caracteres que finaliza con el caracter nulo \0
//     %lf           El dato es real de tipo long double

// SECUENCIA DE ESCAPE
// Las secuencias de escape son cadenas de caracteres que tienen distintos signfiiados dependiente la cadena que se utilice
//
// Cadena de tipo             Descripcion
//      \a                      ALARMA
//      \b                    RETROCESO
//      \f                  AVANCE DE PAGINA
//      \n           RETORNO DE CARRO Y AVANCE DE LINEA
//      \r                RETORNO DE CARRO
//      \t                    TABULACION
//      \v               TABULACION VERTICAL
//      \\               DIAGONAL INVERTIDA
//      \?              SIGNO DE INTERROGACION
//      \"                 COMILLAS DOBLE
//      \000                    OCTAL
//      \xhh                 HEXADECIMAL
//      \0                   CARACTER NULO
