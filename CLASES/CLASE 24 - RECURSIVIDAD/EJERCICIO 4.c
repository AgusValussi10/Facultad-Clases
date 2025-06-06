#include <stdio.h> // Incluye la librería estándar de entrada y salida

// Declaración de la función recursiva que suma los primeros n enteros
int sumaRecursiva(int n);

// Declaración de la función principal del programa
void principal();

int main(){
    principal(); // Llama a la función principal para iniciar el programa
    return 0;    // Retorna 0 para indicar que el programa finalizó correctamente
}

void principal(){
    int n;
    printf("Introduce un numero entero positivo: "); // Solicita al usuario un número
    scanf("%d", &n); // Lee el número introducido y lo guarda en la variable n
    
    if (n < 0) { // Verifica que el número sea positivo
        printf("Por favor, introduce un numero entero positivo.\n"); // Mensaje de error si es negativo
    } else {
        int resultado = sumaRecursiva(n); // Llama a la función recursiva para calcular la suma
        printf("La suma de los primeros %d enteros es: %d\n", n, resultado); // Muestra el resultado
    }
}

// Función recursiva que devuelve la suma de los primeros n enteros
int sumaRecursiva(int n) {
    if (n == 0) {
        return 0; // Caso base: la suma de los primeros 0 enteros es 0
    } else {
        return n + sumaRecursiva(n - 1); // Caso recursivo: suma el número actual y llama a la función con n-1
    }
}
// Esta función suma el número actual n con la suma de los números anteriores
