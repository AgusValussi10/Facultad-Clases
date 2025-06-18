// ESTE SCRIPT ES UNA FORMA DE COMPILAR EL PROGRAMA KIOSCO
// EL SCRIPT DEBE ESTAR EN LA RAIZ DEL PROYECTO
// EL PROYECTO DEBE TENER LA ESTRUCTURA DE CARPETAS CORRECTA

@echo off
cls
:: Compilar el programa
gcc MAIN.c SRC\.C\producto.c SRC\.C\venta.c SRC\.C\administracion.c SRC\.C\menu.c -o kiosco.exe

:: Verificar si la compilación fue exitosa
if exist kiosco.exe (
    echo Compilacion exitosa. Ejecutando el programa...
    kiosco.exe
) else (
    echo Error en la compilacion.
)

pause
