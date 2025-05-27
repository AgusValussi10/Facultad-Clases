// Dado un arreglo de estructuras que tiene los siguiente elementos, numero de producto, 
// nombre del producto, cantidad de productos en stock, se pide:

// A- Cargar el arreglo de estructura.
// B- ordenar el arreglo o número de producto.
// C- ingresar un número de producto por teclado e indicar si esta en arreglo.
// D- mostrar el contenido de arreglo de estructura.

#include <stdio.h>
#define MAX 3

struct Producto
{
 int codigo;
 char nombre[20];
 int stock;
};

void ordenarPorCodigo(struct Producto arr[], int n);
void mostrarArreglo(struct Producto arr[], int n);
int buscarPorCodigo(struct Producto arr[], int n, int codigo);

int main() {
    int i,busqueda,pos;
    struct Producto p[MAX];
    for (i=0;i<MAX;i++){
        printf("Ingresar el codigo del producto:");
        scanf("%d",&p[i].codigo);
        printf("Ingresar el nombre del producto:");
        scanf("%s",&p[i].nombre);
        printf("Ingresar el stock del producto:");
        scanf("%d",&p[i].stock);    
    }
    mostrarArreglo(p, MAX);
    ordenarPorCodigo(p, MAX);
    printf("Ordenado por codigo\n");
    mostrarArreglo(p, MAX);
   
    printf("\nIngrese el código a buscar: ");
    scanf("%d", &busqueda);

    pos = buscarPorCodigo(p, MAX, busqueda);

    if (pos != -1) {
        printf("\nProducto encontrado:\n");
        printf("Código: %d - Nombre: %s - Stock: %d\n", 
               p[pos].codigo, p[pos].nombre, p[pos].stock);
    } else {
        printf("\nProducto con código %d no encontrado.\n", busqueda);
    }

    return 0;
}


void ordenarPorCodigo(struct Producto arr[], int n) {
    struct Producto temp;
    for (int i = 0; i < n - 1; i++) {
        for (int j = 0; j < n - 1 - i; j++) {
            if (arr[j].codigo > arr[j + 1].codigo) {
                temp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = temp;
            }
        }
    }
}

void mostrarArreglo(struct Producto arr[], int n) {
    int i;
    printf("\nListado de Productos\n");
    printf("%-10s %-20s %-10s \n", "Codigo", "Nombre", "Stock");
    for (i = 0; i < n; i++) {
        printf("%-10d %-20s %-10d \n", arr[i].codigo, arr[i].nombre, arr[i].stock);
    }
}

int buscarPorCodigo(struct Producto arr[], int n, int codigo) {
    int inicio = 0, fin = n - 1, medio;

    while (inicio <= fin) {
        medio = (inicio + fin) / 2;
        if (arr[medio].codigo == codigo) {
            return medio;
        } else if (arr[medio].codigo < codigo) {
            inicio = medio + 1;
        } else {
            fin = medio - 1;
        }
    }

return-1;
}