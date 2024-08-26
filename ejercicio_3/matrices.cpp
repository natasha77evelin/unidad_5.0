#include <iostream>
using namespace std;

const int DIM = 5;
typedef struct {
    int elementos [DIM][DIM];
    int n;
} tMatriz;

void leerMatriz(tMatriz &mat);
void mostrarMatriz(const tMatriz &mat);
void sumarMatrices(const tMatriz &A, const tMatriz &B, tMatriz &C) ;
void restarMatrices(const tMatriz &A, const tMatriz &B, tMatriz &C);
void multiplicarMatrices(const tMatriz &A, const tMatriz &B, tMatriz &C);
void trasponerMatriz(const tMatriz &A, tMatriz &T);
void encontrarPuntosSilla(const tMatriz &A);

int main() {
    int n; // Variable para el tamaño de la matriz.
    tMatriz A, B, C, T; //Se crean cuatro matrices de tipo tMatriz

    cout << "Introduce el tamaño de la matriz (NxN): ";
    cin >> n;

    //Se asigna el tamaño a las matrices.
    A.n = n;
    B.n = n;
    C.n = n;
    T.n = n;

    cout << "Matriz A:" << endl;
    leerMatriz(A);

    cout << "Matriz B:" << endl;
    leerMatriz(B);

    int opcion; //Para el menu
    do {
        
        cout << "-------- MENU --------" << endl;
        cout << "1. Sumar matrices" << endl;
        cout << "2. Restar matrices" << endl;
        cout << "3. Multiplicar matrices" << endl;
        cout << "4. Trasponer matriz A" << endl;
        cout << "5. Encontrar puntos de silla en matriz A" << endl;
        cout << "6. Salir" << endl;
        cout << "Opcion: ";
        cin >> opcion;

        switch (opcion) {
            case 1:
                sumarMatrices(A, B, C);
                cout << "Resultado de la suma de matrices:" << endl;
                mostrarMatriz(C);
                break;
            case 2:
                restarMatrices(A, B, C);
                cout << "Resultado de la resta de matrices:" << endl;
                mostrarMatriz(C);
                break;
            case 3:
                multiplicarMatrices(A, B, C);
                cout << "Resultado de la multiplicación de matrices:" << endl;
                mostrarMatriz(C);
                break;
            case 4:
                trasponerMatriz(A, T);
                cout << "Matriz A traspuesta:" << endl;
                mostrarMatriz(T);
                break;
            case 5:
                cout << "Puntos de silla en la matriz A:" << endl;
                encontrarPuntosSilla(A);
                break;
            case 6:
                cout << "Saliendo..." << endl;
                break;
            default:
                cout << "Opcion no válida, por favor intente nuevamente." << endl;
                break;
        }
    } while (opcion != 6);

    return 0;
}
void leerMatriz(tMatriz &mat) {
    //Lee los elementos de la matriz de tamaño n x n del usuario

    cout << "Introduce los elementos de la matriz de tamaño " << mat.n << "x" << mat.n << ":" << endl;
    for (int i = 0; i < mat.n; i++) {
        for (int j = 0; j < mat.n; j++) {
            cin >> mat.elementos[i][j];
        }
    }
}

void mostrarMatriz(const tMatriz &mat) {

    //Muestra la matriz por consola
    for (int i = 0; i < mat.n; i++) {
        for (int j = 0; j < mat.n; j++) {
            cout << mat.elementos[i][j] << " ";
        }
        cout << endl;
    }
}

void sumarMatrices(const tMatriz &A, const tMatriz &B, tMatriz &C) {
    //Suma dos matrices y almacena el resultado en la matriz C
    for (int i = 0; i < A.n; i++) {
        for (int j = 0; j < A.n; j++) {
            C.elementos[i][j] = A.elementos[i][j] + B.elementos[i][j];
        }
    }
}

void restarMatrices(const tMatriz &A, const tMatriz &B, tMatriz &C) {
    //Resta dos matrices y almacena el resultado en la matriz C

    for (int i = 0; i < A.n; i++) {
        for (int j = 0; j < A.n; j++) {
            C.elementos[i][j] = A.elementos[i][j] - B.elementos[i][j];
        }
    }
}

void multiplicarMatrices(const tMatriz &A, const tMatriz &B, tMatriz &C) {
    //Multiplica dos matrices y almacena el resultado en la matriz C
    for (int i = 0; i < A.n; i++) {
        for (int j = 0; j < A.n; j++) {
            C.elementos[i][j] = 0;
        }
    }

    // Multiplicar matrices A y B, almacenando el resultado en C
    for (int i = 0; i < A.n; i++) {
        for (int j = 0; j < A.n; j++) {
            for (int k = 0; k < A.n; k++) {
                C.elementos[i][j] += A.elementos[i][k] * B.elementos[k][j];
            }
        }
    }
}

void trasponerMatriz(const tMatriz &A, tMatriz &T) {
    //Transpone la matriz A y almacena el resultado en la matriz T.
    
    for (int i = 0; i < A.n; i++) {
        for (int j = 0; j < A.n; j++) {
            T.elementos[j][i] = A.elementos[i][j];
        }
    }
}

void encontrarPuntosSilla(const tMatriz &A) {
    for (int i = 0; i < A.n; i++) {
        for (int j = 0; j < A.n; j++) {
            int minFila = A.elementos[i][j];
            for (int k = 0; k < A.n; k++) {
                if (A.elementos[i][k] < minFila) {
                    minFila = A.elementos[i][k];
                }
            }

            int maxColumna = A.elementos[i][j];
            for (int k = 0; k < A.n; k++) {
                if (A.elementos[k][j] > maxColumna) {
                    maxColumna = A.elementos[k][j];
                }
            }

            if (A.elementos[i][j] == minFila && A.elementos[i][j] == maxColumna) {
                cout << "Punto de silla encontrado en [" << i << "][" << j << "]: " << A.elementos[i][j] << endl;
            }
        }
    }
}
