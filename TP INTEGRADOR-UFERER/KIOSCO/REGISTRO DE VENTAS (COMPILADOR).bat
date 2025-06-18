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
