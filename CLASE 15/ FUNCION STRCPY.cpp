#include<stdio.h>
#include<string.h>
#include<conio.h>

int main (){
	char texto1[] = "Corta";
	char texto2[] = "Medina";
	char texto3[] = "Larguisima";
	strcpy(texto2,texto1);
	printf("%s\n", texto2);
	strcpy(texto2,texto3);
	printf("%s\n", texto2);
	getch();
	
	return 0;
}
