#include <stdio.h>
#include <conio.h>

int suma(int a, int b);
int resta(int a, int b);

int main() {
	
	int x, y, z;
	printf("Ingrese un numero a utilizar: ");
	scanf("%d", &x);
	printf("Ingrese otro numero a utilizar: ");
	scanf("%d", &y);
	
	/*z = suma(x,y);*/
	printf("\nLa suma entre %d + %d es: %d", x, y, z = suma (x,y));
	/*z = resta(x,y);*/
	printf("\nLa resta entre %d - %d es: %d", x, y, z = resta (x,y));
	
	getch();
	return 0;
}

int suma (int a, int b){
	int total;
	total = a+b;
	return total;
}
int resta (int a, int b){
	int total;
	total = a-b;
	return total;
}
