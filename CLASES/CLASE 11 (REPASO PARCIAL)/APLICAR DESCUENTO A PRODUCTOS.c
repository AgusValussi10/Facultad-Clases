// Una farmacia hace el 15% de descuento sobre los precios de la lista oficial.
// Hacer un programa que permita ingresar por teclado el precio de lista de un determinado articulo y la cantidad de unidades compradas por el cliente.
// Luego caluclar e informar por pantalla el total a pagar aplicando el descuento en efectivo.

#include <cstdio>
#include <stdio.h>
int main() {
	
	float cantarticulos = 0;
	float precioproducto, cantproductos, totalsindesc, totalcondesc;
	printf("Este es un programa que calcula el precio final a pagar con el descuento aplicado por PAGO EFECTIVO\n");
	printf("\n");
	printf("Ingrese la cantidad de distintos productos que usted lleva: ");
	scanf("%f", &cantarticulos);
	
	for (int i = 1 ; i <= cantarticulos ; i++){
		printf("\nIngrese el precio del %d� producto: $", i);
		scanf("%f", &precioproducto);
		printf("Ingrese la cantidad de unidades que lleva de este producto: ");
		scanf("%f", &cantproductos);
		totalsindesc = totalsindesc + (cantproductos * precioproducto);
	}
	
	printf("\nTotal sin descuento = $%.2f", totalsindesc);
	totalcondesc = totalsindesc - (totalsindesc * 0.15);
	printf("\nTotal con descuento = $%.2f", totalcondesc);
	
	return 0;
}
