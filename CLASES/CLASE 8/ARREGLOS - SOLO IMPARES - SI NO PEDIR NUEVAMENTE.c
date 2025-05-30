#include <stdio.h> // Libreria necesaria para utilizar printf()

int main(){
	
	int A[7];
	int c, acum, d;
	
	c = 0;
	d = 0;
	
	while (d < 7) {
		printf("Ingrese un valor múltiplo de 3\n");
		scanf("%d", &A[c]);
	
		if (A[c] % 3 != 0) {
			do {
				printf("Error, solo son posibles divisibles por 3\n");
				printf("Ingrese nuevamente un numero: ");
				scanf("%d", &A[c]);
			} while (A[c] % 3 != 0);
		}
		d++;
		c++; 
	}
	
	printf("\n");
	acum = 0;
	
	for(c = 0; c < 7; c++){
		printf("Elemento %i: %i \n", c, A[c]);
		acum = acum + A[c];
		if (A[c]%2 == 0){
			d++;
		}
	}
	
	printf("\nSumatoria = %d\n", acum);
	
	if(A[c] != 0){
		printf("\nNo hay numeros pares");
	}
	else{
		printf("\nPares = %d\n", c);
	}
	
	return 0;
}

// GETCHAR y PUTCHAR: permiten la transferencia de 
// caracteres individuales hacia dentro y hacia fuera de la computadora
// GETCHAR, lee un solo carácter desde la entrada estándar (teclado)
// PUTHCAR, imprime un solo carácter en la salida estándar (pantalla(

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


// ARREGLOS = ENTERO
