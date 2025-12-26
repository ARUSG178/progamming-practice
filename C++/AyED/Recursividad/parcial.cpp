#include <iostream>
using namespace std;

int minE(int arr[], int li, int ls){
    if (li == ls) return arr[li];
    if(li == ls - 1) return (arr[li] < arr[ls]) ? arr[li] : arr[ls];

    int mid = (li + ls) / 2;

    int minIzq = minE(arr, li, mid);
    int minDer = minE(arr, mid + 1, ls);

    if(minIzq > minDer) return minDer;
    else return minIzq;

}

int main() {

    int arr[10];
    int min = minE(arr, 0, 9);

    return 0;
}