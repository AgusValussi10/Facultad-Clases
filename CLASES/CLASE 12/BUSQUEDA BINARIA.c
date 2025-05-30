#include <cstdio>      // Para printf y scanf
#include <vector>      // Para std::vector
#include <algorithm>   // Para std::sort

int busquedaBinaria(const std::vector<int>& arreglo, int objetivo) {
	int izquierda = 0;
	int derecha = arreglo.size() - 1;
	
	while (izquierda <= derecha) {
		int medio = izquierda + (derecha - izquierda) / 2;
		
		if (arreglo[medio] == objetivo)
			return medio;
		else if (arreglo[medio] < objetivo)
			izquierda = medio + 1;
		else
			derecha = medio - 1;
	}
	
	return -1;
}

int main() {
	int n, objetivo;
	
	printf("Ingrese el tama�o del arreglo: ");
	scanf("%d", &n);
	
	std::vector<int> arreglo(n);
	
	printf("Ingrese %d elementos (NO es necesario que est�n ordenados):\n", n);
	for (int i = 0; i < n; ++i) {
		scanf("%d", &arreglo[i]);
	}
	
	// Ordenar el arreglo antes de buscar
	std::sort(arreglo.begin(), arreglo.end());
	
	printf("Ingrese el n�mero a buscar: ");
	scanf("%d", &objetivo);
	
	int resultado = busquedaBinaria(arreglo, objetivo);
	if (resultado != -1)
		printf("Elemento encontrado en el �ndice (ordenado): %d\n", resultado);
	else
		printf("Elemento no encontrado.\n");
	
	return 0;
}
