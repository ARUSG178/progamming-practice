#include <iostream>
#include <fstream>
using namespace std;

int main(){
    string archivo = "letras.txt";
    int frecuencia[26] = {0};
    char caracter;

    //Crear el archivo y escribirlo
    ofstream archivo_salida;
    archivo_salida.open(archivo);
    if (archivo_salida.is_open()) {
        archivo_salida << "Hola, mundo!" << endl;
        archivo_salida << "No se loco, tulepera";
        archivo_salida.close();
        }
    else cout << "No se pudo abrir el archivo";

    //Escribir al final del archivo
    archivo_salida.open(archivo, ios::app);{
        archivo_salida << "\nEsto es una prueba de escritura al final del archivo";
        archivo_salida.close();
    }

    //Abrir el archivo y leerlo
    ifstream archivo_entrada;
    archivo_entrada.open(archivo);
    if (archivo_entrada.is_open()){
        while (archivo_entrada.get(caracter)){
            caracter = tolower(caracter);
            if (caracter >= 'a' && caracter <= 'z'){
                frecuencia[caracter - 'a']++;
            }
        }
        archivo_entrada.close();
    }else { cout << "No se pudo abrir el archivo." << endl;}
    for (int i = 0; i < 26; i++){
        cout << "La letra " << char('a' + i) << " aparece "
        << frecuencia[i] << " veces." << endl;
        }
                
}