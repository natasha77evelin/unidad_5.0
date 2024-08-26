/*Programa que lee del teclado una frase y muestra las palabras en una columna, 
seguida cada una del número de letras que la componen.*/

#include <iostream>
#include <sstream>
#include <string>
#include <iomanip>
using namespace std;

int main() {
    string frase;

    cout << "Introduce una frase: ";
    getline(cin, frase);

    istringstream cadena(frase);
    string palabra;

    //Mostar cada palabra y el numero de letras que la componen
    cout << left << setw(15) << "Palabras" << "Letras" << endl;
    cout << "----------------------" << endl;
    while (cadena >> palabra) {
        cout << left << setw(15) << palabra << palabra.length() << endl;
    }

    return 0;
}
