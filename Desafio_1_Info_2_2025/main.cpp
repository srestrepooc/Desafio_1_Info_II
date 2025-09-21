#include <iostream>
#include <fstream>

using namespace std;

int main() {

    ifstream archivo("practica_1.txt");

    if (!archivo.is_open()) {
        cout<<"Error al abrir"<<endl;
        return 1;
    }
    else
        cout<<"Si se abrio"<<endl;

    string contenido;
    char cont;

    while (archivo.get(cont)){
        contenido += cont;
    }

    archivo.close();


    char* letras = new char[contenido.size() + 1];

    for (size_t i = 0;i < contenido.size();++i){
        letras[i] = contenido[i];
    }
    letras[contenido.size()] = '\0';


    for (size_t i = 0;i < contenido.size();++ i){
        letras[i] = ((letras[i] ^ 0x5A) >> 3) | (letras[i] << (8 - 3));


    }

    for (size_t i = 0;i < contenido.size();++ i){
        cout<<"Letra original: "<<static_cast<int>(contenido[i])<<", "<<"Letra convertida: "<<static_cast<int>(letras[i])<<endl;

    }



    cout<<endl;

    delete[]letras;


    return 0;
}

