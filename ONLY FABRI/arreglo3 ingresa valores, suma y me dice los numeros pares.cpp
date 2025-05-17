#include <stdio.h>
using namespace std;

int main(){
int A [7];
int c,acum,d;

d=0;
	while (d<7){
	printf ("ingrese un valor entero multiplo de 3\n");
	scanf ("%d", &A[c]);
	
	if (A[c] / 3!=0){
		printf ("error, ingrese un valor multiplo de 3");
		printf ("Ingrese nuevamente un numero");
		}
	else {
		(A[c] % 3 ==0);
		scanf ("%d", &A[c]);
	d++;
	}
	

	}
	return 0;
}
