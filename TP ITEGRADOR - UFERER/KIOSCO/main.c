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
#include <ctype.h>

#include "./SRC/.H/producto.h" // para usar Producto, y las funciones de producto
#include "./SRC/.H/venta.h"   // para usar RegistroVentas y las funciones de venta
#include "./SRC/.H/administracion.h" // para usar menuAdministrativo
#include "./SRC/.H/menu.h" // para usar menu

#define MAX_PRODUCTOS 100
#define MAX_VENTAS 100

#define ARCHIVO_VENTAS "ventas.dat"
#define ARCHIVO_TXT_PRODUCTOS "productos.txt"

int main() {
    printf("Bienvenido al Kiosco\n");
    menu();
    return 0;
}


