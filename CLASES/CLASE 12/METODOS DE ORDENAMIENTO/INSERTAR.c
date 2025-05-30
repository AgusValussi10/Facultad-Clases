#include <stdio.h>
#include <conio.h>
# define final 10

int main()
{
	
	int lista[10]= {0, 4, 78, 75, 82, 90, 97, 100, 123};
	int i,ult,n;
	
	ult=0;
	i=0;
	while(i < final && lista[i]!= 0)
	{
		printf("Digito %d:%d\n",i,lista[i]);
		ult++;
		i++;
	}
	
	if (final==ult) printf("No se puede insertar un elemento\n");
	else
		{
			printf("Ingrese un valor a inserta en el arreglo\n");
			scanf("%d",&n);	
		}
        
	    if  (n<lista[0])printf("Insertar como primer elemento del arreglo\n");
		else
			if  (n >lista[ult])printf("Insertar como {ultimo elemento del arreglo\n");
	            else printf("Insertar al medio del arreglo\n");
	
	return 0;
}
