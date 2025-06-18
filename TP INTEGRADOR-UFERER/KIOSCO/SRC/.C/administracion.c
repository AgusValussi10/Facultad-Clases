#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "../.H/administracion.h" // Para incluir las declaraciones de funciones y constantes
#include "../.H/producto.h" // Para incluir la estructura Producto y funciones relacionadas

void menuAdministrativo(Producto productos[], int *cantidadProductos) {
    int opcion;
    do {
        printf("\n--- MENU ADMINISTRATIVO ---\n");
        printf("1. Editar producto existente\n");
        printf("2. Agregar nuevo producto\n");
        printf("3. Ver productos con stock bajo\n");
        printf("4. Eliminar producto\n");  
        printf("5. Volver al menu principal\n");  
        scanf("%d", &opcion);

        if (opcion == 1) {
            char entrada[50];
            printf("Ingrese nombre o numero del producto: ");
            scanf("%s", entrada);

            int indice = buscarProducto(productos, *cantidadProductos, entrada);

            if (indice == -1) {
                printf("Producto no encontrado.\n");
                continue;
            }

            int subopcion;
            printf("Menu de edicion:\n");
            printf("Ingrese que desea editar:\n");
            printf("1-Precio / 2-Stock: ");
            scanf("%d", &subopcion);

            if (subopcion == 1) {
                float nuevoPrecio;
                printf("Ingrese nuevo precio: ");
                scanf("%f", &nuevoPrecio);
                productos[indice].precio = nuevoPrecio;
                printf("Precio actualizado.\n");
            } else if (subopcion == 2) {
                int nuevoStock;
                printf("Ingrese nuevo stock: ");
                scanf("%d", &nuevoStock);
                productos[indice].stock = nuevoStock;
                printf("Stock actualizado.\n");
            } else {
                printf("Opcion invalida.\n");
            }

        } else if (opcion == 2) {
            if (*cantidadProductos >= MAX_PRODUCTOS) {
                printf("No se pueden agregar mas productos.\n");
                continue;
            }

            Producto nuevo;
            printf("Ingrese nombre del nuevo producto: ");
            scanf("%s", nuevo.nombre);

            for (int i = 0; i < *cantidadProductos; i++) {
                if (strcmp(productos[i].nombre, nuevo.nombre) == 0) {
                    printf("El producto ya existe.\n");
                    continue;
                }
            }

            printf("Ingrese precio: ");
            scanf("%f", &nuevo.precio);
            printf("Ingrese stock: ");
            scanf("%d", &nuevo.stock);

            productos[*cantidadProductos] = nuevo;
            (*cantidadProductos)++;

            printf("Producto agregado correctamente.\n");

        } else if (opcion == 3) {
            mostrarStockBajo(productos, *cantidadProductos);
        } else if (opcion == 4) {
            eliminarProducto(productos, cantidadProductos);
        }
        else if (opcion == 5){
            break;
        } else {
            printf("Opcion invalida.\n");
        }
    } while (opcion != 5);
}

void mostrarStockBajo(Producto productos[], int cantidadProductos) {
    printf("\n--- PRODUCTOS CON STOCK BAJO (< 5) ---\n");
    int encontrados = 0;
    for (int i = 0; i < cantidadProductos; i++) {
        if (productos[i].stock < 5) {
            printf("%d. %s - Stock: %d\n", i + 1, productos[i].nombre, productos[i].stock);
            encontrados++;
        }
    }
    if (encontrados == 0) {
        printf("Todos los productos tienen stock suficiente.\n");
    }
    // Limpieza de buffer para evitar problemas con getchar
    printf("Presione ENTER para continuar...");
    while (getchar() != '\n');
    getchar();
    system("cls"); // Limpiar pantalla para una mejor visualización
}

void eliminarProducto(Producto productos[], int *cantidadProductos) {
    char nombre[50];
    int encontrado = 0;

    printf("Ingrese el nombre del producto a eliminar: ");
    fflush(stdin); // Limpio el buffer de entrada (fflush(stdin))

    fgets(nombre, sizeof(nombre), stdin);
    nombre[strcspn(nombre, "\n")] = 0; // strcspn para eliminar el salto de línea

    for (int i = 0; i < *cantidadProductos; i++) {
        if (strcmp(productos[i].nombre, nombre) == 0) { // strcmp para comparar cadenas
            for (int j = i; j < *cantidadProductos - 1; j++) {
                productos[j] = productos[j + 1];
            } // Desplazar productos hacia la izquierda
            (*cantidadProductos)--;
            printf("Producto eliminado correctamente.\n");
            encontrado = 1;
            break;
        }
    }

    if (!encontrado) {
        printf("Producto no encontrado.\n");
    }
}

