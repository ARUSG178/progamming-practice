#include <iostream>
#include <vector>
using namespace std;

void evenOdd(const vector<int> &numbers, int &even, int &odd){
    for(int i : numbers) {
        if(i % 2 == 0) even ++;
        else odd ++;
    }
}

int main (){
    vector<int> numbers;
    int x, even = 0, odd = 0;
    int quantity;

    cout << "Enter the quantity of digits that you want to insert: ";
    cin >> quantity;

    for (int i = 0; i < quantity; i++) {
        cin >> x;
        numbers.push_back(x);
    }

    evenOdd(numbers, even, odd);

    cout << "Numbers even: " << even << "| Numbers odd: " << odd << endl;

    return 0;
}
