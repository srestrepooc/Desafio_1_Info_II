#include <iostream>
#include <fstream>
using namespace std;

//rotación de 3 bits a la derecha
unsigned char rotarDer(unsigned char x, int n){
    return (unsigned char)((x >> n) | (x << (8 - n)));
}

//recibe un valor decimal y lo transforma en un char
char convertir_a_char(int valor){
    unsigned char val = (unsigned char)valor;
    val = val ^ 0x5A;           // XOR con semilla
    val = rotarDer(val, 3);     // Rotación derecha 3 bits
    return (char)val;
}

// Recibe el segundo elemento de la tripleta
int convertir_a_int(int valor){
    unsigned char val = (unsigned char)valor;
    val = val ^ 0x5A;
    val = rotarDer(val,3);
    return (int)val;
}

int main() {
    ifstream archivo("Encriptado2.txt", ios::binary);
    if (!archivo.is_open()){
        cout<<"No se pudo abrir el archivo."<<endl;
        return 1;
    }

    //Calcular tamaño del archivo según la cantidad de bytes leidos
    archivo.seekg(0, ios::end);
    int total = archivo.tellg();
    archivo.seekg(0, ios::beg);

    cout<<"El archivo tiene "<<total<<" caracteres"<<endl;

    // Reservar memoria para el arreglo dinámico
    char* arreglo = new char[total];
    archivo.read(arreglo, total);
    archivo.close();

    //Arreglo dinámico para almacenar el mensaje desencriptado
    char* mensaje = new char[total];
    int indice = 0;

    //analisar el texto por tripletas
    for (int i = 0; i < total; i += 3){
        char a = arreglo[i];
        char b = arreglo[i+1];
        char c = arreglo[i+2];


        if (a == 'Z' && b == 'Z'){
            char letra = convertir_a_char((unsigned char)c);
            mensaje[indice] = letra;
            indice++;
        }

        else if (a == 'Z' && b != 'Z'){
            int num_indice = convertir_a_int((unsigned char)b);
            if (num_indice < indice) {
                mensaje[indice] = mensaje[num_indice - 1];
                indice++;
            }
            char letra = convertir_a_char((unsigned char)c);
            mensaje[indice] = letra;
            indice++;
        }
    }

    mensaje[indice] = '\0';


    cout<<"Texto desencriptado: "<<endl;
    for (int i = 0; i < indice; i++) {
        cout << mensaje[i];
    }
    cout<<endl;

    delete[] arreglo;
    delete[] mensaje;

    return 0;
}

