// DISEÑAR UN PROGRAMA QUE ME PERMITA MOSTRAR POR PANTALLA EL RESULTADO
// DE LA TABLA DE VERDAD PARA UNA CONJUNCION, DISYUNCION E IMPLICACION.
// SE DEBE USAR UN MENU DE OPCIONES PARA SELECCIONAR LA TABLA A MOSTRAR

#include <stdio.h> // Libreria necesaria para utilizar printf()
#include <conio.h> // Libreria necesaria para utilizar getch()

int main() {
	char opcion;
	int entradas, preciofinal;
	
	printf("\t\t**************************************\n");
	printf("\t\t*         TABLAS DE LA VERDAD        *\n");
	printf("\t\t**************************************\n");
	printf("\t\t* A- Conjuncion                      *\n");
	printf("\t\t* B- Disyuncion                      *\n");
	printf("\t\t* C- Implicacin                      *\n");
	printf("\t\t**************************************\n");
	printf("\t\tSelecciona la tabla que desea saber: ");
	scanf("%c", &opcion);
	
	switch (opcion)
	{
	case 'A':
		printf("\n");
		printf("\t\tOpcion CONJUNCION elegida. \n");
		printf("\t\tLa tabla de la verdad se compone de la siguiente manera");
		printf("\n");
		printf("\t\t******************************************\n");
		printf("\t\t*              CONJUNCION                *\n");
		printf("\t\t******************************************\n");
		printf("\t\t*             P    Q    P^Q              *\n");
		printf("\t\t******************************************\n");
		printf("\t\t*             V    V     V               *\n");
		printf("\t\t*             V    F     F               *\n");
		printf("\t\t*             F    V     F               *\n");
		printf("\t\t*             F    F     F               *\n");
		printf("\t\t******************************************\n");
		break;
	case 'B':
		printf("\n");
		printf("\t\tOpcion CONJUNCION elegida. \n");
		printf("\t\tLa tabla de la verdad se compone de la siguiente manera");
		printf("\n");
		printf("\t\t******************************************\n");
		printf("\t\t*           DISYUNCION                   *\n");
		printf("\t\t******************************************\n");
		printf("\t\t*          P    Q    PvQ                 *\n");
		printf("\t\t******************************************\n");
		printf("\t\t*          V    V     V                  *\n");
		printf("\t\t*          V    F     V                  *\n");
		printf("\t\t*          F    V     V                  *\n");
		printf("\t\t*          F    F     F                  *\n");
		printf("\t\t******************************************\n");
		break;
	case 'C':
		printf("\n");
		printf("\t\tOpcion CONJUNCION elegida. \n");
		printf("\t\tLa tabla de la verdad se compone de la siguiente manera");
		printf("\n");
		printf("\t\t******************************************\n");
		printf("\t\t*           CONDICIONAL                  *\n");
		printf("\t\t******************************************\n");
		printf("\t\t*          P    Q   P->Q                 *\n");
		printf("\t\t******************************************\n");
		printf("\t\t*          V    V     V                  *\n");
		printf("\t\t*          V    F     F                  *\n");
		printf("\t\t*          F    V     V                  *\n");
		printf("\t\t*          F    F     V                  *\n");
		printf("\t\t******************************************\n");
		break;
	default: 
		printf("\n\t\tOpcion Ingresada Incorrecta \n");
		printf("\t\tFin del programa");
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
