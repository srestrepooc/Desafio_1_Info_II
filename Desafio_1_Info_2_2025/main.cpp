#include <iostream>
#include <fstream>
using namespace std;

// Funciones para desencriptar el archivo txt
unsigned char bits_derecha(unsigned char valor, int n) {
    return (valor >> n) | (valor << (8 - n));
}
unsigned char XOR_char(char x){
    return x ^ 0x5A;
}


int main() {
    //Abrir el archivo y verificar que se abra correctamente
    ifstream archivo("Encriptado1.txt");

    if (!archivo.is_open()){
        cout<<"Error al abrir el archivo"<<endl;
        return 1;
    }
    else
        cout<<"Se abrio correctamente el archivo"<<endl;

    //Leer contenido del archivo y descartar LZ,espacios, saltos de línea, y tabulaciones
    char letra;
    int cont = 0;

    //Con este while obtenemos el tamaño del próximo arreglo dinámico
    while (archivo.get(letra)){
        if (letra != ' ' && letra != '\n' && letra != '\t' && letra != 'Z' && letra != 'R'){
            cont++;
        }
    }

    archivo.clear();
    archivo.seekg(0); //Para que la extracción comience el posición 0 del archivo

    char* letras = new char[cont + 1];
    int indice = 0;

    while (archivo.get(letra)){
        if (letra != ' ' && letra != '\n' && letra != '\t' && letra != 'Z' && letra != 'R'){
            letras[indice++] = letra;
        }
    }

    //Para  arreglos de caracteres en la última posición se debe almacenar el caracter nulo----"Se consultó con el profe"
    letras[indice] = '\0';

    archivo.close(); //Ya obtuve los datos del archivo, entonces lo cierro.

    //Proceso de desencriptación del archivo Encriptado1.txt

    cout<<"El mensaje desencriptado es:"<<endl;
    for (int i = 0;i < cont;++i){
        letras[i] = XOR_char(letras[i]);
        char letra_xoreada = letras[i];
        char l_rotada = bits_derecha(letra_xoreada,3);
        char letra_final = l_rotada;
        cout<<letra_final;
    }

    cout<<endl;
    delete[]letras;




    return 0;
}

