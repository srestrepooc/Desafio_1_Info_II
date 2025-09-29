#include <iostream>
#include <fstream>

using namespace std;

unsigned char rotarDer(unsigned char x, int n) {
    return (unsigned char)((x >> n) | (x << (8 - n)));
}
char convertir_a_char(int valor) {
    unsigned char val = (unsigned char)valor;
    val = val ^ 0x40;
    val = rotarDer(val, 3);
    return (char)val;
}
int convertir_a_int(int valor) {
    unsigned char val = (unsigned char)valor;
    val = val ^ 0x40;
    val = rotarDer(val, 3);
    return (int)val;
}


int main(){

    ifstream archivo("Encriptado3.txt", ios::binary);
    if (!archivo.is_open()) {
        cout << "No se pudo abrir el archivo." << endl;
        return 1;
    }
    //Tamaño del archivo
    archivo.seekg(0, ios::end);
    int total = archivo.tellg();
    archivo.seekg(0, ios::beg);

    //Arreglo dinámico para guardar lo extraído
    char* arreglo = new char[total];
    archivo.read(arreglo, total);
    archivo.close();

    //Arreglo para guardar las letras desencriptadas
    char* mensaje = new char[total];
    cout<<"El mensaje desencriptado es:"<<endl;

    //for para procesar las tripletas
    for (int i = 0; i < total; i += 3) {
        char b = arreglo[i+1];
        char c = arreglo[i+2];

        int repeticiones = convertir_a_int(b);
        char letra = convertir_a_char(c);

        for (int j=0;j < repeticiones;j++){
            cout<<letra;
        }
    }

    cout<<endl;
    delete[]arreglo;
    delete[]mensaje;



    return 0;
}
