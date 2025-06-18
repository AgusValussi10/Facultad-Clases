#ifndef ADMINISTRACION_H
#define ADMINISTRACION_H

#include "producto.h"  // Necesario para usar Producto

void menuAdministrativo(Producto productos[], int *cantidadProductos);
// Funcion que muestra el menu administrativo y permite editar, agregar, ver stock bajo o eliminar productos

void mostrarStockBajo(Producto productos[], int cantidadProductos);
// Funcion que muestra los productos con stock bajo (menos de 5 unidades)

void eliminarProducto(Producto productos[], int *cantidadProductos);
// Funcion que permite eliminar un producto del inventario y actualiza la cantidad de productos disponibles



#endif
