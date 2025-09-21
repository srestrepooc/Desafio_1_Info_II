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

    return 0;
}

