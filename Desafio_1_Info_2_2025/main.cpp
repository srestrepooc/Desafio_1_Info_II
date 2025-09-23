#include <iostream>
using namespace std;

// Función para rotar bits a la derecha
unsigned char rotarDerecha(unsigned char valor, int n) {
    return (valor >> n) | (valor << (8 - n));
}

int main() {
    // Paso 1: Arreglo original dinámico
    int n = 9;
    char* arr = new char[n]{'r','r','e','n','o','s','d','e','s'};

    // Paso 2: RLE - Contar repeticiones
    int maxTam = n * 2; // como máximo, cada letra con su conteo
    char* letras = new char[maxTam];
    int* conteo = new int[maxTam];
    int k = 0;

    for (int i = 0; i < n; ) {
        char actual = arr[i];
        int count = 1;
        while (i + 1 < n && arr[i+1] == actual) {
            count++;
            i++;
        }
        letras[k] = actual;
        conteo[k] = count;
        k++;
        i++;
    }

    // Paso 3: Mostrar RLE original
    cout << "RLE original:" << endl;
    for (int i = 0; i < k; i++) {
        cout << conteo[i] << letras[i] << " ";
    }
    cout << endl << endl;

    // Paso 4: Rotar 3 bits a la derecha y luego aplicar XOR con 0x5A
    cout << "Resultado tras rotacion y XOR (ASCII):" << endl;
    for (int i = 0; i < k; i++) {
        // Convertimos letra a unsigned char
        unsigned char letra = letras[i];

        // Rotacion 3 bits derecha
        unsigned char rotada = letra ^ 0x5A;

        // XOR con 0x5A
        unsigned char resultado =  rotarDerecha(letra, 3);



        // Imprimir: cantidad + caracter transformado
        cout << conteo[i] << (char)resultado << " ";
    }
    cout << endl;

    // Liberar memoria
    delete[] arr;
    delete[] letras;
    delete[] conteo;

    return 0;
}

