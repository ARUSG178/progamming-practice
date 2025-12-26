#include <iostream>
#include <vector>
#include <cmath>

template <typename T>

class Point {
    private:
        T X;
        T Y;
        T Z;
    public:
        Point(const T &x, const T &y, const T &z) : X(x), Y(y), Z(z) {}
        T get_X() const { return X; }
        T get_Y() const { return Y; }
        T get_Z() const { return Z; }

    };

template <typename T>
double distanceBetween(const Point<T> &A, const Point<T> &B){
    double dx = static_cast<double>(A.get_X() - B.get_X());
    double dy = static_cast<double>(A.get_Y() - B.get_Y());
    double dz = static_cast<double>(A.get_Z() - B.get_Z());
    return std::sqrt(dx*dx + dy*dy + dz*dz);
}

int main (){
    // Crear dos puntos
    Point<int> p1(1, 2, 3);
    Point<int> p2(4, 6, 8);

    // Calcular distancia
    double dist = distanceBetween(p1, p2);

    std::cout << "Distancia entre puntos: " << dist << std::endl;

    return 0;
}
