/*
Crear un vector<int> con los números del 1 al 10
Imprimir todos los elementos con for clásico.
Imprimir todos los elementos con for-each.
Imprimir todos los elementos con iteradores (vector<int>::iterator).
Insertar un número al final (push_back).
Insertar un número al inicio (insert).
Borrar un elemento específico (erase).
Vaciar el vector (clear) y comprobar empty().
Encontrar tamaño (size) y capacidad (capacity).
Redimensionar con resize.
Copiar un vector en otro (vector<int> v2 = v).
Comparar dos vectores (==, !=).
Reemplazar todos los elementos por 0 usando assign.
Intercambiar dos vectores (swap).
Encontrar un elemento con find (requiere #include <algorithm>).
Sumar todos los elementos usando accumulate (#include <numeric>).
Contar cuántos son pares con count_if.
Ordenar el vector (sort).
Invertirlo (reverse).
Eliminar duplicados (unique + erase).
*/
#include <iostream>
#include <algorithm>
#include <numeric>
#include <vector>
using namespace std;

int main() {
    vector<int> uwu = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};

    // for classic
    for (auto i = uwu.begin(); i != uwu.end(); ++i)  cout << *i << " "; cout << endl;
    // for-each
    for (auto &it : uwu) cout << it << " "; cout << endl;
    // iterator
    for(vector<int>::iterator it = uwu.begin(); it != uwu.end(); it++) {
        cout << *it << " ";
    }
    // push_back 10 (final)
    uwu.push_back(10);
    // insert 15 at the beginning
    uwu.insert(uwu.begin(), 15);  // (posición, valor)
    // erase first element
    uwu.erase(uwu.begin());
    // clear
    uwu.clear();
    cout << uwu.empty() << endl;
    // find size and capacity
    uwu = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
    cout << uwu.size() << endl;
    cout << uwu.capacity() << endl;
    // resize
    uwu.resize(10, 15); // (nuevo tamaño, valores dentro de esos nuevos slots)
    for(auto &it : uwu) cout << it << " ";
    // copy vector in another
    vector<int> uwu2 = uwu;
    for(auto &it : uwu2) cout << it << " ";
    if(uwu2 == uwu) cout << "uwu" << endl;
    else cout << "vete a la verga" << endl;
    // asign
    uwu.assign(uwu.size(), 0); // (tamaño, valor)
    // swap
    swap(uwu2, uwu); // (vector, otro vector)
    // find a value
    if(find(uwu2.begin(), uwu2.end(), 4) != uwu2.end()) cout << "Finded" << endl; // (inicio_busqueda, final_busqueda, elemento). Devuelve iterador
    else cout << "UnU" << endl;
    // sum all elements
    auto sumUwU = (accumulate(uwu.begin(), uwu.end(), 0)) + (accumulate(uwu2.begin(), uwu2.end(), 0));
    cout << sumUwU << endl;
    // pars
    int pares = count_if(uwu.begin(), uwu.end(), [](int x){ return x & 2 == 0; }); // (inicio_busqueda, final_busqueda, proposicion (booleano))
    // sort method
    sort(uwu2.begin(), uwu2.end());
    // inverse
    reverse(uwu2.begin(),uwu2.end());
    // erase duplicates
    sort(uwu.begin(), uwu.end());
    auto last = unique(uwu.begin(), uwu.end()); // (inicio, final). Devuelve iterador
    uwu.erase(last, uwu.end());
    for(auto &nya : uwu) cout << nya << " "; cout << endl;
}