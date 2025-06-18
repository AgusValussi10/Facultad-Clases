#ifndef PRODUCTO_H
#define PRODUCTO_H

#define MAX_PRODUCTOS 100

typedef struct { // Estructura para representar un producto
    char nombre[50];
    int precio;
    int stock;
} Producto;

void cargarProductosDesdeTxt(Producto productos[], int *cantidadProductos);
// Funcion que carga los productos desde un archivo de texto y actualiza la cantidad de productos
void exportarProductosATexto(Producto productos[], int cantidadProductos);
// Funcion que exporta los productos a un archivo de texto
void mostrarProductos(Producto productos[], int cantidadProductos);
// Funcion que muestra todos los productos disponibles
int buscarProducto(Producto productos[], int cantidadProductos, char *entrada);
// Funcion que busca un producto por nombre y devuelve su indice, o -1 si no se encuentra
void editarProducto(Producto productos[], int *cantidadProductos);
// Funcion que permite editar un producto existente, actualizando su nombre, precio o stock

#endif
