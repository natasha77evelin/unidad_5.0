#include <iostream>
#include <fstream>
using namespace std;

const int MAX_PRODUCTOS = 1000;

//Definicion de estructuras
typedef struct {
    int codigo;
    float precio;
    int unidades;
}tProducto;

typedef struct {
    tProducto productos[MAX_PRODUCTOS];  
    int numProductos; //Contador de productos que se han almacenado
}tLista;

void leerDatos (ifstream &archivo, tLista &lista);
void mostrarDatos (const tLista &lista);
void productoMaxValor(const tLista &lista);
void eliminarProducto(tLista &lista, int codigo);

int main(){
    tLista lista;
    ifstream archivo;
    archivo.open("productos.txt");

    if (archivo.is_open()){
        leerDatos(archivo, lista);
        archivo.close();
        mostrarDatos(lista);
    }
    else {
        cout << "Error al abrir el archivo" << endl;
        }
    
    //Encontrar el producto con el valor máximo
    productoMaxValor(lista);

    //Eliminar un producto con un codigo dado
    int cod_eliminar;
    cout << "---- Para ELIMINAR un producto ingresa el codigo ----: ";
    cin >> cod_eliminar;
    eliminarProducto(lista, cod_eliminar);

    //Mostrar la lista actualizada
    mostrarDatos(lista);
    productoMaxValor(lista);

    return 0;
}

void leerDatos (ifstream &archivo, tLista &lista){ //Se pasan los parametros por referencia
    int codigo, unidades;
    float precio;
    lista.numProductos = 0; //Inicializa el contador en cero

    archivo >> codigo;
        while (codigo != -1){ // -1 es el centinela
             archivo >> precio >> unidades;
        if (lista.numProductos < MAX_PRODUCTOS) {
            lista.productos[lista.numProductos].codigo = codigo;
            lista.productos[lista.numProductos].precio = precio;
            lista.productos[lista.numProductos].unidades = unidades;            
            lista.numProductos++;
            }
            else{
                cout << "Se ha llegado al numero maximo de productos permitidos" << endl;
                break;
            }
            archivo >> codigo;
        }
    }

void mostrarDatos (const tLista &lista){ //Itera los arreglos de productos
    for (int i = 0; i < lista.numProductos; i++) {
        cout << "Codigo: " << lista.productos[i].codigo << endl;
        cout << "Precio: " << lista.productos[i].precio << endl;
        cout << "Unidades: " << lista.productos[i].unidades << endl;
        cout << "-------------------------" << endl;
    }
}
//Función para encontrar el producto con el máximo valor
void productoMaxValor(const tLista &lista){

    int indiceMax = 0;
    float maxValor;

    for (int i = 0; i < lista.numProductos; i++) {
        float valorActual = lista.productos[i].precio * lista.productos[i].unidades;
        if (valorActual > maxValor) {
            maxValor = valorActual;
            indiceMax = i;
        }
    }
        cout << "----- PRODUCTO on el valor maximo en el almacen -----" << endl;
        cout << "Codigo: " << lista.productos[indiceMax].codigo << endl;
        cout << "Precio: " << lista.productos[indiceMax].precio << endl;
        cout << "Unidades: " << lista.productos[indiceMax].unidades << endl;
        cout << "Valor: " << lista.productos[indiceMax].precio * lista.productos[indiceMax].unidades << endl;
}

//Función para eliminar un producto por su código
void eliminarProducto(tLista &lista, int codigo) {
    int pos = -1;

    //Buscar el producto con el código dado
    for (int i = 0; i < lista.numProductos; i++) {
        if (lista.productos[i].codigo == codigo) {
            pos = i;
            break;
        }
    }

    //Si no se encuentra el producto
    if (pos == -1) {
        cout << "Producto no encontrado." << endl;
    }

    //Eliminar el producto y ajustar el resto de la lista
    for (int i = pos; i < lista.numProductos - 1; i++) {
        lista.productos[i] = lista.productos[i + 1];
    }

    lista.numProductos--;
    cout << "Producto eliminado con exito." << endl;
}
