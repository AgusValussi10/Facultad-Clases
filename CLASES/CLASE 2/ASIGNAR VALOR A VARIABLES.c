#include <stdio.h> // Libreria necesaria para utilizar printf()
#include <conio.h> // Libreria necesaria para utilizar getch()

int main() 
{	
	char b;     // Declarar Variables
	int a,t,p;  // Declarar Variables
	
	printf ("Hoy es Miercoles \n"); // \n sirve para dar un enter
	printf ("Hoy es la segunda clase de Prog. I \n"); 
	a = 3; // Asignamos valor
	printf ("El Valor de la Variable A, es: %d \n",a ); // %d es para determinar como un entero decimal
	b = 'i'; // Asignamos valor
	printf ("Valor de B es: %c \n", b); // %c es para determinar como un caracter
	t = 5; // Asignamos valor
	printf ("%d + %d = %d \n", a, t, a+t); // se asigna % en el orden que se muestran al final las variables
	
	p = a + t; // Asignamos valor
	printf ("%d + %d = %d \n", a,t,p); // lo mismo que el anterior solo que asignando una variable nueva para el resultado
	
	printf ("\n"); // \n sirve para dar un enter
	
	printf ("%d\n%c\n%d\n%d", a,b,t,p); // se asigna % en el orden que se muestran al final las variables

	return 0;
}

// GETCHAR y PUTCHAR: permiten la transferencia de 
// caracteres individuales hacia dentro y hacia fuera de la computadora
// GETCHAR, lee un solo car�cter desde la entrada est�ndar (teclado)
// PUTHCAR, imprime un solo car�cter en la salida est�ndar (pantalla)

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

