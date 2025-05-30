#include <stdio.h>

// Declaraciones de funciones
int resta(int minuendo, int sustraendo);
float division(int dividendo, int divisor);
int potencia(int base, int exponente);
int factorial(int nro);
void tablaDeMultiplicar(int nro);
void sumar();
void multiplicar();

void mostrarMenu(); // Funcion para el Menu
void operaciones(); // Funcion para Operaciones
void principal();

int main() {
	
	principal();
	
	return 0;
}

// Principal (main fuera del main)
void principal() {
	char seguir;
	
	do {
		mostrarMenu();
		operaciones();
		
		printf("\n¿Desea realizar otra operación? (s/n): ");
		scanf(" %c", &seguir);  // Espacio antes de %c para ignorar el enter anterior
		
	} while (seguir == 's' || seguir == 'S');
	
	printf("¡Gracias por usar el programa!\n");
}
// Mostrar menu
void mostrarMenu() {
	printf("\n----- MENU DE OPERACIONES -----\n");
	printf("1. Resta\n");
	printf("2. División\n");
	printf("3. Potencia\n");
	printf("4. Factorial\n");
	printf("5. Tabla de multiplicación\n");
	printf("6. Suma de varios números\n");
	printf("7. Multiplicación de varios números\n");
	printf("--------------------------------\n");
}
// Operaciones
void operaciones(){
	int opcion;
	printf("Ingrese la operación que desea realizar (1-7): ");
	scanf("%d", &opcion);
	
	switch (opcion) {
	case 1: {
		int a, b;
		printf("Ingrese el minuendo: ");
		scanf("%d", &a);
		printf("Ingrese el sustraendo: ");
		scanf("%d", &b);
		printf("Resultado: %d\n", resta(a, b));
		break;
	}
	case 2: {
		int a, b;
		printf("Ingrese el dividendo: ");
		scanf("%d", &a);
		printf("Ingrese el divisor: ");
		scanf("%d", &b);
		printf("Resultado: %.2f\n", division(a, b));
		break;
	}
	case 3: {
		int base, exponente;
		printf("Ingrese la base: ");
		scanf("%d", &base);
		printf("Ingrese el exponente: ");
		scanf("%d", &exponente);
		printf("Resultado: %d\n", potencia(base, exponente));
		break;
	}
	case 4: {
		int nro;
		printf("Ingrese el número: ");
		scanf("%d", &nro);
		printf("Resultado: %d\n", factorial(nro));
		break;
	}
	case 5: {
		int nro;
		printf("Ingrese el número: ");
		scanf("%d", &nro);
		tablaDeMultiplicar(nro);
		break;
	}
	case 6:
		sumar();
		break;
	case 7:
		multiplicar();
		break;
	default:
		printf("Opción inválida.\n");
	}
}


// Operacion Resta
int resta(int minuendo, int sustraendo) {
	return minuendo - sustraendo;
}


// Operacion Division
float division(int dividendo, int divisor) {
	if (divisor == 0) {
		printf("?? Error: No se puede dividir por cero.\n");
		return 0;
	}
	return (float)dividendo / divisor;
}



// Operacion Potencia
int potencia(int base, int exponente) {
	int resultado = 1;
	
	for (int i = 0; i < exponente; i++) {
		resultado *= base;
	}
	
	return resultado;
}




// Operacion Factorial
int factorial(int nro) {
	int resultado = 1;
	
	if (nro < 0) {
		printf("?? Error: el factorial no está definido para números negativos.\n");
		return 1;
	}
	
	for (int i = 1; i <= nro; i++) {
		resultado *= i;
	}
	
	return resultado;
}



// Operacion Tabla de Multiplicar
void tablaDeMultiplicar(int nro) {
	printf("Tabla de multiplicar del %d:\n", nro);
	for (int i = 1; i <= 10; i++) {
		printf("%d x %d = %d\n", nro, i, nro * i);
	}
}

// Operacion Sumar
void sumar() {
	int cantidad;
	printf("¿Cuántos números desea sumar?: ");
	scanf("%d", &cantidad);
	
	int numero, suma = 0;
	
	for (int i = 1; i <= cantidad; i++) {
		printf("Ingrese el número %d: ", i);
		scanf("%d", &numero);
		suma += numero;
	}
	
	printf("Resultado de la suma: %d\n", suma);
}


// Operacion Multiplicar 
void multiplicar() {
	int cantidad;
	printf("¿Cuántos números desea multiplicar?: ");
	scanf("%d", &cantidad);
	
	int numero;
	int producto = 1;
	
	for (int i = 1; i <= cantidad; i++) {
		printf("Ingrese el número %d: ", i);
		scanf("%d", &numero);
		producto *= numero;
	}
	
	printf("Resultado de la multiplicación: %d\n", producto);
}
