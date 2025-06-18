#ifndef VENTA_H
#define VENTA_H

#define MAX_VENTAS 100

#include "producto.h"  // Para usar la estructura Producto

typedef struct {
    char nombre[50];
    int cantidad;
    int precio;
} Venta;

typedef struct {
    Venta ventas[MAX_VENTAS];
    int totalVentas;
} RegistroVentas;

void registrarVenta(Producto productos[], int cantidadProductos, RegistroVentas *registro);
void mostrarVentas(RegistroVentas *registro);
void guardarVentas(RegistroVentas *registro);
void leerVentas(RegistroVentas *registro);

#endif
