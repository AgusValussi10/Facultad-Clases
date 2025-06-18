#include <stdio.h> // para usar printf, scanf
#include <stdlib.h> // para usar system, exit
#include <string.h> // para usar strcmp, strcpy, fgets, strcspn
#include <ctype.h>  // para usar isdigit, isalpha (busqueda por numero o nombre)

#include "./SRC/.H/producto.h" // para usar Producto, y las funciones de producto
#include "./SRC/.H/venta.h"   // para usar RegistroVentas y las funciones de venta
#include "./SRC/.H/administracion.h" // para usar menuAdministrativo
#include "./SRC/.H/menu.h" // para usar Menu

#define MAX_PRODUCTOS 100
#define MAX_VENTAS 100

#define ARCHIVO_VENTAS "ventas.dat"
#define ARCHIVO_TXT_PRODUCTOS "productos.txt"

int main() {
    printf("Bienvenido al Kiosco\n");
    menu();
    return 0;
}


