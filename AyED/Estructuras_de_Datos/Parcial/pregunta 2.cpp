#include <iostream>
using namespace std;

template <typename T>
class Inventario{
    private:
        struct Objeto {
            char tipo;
            int peso;
            Objeto* next;
            Objeto(const char &t = '\0', const int &p = 0, Objeto* obj = nullptr) : tipo(t), peso(p), next(obj) {}
        };

        Objeto* head;
        Objeto* tail;
        int cantidad;

        class List <T>{
            struct Node {
                char tipo;
                int peso;
                Node* next;
                Node(const char &t = '\0', const int &p = 0, Objeto* obj = tail) : tipo(t), peso (p), next (obj) {}
            }

        }
        void insert(const char& tipo, const int& peso, Objeto* pos){
            Objeto* nuevo = new Objeto(tipo, peso, pos->next);
            pos->next = nuevo;
            cantidad++;
        }



    public:
        Inventario() : head(new Objeto()), tail(new Objeto()), cantidad (0){
            head->next = tail;
        }

        Inventario(const Inventario &inventario){
            head->next = tail;
            Objeto* current = head;
            Objeto* original = inventario.head->next;
            while (current != tail){
                Objeto* nuevo = new Objeto(original->tipo, original->peso, current);
                current = current->next;
                original = original->next;
            }
        }

        
        void agregar (Objeto elemento){
            Objeto* current = head;
            while(current != tail && current->peso < elemento.peso){
                current = current->next;
            }
            insert(elemento.tipo, elemento.peso, current);
        }

        int size(){ return cantidad;}
        bool empty(){return cantidad == 0;}

        void agregar(Inventario inventario){
        
        |   if(empty()|| inventario.head->next == inventario.tail) throw runtime_error ("Inventario vacío");

            Objeto* original = inventario.head->next;
                while(current != inventario.tail){
                    insert(original->tipo, original->peso, current);
                    original = original->next;
            }
        }

        void eliminar(Objeto objeto){
            Objeto* current = head->next;
            Objeto* prev = head;
            while(current != tail){
                if(current->tipo == objeto.tipo && current->peso == obj.peso){
                    prev->next = current->next;
                    delete current;
                    cantidad--;
                    return;
                }
        }

        int pesoTotal(){
            if(!empty()) return 0;

            Objeto* current = head->next;
            int peso = 0;
            while(current != tail){
                peso += current->peso;
                current = current->next;
            }
            
            return peso;
        }

        List<T> objetos(){
            List<T>
        }


};