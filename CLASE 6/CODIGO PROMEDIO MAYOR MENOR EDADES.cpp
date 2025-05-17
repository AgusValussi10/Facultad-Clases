#include <stdio.h>
#include <stdbool.h>

int main()
{
	int calif, suma = 0, contador = 0;
	
	int calif_min = 2147483647;  // Valor inicial alto para encontrar el mínimo
	int calif_max = -2147483648; // Valor inicial bajo para encontrar el máximo
	
	printf("Ingrese las calificaciones una por una (ingrese -1 para finalizar):\n");
	
	bool continuar = true;
	
	while (continuar)
	{
		printf("Calificacion: ");
		scanf("%d", &calif);
		
		if (calif < 0 && calif != -1)
		{
			printf("Error: La calificacion no puede ser negativa. Intente nuevamente.\n");
		}
		if (calif > 10)
		{
			printf("Error: La calificacion no puede ser mayor a 10. Intente nuevamente.\n");
		}
		else if (calif == (-1))
		{
			continuar = false;
		}
		else
		{
			// Calculos para el resultado:
			suma += calif;
			contador++;
		}
	}
	
	if (contador > 0)
	{
		float promedio = (float)suma / contador;
		printf("El promedio de calificaciones: %.2f\n", promedio);
	}
	
	return 0;
}
