#include <iostream>
#include <vector>
using namespace std;

void uwu(vector<int> A, int N, int &greatherThan, double &average) {
    int count = 0;
    int sumatory = 0;
    for(int i : A){
        count++;
        if(i > N) {
            greatherThan++;
            sumatory += i;
        }
    }

    average = static_cast<double>(sumatory)/greatherThan;
}

int main() {
    vector<int> numbers;
    int data, parameter;
    int greatherThan = 0;
    double average = 0;
    
    int max;
    cout << "Enter the max amount of number that you want to insert in the array: ";
    cin >> max;

    for(int i = 0; i < max; i++){
        cin >> data;
        numbers.push_back(data);
    }

    uwu(numbers, parameter, greatherThan, average);

    cout << "Number grearthers than " << parameter << " : " << greatherThan << endl;
    cout << "Average of them: " << average << endl;
    
    return 0;
}