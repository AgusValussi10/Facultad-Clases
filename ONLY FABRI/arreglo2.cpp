#include <stdio.h>
using namespace std;

int main(){
int A [7];
int c,acum,d;

	for (c=0; c<7 ; c++){
	printf ("ingrese un valor entero\n");
	scanf ("%d", &A[c]);
}
	acum=0;
	d=0;
for (c=0; c<7 ;c++){
	printf ("Elemento %i :%i\n", c,A[c]);
	acum=acum+ A[c];
	if (A[c] %2==0){
		d++;
	}
	
}
printf ("Sumatoria =%d\n", acum);
if (d == 0){
	printf ("no hay numeros pares");
}
else 
	{ printf ("\nPares = %d\n", d);
}
	return 0;
}
