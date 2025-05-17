#include <stdio.h> // Libreria necesaria para utilizar printf()
#include <conio.h> // Libreria necesaria para utilizar getch()

int main() {
	
	int numero1, numero2, resultado, opcion; // DECLARAMOS VARIABLES
	
	printf ("Ingrese un numero: "); // PEDIMOS QUE INGRESE UN NUMERO
	scanf ("%d", &numero1); // ALMACENAMOS EL 1° NUMERO EN UNA VARIABLE
	
	printf ("Ingrese el segundo numero: "); // PEDIMOS QUE INGRESE OTRO NUMERO
	scanf ("%d", &numero2); // ALMACENAMOS EL 2° NUMERO EN UNA VARIABLE
	
	printf ("Ahora seleccion la operacion matematica que desea hacer \n");
	printf("Opcion 1 = Suma \n");
	printf("Opcion 2 = Resta \n");
	printf("Opcion 3 = Multiplicacion \n");
	printf("Opcion 4 = Division \n");
	scanf("%d", &opcion); // ALMACENAMOS EL NUMERO DE LA OPCION ELEGIDA
	
	switch (opcion){ // ABRIMOS SL SWITCH
		case 1:
			printf("Opcion SUMA seleccionada. \n");
			resultado = numero1 + numero2;
			printf("El resultado de la suma es: %d", resultado);
			break; // EN CASO QUE ENTRE EN ESTA OPCION, SALE AL FINALIZAR CON BREK;
		case 2:
			printf("Opcion RESTA seleccionada. \n");
			resultado = numero1 - numero2,
			printf("El resultado de la suma es: %d", resultado);
			break; // EN CASO QUE ENTRE EN ESTA OPCION, SALE AL FINALIZAR CON BREK;
		case 3:
			printf("Opcion MULTIPLICACION seleccionada. \n");
			resultado = numero1 * numero2;
			printf("El resultado de la suma es: %d", resultado);
			break; // EN CASO QUE ENTRE EN ESTA OPCION, SALE AL FINALIZAR CON BREK;
		case 4:
			printf("Opcion DIVISION seleccionada. \n");
			resultado = numero1 / numero2;
			printf("El resultado de la suma es: %d", resultado);
			break; // EN CASO QUE ENTRE EN ESTA OPCION, SALE AL FINALIZAR CON BREK;
		default:
		printf("Opcion Invalida. \n");
	}
	return 0;
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
