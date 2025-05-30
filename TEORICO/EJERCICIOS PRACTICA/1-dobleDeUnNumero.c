// Escriba una función llamada doble que reciba un número entero y devuelva su doble. 
// El programa principal debe pedir un número al usuario, llamar a la función y mostrar el resultado.

#include <stdio.h>

int numeros();       // Declaración de la función
int doble(int x);    // Declaración de la función
void principal();    // Declaración de la función

int main() {

    principal(); // Llamada a la función principal          
    return 0;
}

void principal() {
    printf("\n");
    int num = numeros();     
    doble(num);             
}

int numeros() {
    int a;
    printf("Ingrese un numero: ");
    scanf("%d", &a);
    return a;
}

int doble(int a) {
    int resultado = a * 2;
    printf("El doble de %d es %d \n", a, resultado);
    return resultado;
}
