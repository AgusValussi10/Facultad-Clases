#ifndef ADMINISTRACION_H
#define ADMINISTRACION_H

#include "producto.h"  // Necesario para usar Producto

void menuAdministrativo(Producto productos[], int *cantidadProductos);
// Funcion que muestra el menu de opciones al usuario
void mostrarStockBajo(Producto productos[], int cantidadProductos);
// Funcion que muestra los productos con stock bajo
void eliminarProducto(Producto productos[], int *cantidadProductos);
// Funcion que elimina un producto del inventario


#endif
