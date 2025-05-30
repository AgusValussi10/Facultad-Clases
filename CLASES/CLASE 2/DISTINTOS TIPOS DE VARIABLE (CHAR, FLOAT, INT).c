#include <stdio.h> // Libreria necesaria para utilizar printf()
#include <conio.h> // Libreria necesaria para utilizar getch()

int main()
{
	char c;    // Declara Variables
	float x;   // Declara Variables
	int i;     // Declara Variables
	
	printf("Ingrese un caracter: "); // solicita un caracter, sin \n para que sea a continuacion
	scanf("%c", &c); //entrada de un caracter
	
	printf ("Ingrese un valor flotante: "); // solicita un caracter, sin \n para que sea a continuacion
	scanf ("%f", &x); //entrada de un numero con coma flotante
	
	printf ("Ingrese un valor entero: "); // sin \n para que sea a continuacion
	scanf ("%d", &i); //entrada de enteros
	
	printf ("Mostrar los valores ingresados: "); // sin \n para que sea a continuacion
	
	putchar(c); //salida de un caracter, SIN \n para que se a continuacion
	printf (" %2.3f %2d", x, i); //salida de numeros
	// %2.3f
	// % indica el inicio de un especificador de formato
	// 2 define el ancho mínimo total del número, incluyendo dígitos, punto decimal y espacios si es necesario
	// . separa la parte entera de la parte decimal
	// f indica que el número es de tipo flotante (decimal)
	
	// %2d
	// % indica el inicio del formato
	// 2 define el ancho mínimo total del número. Si el número tiene menos de 2 caracteres, se añaden espacios a la izquierda.
	// d especifica que el número es un entero (decimal)
		
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

