#ifndef PRODUCTO_H
#define PRODUCTO_H

#define MAX_PRODUCTOS 100

typedef struct {
    char nombre[50];
    int precio;
    int stock;
} Producto;

void cargarProductosDesdeTxt(Producto productos[], int *cantidadProductos);
void exportarProductosATexto(Producto productos[], int cantidadProductos);
void mostrarProductos(Producto productos[], int cantidadProductos);
int buscarProducto(Producto productos[], int cantidadProductos, char *entrada);
void editarProducto(Producto productos[], int *cantidadProductos);

#endif
