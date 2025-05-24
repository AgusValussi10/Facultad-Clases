// 3) Cuantas cifras tiene un numero?
// Crear una función recursiva que muestre los dígitos de un número entero en orden inverso.
// Ejemplo: entrada: 1234 → salida: 4321

#include <stdio.h>

void mostrarDigitosInverso(int n); // Declaración de la función recursiva
void principal(); // Declaración de la función principal

int main() {
    principal(); // Llamada a la función principal
    return 0;
}

// Definición de la función recursiva que muestra los dígitos en orden inverso
void mostrarDigitosInverso(int n) {
    if (n < 10) { // Caso base: si n es menor que 10, imprime el dígito
        printf("%d", n);
    } else {
        printf("%d", n % 10); // Imprime el último dígito
        mostrarDigitosInverso(n / 10); // Llama a la función con el número sin el último dígito
    }
}

void principal() // Definición de la función principal
{
    int n;
    printf("Ingrese un número natural: ");
    scanf("%d", &n);
    printf("Los dígitos de %d en orden inverso son: ", n);
    mostrarDigitosInverso(n); // Llama a la función para mostrar los dígitos en orden inverso
    printf("\n");
}