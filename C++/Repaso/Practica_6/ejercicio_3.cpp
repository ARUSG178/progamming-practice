 #include <iostream>
 #include <string>
 #include <algorithm> // para usar reverse
 using namespace std;

bool isCapicuaWithAlgorithm(string word) {
    string clean;
    for (char c: word) {
        //isspace(c) ve si no es un espacio. tolower pasa de mayus a minus.
        //en un string para agregar al final se suma.
        if (!isspace(c)) clean += tolower(c);
    }

    string reversed = clean;
    reverse(reversed.begin(), reversed.end());

    return reversed == clean;
}

bool isCapicua(string word) {
    string clean;
    for (char c: word) {
        //isspace(c) ve si no es un espacio. tolower pasa de mayus a minus.
        //en un string para agregar al final se suma.
        if (!isspace(c)) clean += tolower(c);
    }

    string reversed = clean;
    for(int i = clean.size(); i > 0; i--) reversed += clean[i - 1];
    
    return reversed == clean;
}

 int main () {
    string word;
    cout << "Insert the number, word or phrase that you want to know if Capicua/Palindrome or not: ";
    getline(cin, word);

    if(isCapicua(word)) cout << "Is Capicua or Palindrome!" << endl;
    else cout << "Isn't Capicua or Palindrome ):" << endl;

    return 0;
 }

