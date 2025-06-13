/*Este va a ser un trabajo final integrador
Debo crear un punto de registro de ventas de un kiosco, teniendo en cuenta todo lo dado hasta ahora
Arreglo de productos, con precios y stock.
Registro de ventas del día (con listas).
Cálculo de total vendido.
Guardar ventas en archivo.
Leer ventas de archivo.
Mostrar ventas en pantalla.
*/
/*Este va a ser un trabajo final integrador
Debo crear un punto de registro de ventas de un kiosco, teniendo en cuenta todo lo dado hasta ahora
Arreglo de productos, con precios y stock.
Registro de ventas del dia (con listas).
Calculo de total vendido.
Guardar ventas en archivo.
Leer ventas de archivo.
Mostrar ventas en pantalla.
*/
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_PRODUCTOS 100
#define MAX_VENTAS 100

#define ARCHIVO_VENTAS "ventas.dat"
#define ARCHIVO_TXT_PRODUCTOS "productos.txt"

// Estructura de productos
typedef struct {
    char nombre[50];
    float precio;
    int stock;
} Producto;

// Estructura de ventas
typedef struct {
    char nombre[50];
    int cantidad;
    float precio;
} Venta;

// Lista de ventas del dia
typedef struct {
    Venta ventas[MAX_VENTAS];
    int totalVentas;
} RegistroVentas;

// Leer productos desde productos.txt
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
            productos[*cantidadProductos].precio = atof(precioStr);
            productos[*cantidadProductos].stock = atoi(stockStr);
            (*cantidadProductos)++;
        }
    }

    fclose(archivo);
    printf("Productos cargados desde productos.txt correctamente.\n");
}

// Exportar productos actualizados a productos.txt
void exportarProductosATexto(Producto productos[], int cantidadProductos) {
    FILE *archivo = fopen(ARCHIVO_TXT_PRODUCTOS, "w");
    if (archivo == NULL) {
        printf("No se pudo crear el archivo de texto de productos.\n");
        return;
    }

    for (int i = 0; i < cantidadProductos; i++) {
        fprintf(archivo, "%s,%.2f,%d\n",
                productos[i].nombre,
                productos[i].precio,
                productos[i].stock);
    }

    fclose(archivo);
    printf("Archivo productos.txt actualizado.\n");
}

// Mostrar productos en consola
void mostrarProductos(Producto productos[], int cantidadProductos) {
    printf("\nProductos en stock:\n");
    for (int i = 0; i < cantidadProductos; i++) {
        printf("%d. %s - Precio: $%.2f - Stock: %d\n",
               i + 1,
               productos[i].nombre,
               productos[i].precio,
               productos[i].stock);
    }
}

// Registrar una venta
void registrarVenta(Producto productos[], int cantidadProductos, RegistroVentas *registro) {
    Venta venta;
    printf("Ingrese el nombre del producto: ");
    scanf("%s", venta.nombre);
    printf("Ingrese la cantidad vendida: ");
    scanf("%d", &venta.cantidad);

    for (int i = 0; i < cantidadProductos; i++) {
        if (strcmp(productos[i].nombre, venta.nombre) == 0) {
            if (productos[i].stock >= venta.cantidad) {
                productos[i].stock -= venta.cantidad;
                venta.precio = productos[i].precio * venta.cantidad;
                registro->ventas[registro->totalVentas++] = venta;

                printf("Venta registrada: %s - Cantidad: %d - Total: $%.2f\n",
                       venta.nombre, venta.cantidad, venta.precio);
            } else {
                printf("Stock insuficiente.\n");
            }
            return;
        }
    }

    printf("Producto no encontrado.\n");
}

// Mostrar todas las ventas del dia
void mostrarVentas(RegistroVentas *registro) {
    printf("\nVentas del dia:\n");
    float totalGeneral = 0.0;
    for (int i = 0; i < registro->totalVentas; i++) {
        printf("%d. %s - Cantidad: %d - Total: $%.2f\n",
               i + 1,
               registro->ventas[i].nombre,
               registro->ventas[i].cantidad,
               registro->ventas[i].precio);
        totalGeneral += registro->ventas[i].precio;
    }
    printf("TOTAL VENDIDO: $%.2f\n", totalGeneral);
}

// Guardar ventas en archivo binario
void guardarVentas(RegistroVentas *registro) {
    FILE *archivo = fopen(ARCHIVO_VENTAS, "wb");
    if (archivo == NULL) {
        printf("No se pudo abrir archivo de ventas.\n");
        return;
    }

    fwrite(registro, sizeof(RegistroVentas), 1, archivo);
    fclose(archivo);
    printf("Ventas guardadas en %s.\n", ARCHIVO_VENTAS);
}

// Leer ventas desde archivo binario
void leerVentas(RegistroVentas *registro) {
    FILE *archivo = fopen(ARCHIVO_VENTAS, "rb");
    if (archivo == NULL) {
        printf("No se pudo abrir archivo de ventas.\n");
        return;
    }

    fread(registro, sizeof(RegistroVentas), 1, archivo);
    fclose(archivo);
}
// Funcion menu
int mostrarMenu() {
    Producto productos[MAX_PRODUCTOS];
    int cantidadProductos = 0;
    RegistroVentas registroVentas;
    registroVentas.totalVentas = 0;

    cargarProductosDesdeTxt(productos, &cantidadProductos);

    if (cantidadProductos == 0) {
        printf("No hay productos cargados. Finalizando.\n");
        return 1;
    }
    int opcion;
    do {
        printf("\n--- MENU PRINCIPAL ---\n");
        printf("1. Mostrar productos\n");
        printf("2. Registrar venta\n");
        printf("3. Mostrar ventas del dia\n");
        printf("4. Guardar ventas y actualizar productos\n");
        printf("5. Salir\n");
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
                printf("Cerrando programa. ¡Hasta luego!\n");
                break;
            default:
                printf("Opcion no valida.\n");
        }
    } while (opcion != 5);
}
// Menu principal
int main() {
    printf("Bienvenido al Kiosco!\n");
    printf("Cargando productos desde archivo...\n");

    mostrarMenu();

    return 0;
}

