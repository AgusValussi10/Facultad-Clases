#ifndef VENTA_H
#define VENTA_H

#define MAX_VENTAS 100

#include "producto.h"  // Para usar la estructura Producto

typedef struct { // Estructura para representar una venta
    char nombre[50];
    int cantidad;
    int precio;
} Venta;

typedef struct { // Estructura para registrar las ventas
    Venta ventas[MAX_VENTAS];
    int totalVentas;
} RegistroVentas;

void registrarVenta(Producto productos[], int cantidadProductos, RegistroVentas *registro);
// Funcion que permite registrar una venta, actualizando el stock del producto y guardando la venta en el registro
void mostrarVentas(RegistroVentas *registro);
// Funcion que muestra todas las ventas registradas
void leerVentas(RegistroVentas *registro);
// Funcion que lee las ventas desde un archivo y las carga en el registro
void guardarVentas(RegistroVentas *registro);
// Funcion que guarda las ventas en un archivo

#endif
