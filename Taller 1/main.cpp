#include <iostream>
using namespace std;
#include "Libro.h"
#include "Revista.h" 
#include "Usuario.h"

/*ESTE MAIN ES FALSO, SE ME HABIA OLVIDADO QUE HAY QUE LEER/ESCRIBIR/GUARDAR LOS DATOS EN EL ARCHIVO.TXT
ASI QUE NO TOMES EN CUENTA ESTO :D*/

int mostrarOpciones(){              
    cout << "**** Bienvenido al Sistema de Bibliotecas UCN ****" << endl;
    cout << "1. Agregar Libros" << endl;
    cout << "2. Agregar Revista" << endl;
    cout << "3. Registrar Usuario" << endl;
    cout << "4. Buscar Usuario" << endl;
    cout << "5. Eliminar Usuario" << endl;
    cout << "6. Mostrar Libros/Revistas prestados a Usuarios" << endl;
    cout << "0. Salir del Sistema" << endl;
    cout << "Seleccione una opcion: ";
    int op;
    cin >> op;
    cout << " " << endl;
    cout << " " << endl;

    return op;
}

void agregarLibro(MaterialBibliografico* biblioteca[], int c){
    if(c >= 10){
        cout << "La Biblioteca está llena, NO se pueden añadir más Libros." << endl;
        return;
    }

    string nom, isbn, autor, fecha, resumen;
    cout << "Escriba el nombre del libro: ";
    cin.ignore();
    getline(cin, nom);
    cout << "ISBN del libro: ";
    getline(cin, isbn);
    cout << "Nombre del Autor(es): ";
    getline(cin, autor);
    cout << "Fecha de publicación del Libro: ";
    getline(cin, fecha);
    cout << "Resumen del Libro: ";
    getline(cin, resumen);

    biblioteca[c] = new Libro(nom, isbn, autor, fecha, resumen);
}

void agregarRevista(MaterialBibliografico* biblioteca[], int c){
    cout << "agregaste una revista" << endl;
}

void registrarUsuario(){
    cout << "registraste un usuario" << endl;
}

void buscarUsuario(){
    cout << "Encontraste al usuario" << endl;
}

void eliminarUsuario(){
    cout << "el usuario  JUANITO ha sido eliminado" << endl;
}

void mostrarLibrosRevistasUsuario(){
    cout << "juanito tiene 2 libros y son: 1) Matematicas    2) Quimica " << endl;
}

void menuBibliotecas(MaterialBibliografico* biblioteca[], int contador){
    bool menu = true;
    while(menu){
        int opcion = mostrarOpciones();

        switch(opcion){
            case 0:
                cout << "Cerrando Sistema..." << endl;
                cout << " " << endl;
                menu = false;
                break;
            
            case 1:
                agregarLibro(biblioteca, contador);
                contador++;
                break;

            case 2:
                agregarRevista(biblioteca, contador);
                contador++;
                break;

            case 3:
                registrarUsuario();
                break;

            case 4:
                buscarUsuario();
                break;

            case 5:
                eliminarUsuario();
                break;
            
            case 6:
                mostrarLibrosRevistasUsuario();
                break;

            default:
                cout << "Opción inválida. Intente nuevamente..." << endl;
                cout << " " << endl;
                cout << " " << endl;
        }
    }
}

int main(){
    /*Le puse 10 para ir probando, pero no se de cuantos quieras el tamaño
    en el pdf dice de ejemplo 100 */

    MaterialBibliografico* biblioteca[10] = {nullptr};  //aqui podriamos arreglarlo despues para cuando eliminen un libro, luego mover
    int contador = 0;                                   //toda la lista para que no queden espacios vacios y asi tmb modificar el contador

    menuBibliotecas(biblioteca, contador);
    
    //esto tengo entendido que es para liberar la memoria al finalizar la ejecucion del menú...
    for(int i = 0; i < contador; i++){
        delete biblioteca[i];
    }

    cout << "Felicidades, el menu funciono xd" << endl;

    return 0;
}