#include "Libro.h"
#include "Revista.h"
#include "Usuario.h"
#include <iostream>
using namespace std;

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
    //es la version vanilla, despues se pondrá para que por ISBN por ejemplo no se repitan los libros (por ejemplo de Quimica)
    string nom, isbn, autor, fecha, resumen;  //segun internet.con  al usar getline nos ahorramos posibles problemas con saltos de linea
    cout << "Escriba el nombre del libro: ";            // y con espacios vacios
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
    cout << "\nEl Libro se ha agregado existosamente!\n" << endl;
}

int main(){
    //aqui linea de codigo para cargar los archivos txt (creo que ya entendi como o eso espero)

    Usuario* usuarios[10];
    int contadorUsuarios = 0;
    MaterialBibliografico* biblioteca[10] = {nullptr};  //lo voy creando acá pero no se si por ejemplo quieres crear otra clase
    int contador = 0;                 //tipo biblioteca o algo asi y ahí ir creando las listas de material y usuarios

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
                //agregarRevista();
                break;

            case 3:
                //registrarUsuario();
                contadorUsuarios++;
                break;

            case 4:
                //buscarUsuario();
                break;

            case 5:
                //eliminarUsuario();
                break;
            
            case 6:
                //mostrarLibrosRevistasUsuario();
                break;

            default:
                cout << "Opción inválida. Intente nuevamente..." << endl;
                cout << " " << endl;
                cout << " " << endl;
        }
    }

    //esto tengo entendido que es para liberar la memoria al finalizar la ejecucion del menú...
    for(int i = 0; i < contador; i++){
        delete biblioteca[i];
    }

    for(int j = 0; j < contadorUsuarios; j++){
        delete usuarios[j];
    }

    return 0;
}