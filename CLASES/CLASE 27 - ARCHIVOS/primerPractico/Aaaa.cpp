#include <stdio.h>

int main() {
    FILE *parch;

    parch = fopen("banco.dat", "rb");  // Intento abrir para lectura

    if (parch == NULL) {  // Si no existe o no se pudo abrir
        parch = fopen("banco.dat", "wb");  // Intento crear el archivo

        if (parch == NULL) {  // Si tampoco se pudo crear
            printf("El archivo no puede ser abierto\n");
            return 1;  // Salir con error
        }
    }

    // Aquí el archivo está abierto (modo lectura o escritura)
    // Podés hacer operaciones con el archivo

    fclose(parch);  // Cerramos el archivo
    return 0;  // Salida correcta
}
