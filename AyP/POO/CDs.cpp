#include <iostream>
#include <string>
using namespace std;

class Producto{
    protected:
    string codigo;
    float precio;
    float IVA; // Cambiado a float

    public:

    Producto(string codigo, float precio, float IVA){
        this->codigo = codigo;
        this->precio = precio;
        this->IVA = IVA; // Cambiado a IVA
    }

    virtual float calculoPrecio() = 0;
    virtual void print(){
        cout << "Codigo: " << codigo << endl;
        cout << "Precio: " << calculoPrecio() << endl;
        }
};

class Libro: public Producto{
    private:
    string titulo;
    string autor;
    int anio_publicacion;
    string editorial;
    long long int ISBN;
    public:

    Libro(string c, float p, float IVA, string titulo, string autor, int anio_publicacion, string editorial, long long int ISBN) : Producto(c, p, IVA){
        this->titulo = titulo;
        this->autor = autor;
        this->anio_publicacion = anio_publicacion;
        this->editorial = editorial;
        this->ISBN = ISBN;
    }
    
    float calculoPrecio() {
        float precioConIVA = precio + (precio * IVA);
        return precioConIVA - (precioConIVA * 0.2);
    }

    void print(){
        Producto::print();
        cout << "Titulo: " << titulo << endl;
        cout << "Autor: " << autor << endl;
        cout << "Anio de publicacion: " << anio_publicacion << endl;
        cout << "Editorial: " << editorial << endl;
        cout << "ISBN: " << ISBN << endl;
        }
};

    class CD: public Producto{
    private:
    string titulo;
    string interprete;
    int anio_publicacion;
    public:
    CD(string c, float p, float IVA, string titulo, string interprete, int anio_publicacion) : Producto(c, p, IVA){
        this->titulo = titulo;
        this->interprete = interprete;
        this-> anio_publicacion = anio_publicacion;
    }

    float calculoPrecio() {
        float precioConIVA = precio + (precio * IVA);
        return precioConIVA - (precioConIVA * 0.1);
    }

    void print(){
        Producto::print();
        cout << "Titulo: " << titulo << endl;
        cout << "Interprete: " << interprete << endl;
    }
};

int main(){
    //Ahora un CD
    CD cd1("03240923", 100, 0.1, "La Solitaria", "El papu papu", 17062020);

    cd1.print();
    cout << "\n" << endl;
    //Ahora un libro
    Libro libro1("1234567890", 20.0, 0.16, "El Señor de los Anillos", "J.R.R. Tolkien", 1954, "Editorial Minotauro", 9783111L);
    libro1.print();
    cout << "\n" << endl;

    return 0;
}