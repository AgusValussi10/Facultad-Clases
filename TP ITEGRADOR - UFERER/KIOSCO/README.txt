============================
REGISTRO DE VENTAS - KIOSCO
============================

Este programa en lenguaje C permite gestionar un punto de venta para un kiosco, incluyendo productos, ventas, stock y administración.

----------------------------
📂 ESTRUCTURA DE CARPETAS
----------------------------

- MAIN.c ....................... Archivo principal
- productos.txt ............... Archivo de texto con los productos
- SRC/
    ├── .C/ .................... Archivos fuente (.c)
    └── .H/ .................... Archivos de cabecera (.h)

----------------------------
⚙️ FUNCIONALIDADES
----------------------------

✔ Ver productos disponibles
✔ Registrar ventas del día
✔ Mostrar ventas realizadas
✔ Guardar ventas en archivo
✔ Editar o agregar productos desde menú administrativo
✔ Cálculo automático de stock y total vendido
✔ Buscar producto por nombre o número
✔ Precios trabajados como ENTEROS (sin decimales)

----------------------------
💻 CÓMO COMPILAR
----------------------------

Abrir terminal en la carpeta principal y ejecutar:

    gcc MAIN.c SRC/.C/producto.c SRC/.C/venta.c SRC/.C/administracion.c SRC/.C/menu.c -o kiosco.exe

Esto genera el archivo ejecutable `kiosco.exe`.

----------------------------
▶️ CÓMO EJECUTAR
----------------------------

Desde la terminal:

    ./kiosco.exe

O haciendo doble clic en el archivo `kiosco.exe`.

⚠ Asegurate de tener `productos.txt` en la misma carpeta que el ejecutable.

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
👨‍💻 AUTOR
----------------------------

Trabajo Práctico Integrador - Programación I

Realizado por: [Tu nombre aquí]
Fecha: Junio 2025
