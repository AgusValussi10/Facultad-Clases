// Cuál es el resultado de esta función para distintos valores de X? 

#include <iostream>

using namespace std;

// Definición de la función f
int f(int x) {
    if (x > 100) {
        return x - 10;
    } else {
        return f(f(x + 11));
    }
}

int main() {
    // Probar la función con varios valores
    int valores[] = {50, 75, 90, 95, 100, 101, 102, 110};
    int n = sizeof(valores) / sizeof(valores[0]);

    cout << "Resultados de la funcion f(x):" << endl;
    for (int i = 0; i < n; i++) {
        int x = valores[i];
        cout << "f(" << x << ") = " << f(x) << endl;
    }

    return 0;
}

