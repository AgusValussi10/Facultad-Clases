// Cree una función llamada areaTriangulo que reciba la base y la altura de un triángulo y retorne el área. 
// Muestre el resultado en el main.

#include <stdio.h>  // Inclusión de la librería estándar para entrada/salida

// Declaración de funciones
void baseAltura(int *base, int *altura); // Esta función recibe punteros a base y altura para modificar sus valores desde dentro de la función
float areaTriangulo(int base, int altura); // Recibe los valores enteros de base y altura, y devuelve el área como float
void principal(); // Función principal del programa (lógica principal)

int main(){
    printf("\n");           // Imprime un salto de línea por estética
    principal();            // Llama a la función principal donde se ejecuta la lógica
    return 0;               // Fin del programa
}

void principal(){
    int base, altura;                       // Se declaran las variables donde se almacenarán los datos del usuario
    baseAltura(&base, &altura);            // Se pasan las direcciones de memoria de base y altura
                                           // El operador & obtiene la dirección en memoria de cada variable
    areaTriangulo(base, altura);           // Se pasan los valores (no direcciones) a la función para calcular el área
}


void baseAltura(int *base, int *altura){   // Se reciben punteros (int *) como parámetros
    // Esto permite modificar directamente las variables originales (base y altura)
    printf("Ingrese la base del triangulo: ");
    scanf("%d", base);                     // No se usa &, porque base ya es un puntero (una dirección)
    // scanf guardará el valor en la dirección apuntada por base
    printf("Ingrese la altura del triangulo: ");
    scanf("%d", altura);                   // Igual que antes, altura ya es un puntero, no necesita &
}


float areaTriangulo(int base, int altura){   // Se reciben los valores por copia (no se modifican)
    float area = (base * altura) / 2.0;      // Se calcula el área. Se divide por 2.0 para asegurarse que sea float
    printf("El area del triangulo es: %.2f \n", area); // Se imprime el área con 2 decimales
    return area;                             // Se retorna el área por si se quiere usar después
}

/*
=================== RESUMEN FINAL ===================

🟢 OBJETIVO DEL PROGRAMA:
- Pedir al usuario la base y altura de un triángulo.
- Calcular e imprimir el área (base * altura / 2).

🟠 ERRORES Y CORRECCIONES APRENDIDAS:

1. ❌ Pasar variables por valor no modificaba su contenido en otras funciones.
   ✅ Se resolvió pasando las variables por referencia usando punteros (int *base, int *altura)
   ✅ Se usó & en el llamado (por ejemplo: &base) y * en el parámetro (por ejemplo: int *base)

2. ❌ scanf no funcionaba correctamente cuando se usaban variables no inicializadas.
   ✅ Se aprendió que las variables deben tener memoria asignada correctamente antes de usar scanf.
   ✅ Cuando se usa un puntero como parámetro, NO se pone & en scanf (porque ya es una dirección).

3. ❌ El área daba siempre 0 cuando se usaban enteros (int).
   ✅ Se cambió la división a / 2.0 para que el cálculo se haga en float y no trunque el resultado.
   ✅ También se cambió el tipo de área a float para reflejar esto.

🧠 CONCEPTOS CLAVE RECORDAR:

- `&variable` → dirección de memoria de una variable (se usa al pasar a funciones por referencia)
- `*puntero` → accede al valor contenido en una dirección (se usa en parámetros para modificar datos)
- Pasar por puntero permite que una función modifique una variable definida en otra parte.
- Las funciones deben llamarse correctamente sin volver a declararlas dentro de `main()` (error común).

✅ Buen uso de modularización: el código está dividido en funciones claras y reutilizables.

=====================================================
*/

