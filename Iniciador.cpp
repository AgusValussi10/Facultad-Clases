#include <stdio.h> // Libreria necesaria para utilizar printf()
#include <conio.h> // Libreria necesaria para utilizar getch()

int main() {
	
	
	
	return 0;
}

// git add .                      # Agregar todos los cambios
// git commit -m "Tu mensaje"     # Crear el commit
// git push origin main           # Subir a la rama main en GitHub


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


// IF y IF ANIDADOS
// Permiten ejecutar un bloque de c�digo solo si se cumple una condici�n.
//
// Sintaxis IF:
// if (condici�n) {
//     // c�digo a ejecutar si la condici�n es verdadera
// }
//
// Sintaxis IF - ELSE:
// if (condici�n) {
//     // si la condici�n es verdadera
// } else {
//     // si la condici�n es falsa
// }
//
// Sintaxis IF ANIDADO:
// if (condici�n1) {
//     // si condici�n1 es verdadera
//     if (condici�n2) {
//         // si condici�n2 tambi�n es verdadera
//     }
// } else {
//     // si condici�n1 es falsa
// }


// SWITCH
// Permite ejecutar diferentes bloques de c�digo seg�n el valor de una variable.
//
// Sintaxis:
// switch (variable) {
//     case valor1:
//         // c�digo si variable == valor1
//         break;
//     case valor2:
//         // c�digo si variable == valor2
//         break;
//     ...
//     default:
//         // c�digo si ning�n caso se cumple
// }
//
// IMPORTANTE:
// - La palabra clave 'break' evita que se ejecuten los siguientes casos (ca�da de casos).
// - 'default' es opcional, pero �til para manejar casos no previstos.


// WHILE
// Ejecuta un bloque de c�digo mientras una condici�n sea verdadera.
//
// Sintaxis:
// while (condici�n) {
//     // c�digo a ejecutar mientras la condici�n sea verdadera
// }
//
// IMPORTANTE:
// - La condici�n se eval�a antes de cada iteraci�n.
// - Si la condici�n nunca es falsa, el bucle se vuelve infinito.


// DO WHILE
// Similar al while, pero garantiza que el bloque se ejecute al menos una vez.
//
// Sintaxis:
// do {
//     // c�digo a ejecutar
// } while (condici�n);
//
// IMPORTANTE:
// - La condici�n se eval�a despu�s de ejecutar el bloque.
// - Se ejecuta al menos una vez, aunque la condici�n sea falsa desde el inicio.


// FOR
// Ideal para repetir un bloque de c�digo un n�mero conocido de veces.
//
// Sintaxis:
// for (inicializaci�n; condici�n; incremento/decremento) {
//     // c�digo a ejecutar en cada iteraci�n
// }
//
// Ejemplo:
// for (int i = 0; i < 10; i++) {
//     printf("%d\n", i);
// }
//
// IMPORTANTE:
// - Se usa cuando sabemos cu�ntas veces queremos repetir el bucle.
// - La variable de control (ej: i) puede declararse dentro o fuera del for.
