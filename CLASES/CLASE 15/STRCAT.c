#include<stdio.h>
#include<string.h>

int main (){
	char texto1[] = "Don Pepito";
	char texto2[] = " y ";
	char texto3[] = "Don Jose";
	printf("%s\n", texto1);
	strcat(texto1,texto2);
	printf("%s\n", texto1);
	strcat(texto1,texto3);
	printf("%s\n", texto1);
	
	return 0;
}
