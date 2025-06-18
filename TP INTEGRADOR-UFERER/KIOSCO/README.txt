============================
REGISTRO DE VENTAS - KIOSCO
============================

Este programa en lenguaje C permite gestionar un punto de venta para un kiosco, incluyendo productos, ventas, stock y administración.

----------------------------
📂 ESTRUCTURA DE CARPETAS
----------------------------
- KIOSCO
-   |---- SRC/
    |     ├── .C/ .................... Archivos fuente (.c) // Contienen funciones, lógica del programa, main(), etc.
    |     └── .H/ .................... Archivos de cabecera (.h) // Contienen declaraciones: prototipos de funciones, constantes y estructuras.
-   |─ MAIN.c ....................... Archivo principal
-   |─ productos.txt ............... Archivo de texto con los productos
-   |─ RESGISTRO DE VENTAS (COMPILADOR )..... Script para ejecutar programa mas facil
- MEJORAS.txt .................. Archivo que describe mejoras con respecto al programa base
- PLANIFICACION.pdf ............ Archivo que describe el paso a paso seguido para desarrollar el programa

----------------------------
⚙️ FUNCIONALIDADES
----------------------------

✔ Ver productos disponibles
✔ Registrar ventas del día
✔ Mostrar ventas realizadas
✔ Guardar ventas en archivo
✔ Editar o agregar productos desde menú administrativo
✔ Cálculo automático de stock y total vendido
✔ Comprobar Stock de productos, ver los de stock bajo
✔ Buscar producto por nombre o número
✔ Editar Stock y Precio desde el programa
✔ Eliminar productos
✔ Precios trabajados como ENTEROS (sin decimales)

----------------------------
💻 CÓMO COMPILAR
----------------------------

Abrir terminal en la carpeta principal y ejecutar:

    gcc main.c ./SRC/.C/administracion.c ./SRC/.C/menu.c ./SRC/.C/producto.c ./SRC/.C/venta.c -o kiosco.exe

Esto genera el archivo ejecutable `kiosco.exe`.

----------------------------
▶️ CÓMO EJECUTAR
----------------------------

Desde la terminal, a continuacion de ejectuar el comando anterior:

    ./kiosco.exe

O haciendo doble clic en el archivo `kiosco.exe`.

⚠ Asegurate de tener `productos.txt` en la misma carpeta que el ejecutable.

⚠ Como segunda opcion se puede EJECUTAR desde el archivo REGISTRO DE VENTAS (COMPILADOR)
Este es un archivo .bat (script) que ahorra los pasos de hacerlo por la terminal.

----------------------------
📁 ARCHIVO DE PRODUCTOS
----------------------------

El archivo `productos.txt` tiene el siguiente formato:

    nombre,precio,stock

Ejemplo:

    Galletitas,120,30
    CocaCola,500,10
    Agua,300,15

----------------------------
👨‍💻 AUTORES
----------------------------

Trabajo Práctico Integrador - Programación I

Realizado por:  © Fabrizio Rios
                © Agustin Valussi
Fecha: Junio 2025
