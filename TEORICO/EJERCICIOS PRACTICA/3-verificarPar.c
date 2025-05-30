// Escriba una función llamada esPar.
// Que esta reciba un número entero y devuelva 1 si es par o 0 si es impar. Mostrar el resultado en el main.

#include <stdio.h>  // Librería estándar de entrada/salida para usar printf y scanf

// Declaración de funciones
int pedirNumero();        // Prototipo: función que pedirá un número al usuario y lo devolverá
int esPar(int numero);    // Prototipo: función que verifica si un número es par (devuelve 1 o 0)
void principal();         // Prototipo: función principal que contiene la lógica del programa

int main(){
    printf("\n");         // Salto de línea para estética
    principal();          // Llamada a la función principal
    return 0;             // Fin del programa
}

void principal(){
    int numero = pedirNumero();   // Se llama a pedirNumero() y se guarda el valor retornado en la variable "numero"
    
    // Se llama a la función esPar con el número ingresado
    // Si devuelve 1, es par; si devuelve 0, es impar
    if (esPar(numero)) {
        printf("El numero %d es par\n", numero);    // Imprime si es par
    } else {
        printf("El numero %d es impar\n", numero);  // Imprime si es impar
    }
}

int pedirNumero(){
    int num;
    printf("Ingrese un numero: ");   // Solicita al usuario que ingrese un número
    scanf("%d", &num);               // Guarda el número ingresado en la variable "num"
    return num;                      // Devuelve ese número a quien lo llamó
}

int esPar(int numero){
    // Operación lógica: si el número es divisible por 2, es par (retorna 1); si no, es impar (retorna 0)
    return (numero % 2 == 0) ? 1 : 0;
}

/*
-------------------------------------------------------
Resumen del programa:
- Este programa pide un número entero al usuario y le indica si es par o impar.
- Se usan tres funciones:
  1. pedirNumero(): solicita el número al usuario y lo devuelve.
  2. esPar(int): determina si el número es par (retorna 1) o impar (retorna 0).
  3. principal(): coordina la lógica llamando a las otras funciones.

Errores que se corrigieron respecto a versiones anteriores:
- Uso incorrecto de parámetros: ahora las funciones devuelven valores (return) en vez de intentar modificarlos dentro.
- Llamadas a funciones mal declaradas o sin argumentos fueron corregidas.
- Se mejoró la separación de responsabilidades entre funciones: cada una hace una sola tarea.
- El uso de `? :` (operador ternario) en esPar simplifica la lógica de retorno.

Aprendizajes:
✔ Cómo retornar valores desde funciones.
✔ Cómo pasar datos entre funciones usando variables.
✔ Cómo separar la lógica del programa en funciones pequeñas y claras.
✔ Uso del operador módulo `%` para verificar si un número es par.

Este tipo de estructura ayuda a escribir programas más claros, reutilizables y mantenibles.
-------------------------------------------------------
*/


