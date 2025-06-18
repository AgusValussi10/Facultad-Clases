#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include "../.H/producto.h"

#define ARCHIVO_TXT_PRODUCTOS "productos.txt"

void cargarProductosDesdeTxt(Producto productos[], int *cantidadProductos) {
    FILE *archivo = fopen(ARCHIVO_TXT_PRODUCTOS, "r");
    if (archivo == NULL) {
        printf("No se pudo abrir productos.txt. Verifique que exista.\n");
        return;
    }

    char linea[100];
    *cantidadProductos = 0;

    while (fgets(linea, sizeof(linea), archivo)) {
        linea[strcspn(linea, "\n")] = 0;
        char *nombre = strtok(linea, ",");
        char *precioStr = strtok(NULL, ",");
        char *stockStr = strtok(NULL, ",");

        if (nombre && precioStr && stockStr) {
            strcpy(productos[*cantidadProductos].nombre, nombre);
            productos[*cantidadProductos].precio = atoi(precioStr);
            productos[*cantidadProductos].stock = atoi(stockStr);
            (*cantidadProductos)++;
        }
    }

    fclose(archivo);
}

void exportarProductosATexto(Producto productos[], int cantidadProductos) {
    FILE *archivo = fopen(ARCHIVO_TXT_PRODUCTOS, "w");
    if (archivo == NULL) {
        printf("No se pudo crear el archivo de texto de productos.\n");
        return;
    }

    for (int i = 0; i < cantidadProductos; i++) {
        fprintf(archivo, "%s,%d,%d\n", productos[i].nombre, productos[i].precio, productos[i].stock);
    }

    fclose(archivo);
    printf("Archivo productos.txt actualizado.\n");
}

void mostrarProductos(Producto productos[], int cantidadProductos) {
    printf("\nLista de productos:\n");
    for (int i = 0; i < cantidadProductos; i++) {
        printf("%d. %s - Precio: $%d - Stock: %d\n",
               i + 1, productos[i].nombre, productos[i].precio, productos[i].stock);
    }
    printf("Presione ENTER para continuar...");
    while (getchar() != '\n'); // Limpiar buffer
    getchar();
    system("cls");
}

int buscarProducto(Producto productos[], int cantidadProductos, char *entrada) {
    if (isdigit(entrada[0])) {
        int numero = atoi(entrada);
        if (numero >= 1 && numero <= cantidadProductos) {
            return numero - 1;
        } else {
            return -1;
        }
    } else {
        #ifdef _WIN32
            #define strcasecmp _stricmp
        #endif

        for (int i = 0; i < cantidadProductos; i++) {
            if (strcasecmp(productos[i].nombre, entrada) == 0) {
                return i;
    }
}

    }
    return -1;
}

void editarProducto(Producto productos[], int *cantidadProductos) {
    int opcion;
    printf("1. Editar producto existente\n");
    printf("2. Agregar nuevo producto\n");
    printf("Seleccione una opcion: ");
    scanf("%d", &opcion);

    if (opcion == 1) {
        char entrada[50];
        printf("Ingrese nombre o numero del producto: ");
        scanf("%s", entrada);

        int indice = buscarProducto(productos, *cantidadProductos, entrada);

        if (indice == -1) {
            printf("Producto no encontrado.\n");
            return;
        }

        int subopcion;
        printf("Editar 1-Precio o 2-Stock: ");
        scanf("%d", &subopcion);

        if (subopcion == 1) {
            float nuevoPrecio;
            printf("Ingrese nuevo precio: ");
            scanf("%f", &nuevoPrecio);
            productos[indice].precio = nuevoPrecio;
            printf("Precio actualizado.\n");
        } else if (subopcion == 2) {
            int nuevoStock;
            printf("Ingrese nuevo stock: ");
            scanf("%d", &nuevoStock);
            productos[indice].stock = nuevoStock;
            printf("Stock actualizado.\n");
        } else {
            printf("Opcion invalida.\n");
        }

    } else if (opcion == 2) {
        if (*cantidadProductos >= MAX_PRODUCTOS) {
            printf("No se pueden agregar mas productos.\n");
            return;
        }

        Producto nuevo;
        printf("Ingrese nombre del nuevo producto: ");
        scanf("%s", nuevo.nombre);

        for (int i = 0; i < *cantidadProductos; i++) {
            if (strcmp(productos[i].nombre, nuevo.nombre) == 0) {
                printf("El producto ya existe.\n");
                return;
            }
        }

        printf("Ingrese precio: ");
        scanf("%f", &nuevo.precio);
        printf("Ingrese stock: ");
        scanf("%d", &nuevo.stock);

        productos[*cantidadProductos] = nuevo;
        (*cantidadProductos)++;

        printf("Producto agregado correctamente.\n");

    } else {
        printf("Opcion invalida.\n");
    }
}
