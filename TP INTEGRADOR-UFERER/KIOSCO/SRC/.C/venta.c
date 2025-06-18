#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "../.H/venta.h"
#include "../.H/producto.h"  // para usar Producto y buscarProducto

#define ARCHIVO_VENTAS "ventas.txt"

void registrarVenta(Producto productos[], int cantidadProductos, RegistroVentas *registro) {
    char entrada[50];
    int cantidad;

    printf("Ingrese nombre o numero del producto: ");
    scanf("%s", entrada);

    int indice = buscarProducto(productos, cantidadProductos, entrada);

    if (indice == -1) {
        printf("Producto no encontrado.\n");
        // Limpieza de buffer para evitar problemas con getchar
        printf("Presione ENTER para continuar...");
        while (getchar() != '\n');
        getchar();
        system("cls"); // Limpiar pantalla para una mejor visualización
        return;
    }
    

    // Mostrar informacion del producto
    printf("\nProducto seleccionado:\n");
    printf("Nombre: %s\n", productos[indice].nombre);
    printf("Precio: $%d\n", productos[indice].precio);
    printf("Stock disponible: %d\n", productos[indice].stock);

    // Confirmar
    char confirmar;
    printf("Desea continuar con la venta? (s/n): ");
    scanf(" %c", &confirmar);

    if (confirmar != 's' && confirmar != 'S') {
        printf("Venta cancelada por el usuario.\n");
        // Limpieza de buffer para evitar problemas con getchar
        printf("Presione ENTER para continuar...");
        while (getchar() != '\n');
        getchar();
        system("cls"); // Limpiar pantalla para una mejor visualización
        return;
    }

    printf("Ingrese cantidad: ");
    scanf("%d", &cantidad);

    if (cantidad <= 0 || cantidad > productos[indice].stock) {
        printf("Error: cantidad invalida. Debe ser mayor a 0 y menor o igual al stock disponible.\n");
        printf("Stock disponible: %d\n", productos[indice].stock);
        // Limpieza de buffer para evitar problemas con getchar
        printf("Presione ENTER para continuar...");
        while (getchar() != '\n');
        getchar();
        system("cls"); // Limpiar pantalla para una mejor visualización
        return;
    }
    

    productos[indice].stock -= cantidad; // Actualizar stock del producto

    Venta venta;
    strcpy(venta.nombre, productos[indice].nombre); // Copiar nombre del producto a la venta
    venta.cantidad = cantidad; 
    venta.precio = productos[indice].precio; // Calcular precio total de la venta
    registro->ventas[registro->totalVentas++] = venta; // Registrar la venta

    printf("Venta registrada: %s - Cantidad: %d - Total: $%d\n",
           venta.nombre, venta.cantidad, venta.precio * venta.cantidad);
    printf("Stock restante de %s: %d\n", productos[indice].nombre, productos[indice].stock);

        // Limpieza de buffer para evitar problemas con getchar
        printf("Presione ENTER para continuar...");
        while (getchar() != '\n');
        getchar();
        system("cls"); // Limpiar pantalla para una mejor visualización
}

void mostrarVentas(RegistroVentas *registro) {
    printf("\nVentas del dia:\n");
    int totalGeneral = 0.0;
    for (int i = 0; i < registro->totalVentas; i++) {
        printf("%d. %s - Cantidad: %d - Total: $%d\n",
               i + 1,
               registro->ventas[i].nombre,
               registro->ventas[i].cantidad,
               registro->ventas[i].precio * registro->ventas[i].cantidad);
        totalGeneral += registro->ventas[i].precio * registro->ventas[i].cantidad; // Calcular total general
    }
    printf("TOTAL VENDIDO: $%d\n", totalGeneral);
    // Limpieza de buffer para evitar problemas con getchar
    printf("Presione ENTER para continuar...");
    while (getchar() != '\n');
    getchar();
    system("cls"); // Limpiar pantalla para una mejor visualización
}

void leerVentas(RegistroVentas *registro) {
    FILE *archivo = fopen(ARCHIVO_VENTAS, "rb");
    if (archivo == NULL) {
        printf("No se pudo abrir archivo de ventas.\n");
        return;
    }

    fread(registro, sizeof(RegistroVentas), 1, archivo); // Leer registro de ventas desde el archivo
    fclose(archivo);
}

void guardarVentas(RegistroVentas *registro) {
    FILE *archivo = fopen("ventas.txt", "w");
    if (archivo == NULL) {
        printf("No se pudo abrir ventas.txt para escribir.\n");
        return;
    }

    int total = 0;

    for (int i = 0; i < registro->totalVentas; i++) {
        Venta v = registro->ventas[i];
        int subtotal = v.precio * v.cantidad;
        fprintf(archivo, "Producto: %s | Cantidad: %d | Precio: %d | Subtotal: %d\n",
                v.nombre, v.cantidad, v.precio, subtotal);
        total += subtotal;
    }

    fprintf(archivo, "TOTAL VENDIDO: $%d\n", total);
    fclose(archivo);
    printf("Ventas guardadas correctamente en ventas.txt\n");

    // Limpieza de buffer para evitar problemas con getchar
    printf("Presione ENTER para continuar...");
    while (getchar() != '\n');
    getchar();
    system("cls"); // Limpiar pantalla para una mejor visualización
}

