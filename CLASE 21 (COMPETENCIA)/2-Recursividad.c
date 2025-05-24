// 2) Cuantas cifras tiene un numero?
// Crear una función recursiva que reciba un número entero positivo,
// y devuelva la cantidad de dígitos que contiene.
// Ejemplo: digitos(1234) → 4 / digitos(9) → 1

#include <stdio.h>

int digitos(int n); // Declaración de la función recursiva
void principal(); // Declaración de la función principal

int main() {
    principal(); // Llamada a la función principal
    return 0;
}

// Definición de la función recursiva que calcula la cantidad de dígitos
int digitos(int n) {
    if (n < 10) { // Caso base: si n es menor que 10, tiene 1 dígito
        return 1;
    }
    // Caso recursivo: suma 1 al resultado de la función con el número dividido por 10
    return 1 + digitos(n / 10); 
}
void principal() // Definición de la función principal
{
    int n;
    printf("Ingrese un número natural: ");
    scanf("%d", &n);
    printf("La cantidad de dígitos en %d es: %d\n", n, digitos(n));
}