#include <iostream>
#include <vector>
using namespace std;

int maxValue(const vector<int> &data){
    int max = INT_MIN;

    for(int i : data) if(max < i) max = data[i]; // data[i]  -> i
    
   return max;
}

int main (){ 
    vector<int> v;
    int x;

    cout << "Enter de numbers (finish with -1): ";
    while(cin >> x && x != -1) v.push_back(x);

     cout << "The max value is: " << maxValue(v) << endl;

    return 0;
}
