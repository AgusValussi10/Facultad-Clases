/*
Diseñar un programa que permita generar una archivo de texto el cual debe contener los nombres de las materias de TUP.
Mostrar el contenido del archivo, es decir los nombres en la misma linea y separados por dos **. EJ: PROGRAMACION**MATEMATICA
*/
#include <stdio.h>
#include <stdlib.h>

int main() {
    FILE *archivo;
    char *nombreArchivo = "materias.txt";
    char *materias[] = {"PROGRAMACION I", "MATEMATICA", "ORGANIZACION EMPRESARIAL", "ARQUITECTURA Y SO"};
    int cantidadMaterias = sizeof(materias) / sizeof(materias[0]);

    // Abrir el archivo para escritura
    archivo = fopen(nombreArchivo, "w");
    if (archivo == NULL) {
        perror("Error al abrir el archivo");
        return EXIT_FAILURE;
    }

    // Escribir las materias en el archivo
    for (int i = 0; i < cantidadMaterias; i++) {
        fprintf(archivo, "%s", materias[i]);
        if (i < cantidadMaterias - 1) {
            fprintf(archivo, "**"); // Agregar separador entre materias
        }
    }

    // Cerrar el archivo
    fclose(archivo);

    // Abrir el archivo para lectura y mostrar su contenido
    archivo = fopen(nombreArchivo, "r");
    if (archivo == NULL) {
        perror("Error al abrir el archivo para lectura");
        return EXIT_FAILURE;
    }

    char buffer[256];
    while (fgets(buffer, sizeof(buffer), archivo) != NULL) {
        printf("%s", buffer);
    }

    // Cerrar el archivo
    fclose(archivo);

    return EXIT_SUCCESS;
}