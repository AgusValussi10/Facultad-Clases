#include <stdio.h>
using namespace std;

int main(){
int A [7];
int c,acum;

	for (c=0; c<7 ; c++){
	printf ("ingrese un valor entero\n");
	scanf ("%d", &A[c]);
}
	acum=0;
for (c=0; c<7 ;c++){
	printf ("Elemento %i :%i\n", c,A[c]);
	acum=acum+ A[c];
	
}
printf ("Sumatoria =%d\n", acum);
	return 0;
}
