#include <stdio.h>
#include <stdlib.h>
#include "../.H/menu.h"
#include "../.H/producto.h"
#include "../.H/venta.h"
#include "../.H/administracion.h"

#define MAX_PRODUCTOS 100

void menu() {
    Producto productos[MAX_PRODUCTOS];
    int cantidadProductos = 0;
    RegistroVentas registroVentas;
    registroVentas.totalVentas = 0;

    cargarProductosDesdeTxt(productos, &cantidadProductos);

    if (cantidadProductos == 0) {
        printf("No hay productos cargados.\n");
        return;
    }

    int opcion;
    do {
        system("cls");
        printf("\n--- MENU PRINCIPAL---\n");
        printf("1. Mostrar productos\n");
        printf("2. Registrar venta\n");
        printf("3. Mostrar ventas del dia\n");
        printf("4. Guardar ventas del dia\n");
        printf("5. Menu Administrativo (editar/agregar)\n");
        printf("6. Salir\n");
        printf("Seleccione una opcion: ");
        scanf("%d", &opcion);

        switch (opcion) {
            case 1:
                mostrarProductos(productos, cantidadProductos);
                break;
            case 2:
                registrarVenta(productos, cantidadProductos, &registroVentas);
                break;
            case 3:
                mostrarVentas(&registroVentas);
                break;
            case 4:
                guardarVentas(&registroVentas);
                exportarProductosATexto(productos, cantidadProductos);
                break;
            case 5:
                menuAdministrativo(productos, &cantidadProductos);
                break;
            case 6:
                printf("Cerrando programa. Hasta luego!\n");
                break;
            default:
                printf("Opcion no valida.\n");
        }
    } while (opcion != 6);
}
