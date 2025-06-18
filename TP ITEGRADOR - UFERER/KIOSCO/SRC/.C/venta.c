#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "../.H/venta.h"
#include "../.H/producto.h"  // para usar Producto y buscarProducto

#define ARCHIVO_VENTAS "ventas.dat"

void registrarVenta(Producto productos[], int cantidadProductos, RegistroVentas *registro) {
    char entrada[50];
    int cantidad;

    printf("Ingrese nombre o numero del producto: ");
    scanf("%s", entrada);

    int indice = buscarProducto(productos, cantidadProductos, entrada);

    if (indice == -1) {
        printf("Producto no encontrado.\n");
        printf("Presione ENTER para continuar...");
        while (getchar() != '\n');
        getchar();
        system("cls");
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
        printf("Presione ENTER para continuar...");
        while (getchar() != '\n');
        getchar();
        system("cls");
        return;
    }

    printf("Ingrese cantidad: ");
    scanf("%d", &cantidad);

    if (cantidad <= 0 || cantidad > productos[indice].stock) {
        printf("Error: cantidad invalida. Debe ser mayor a 0 y menor o igual al stock disponible.\n");
        printf("Stock disponible: %d\n", productos[indice].stock);
        printf("Presione ENTER para continuar...");
        while (getchar() != '\n');
        getchar();
        system("cls");
        return;
    }
    

    productos[indice].stock -= cantidad;

    Venta venta;
    strcpy(venta.nombre, productos[indice].nombre);
    venta.cantidad = cantidad;
    venta.precio = productos[indice].precio * cantidad;
    registro->ventas[registro->totalVentas++] = venta;

    printf("Venta registrada: %s - Cantidad: %d - Total: $%d\n",
           venta.nombre, venta.cantidad, venta.precio);
    printf("Stock restante de %s: %d\n", productos[indice].nombre, productos[indice].stock);

    printf("Presione ENTER para continuar...");
    while (getchar() != '\n');
    getchar();
    system("cls");
}

void mostrarVentas(RegistroVentas *registro) {
    printf("\nVentas del dia:\n");
    float totalGeneral = 0.0;
    for (int i = 0; i < registro->totalVentas; i++) {
        printf("%d. %s - Cantidad: %d - Total: $%d\n",
               i + 1,
               registro->ventas[i].nombre,
               registro->ventas[i].cantidad,
               registro->ventas[i].precio);
        totalGeneral += registro->ventas[i].precio;
    }
    printf("TOTAL VENDIDO: $%d\n", totalGeneral);
    printf("Presione una tecla para continuar...");
    getchar();
    getchar();
    system("cls");
}

void guardarVentas(RegistroVentas *registro) {
    FILE *archivo = fopen(ARCHIVO_VENTAS, "wb");
    if (archivo == NULL) {
        printf("No se pudo abrir archivo de ventas.\n");
        return;
    }

    fwrite(registro, sizeof(RegistroVentas), 1, archivo);
    fclose(archivo);
    printf("Ventas guardadas en %s.\n", ARCHIVO_VENTAS);
    printf("Presione ENTER para continuar...");
    while (getchar() != '\n');
    getchar();
    system("cls");
}

void leerVentas(RegistroVentas *registro) {
    FILE *archivo = fopen(ARCHIVO_VENTAS, "rb");
    if (archivo == NULL) {
        printf("No se pudo abrir archivo de ventas.\n");
        return;
    }

    fread(registro, sizeof(RegistroVentas), 1, archivo);
    fclose(archivo);
}
