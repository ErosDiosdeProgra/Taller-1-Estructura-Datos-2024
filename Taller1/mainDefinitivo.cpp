#include "Libro.h"
#include "Revista.h"
#include "Usuario.h"
#include <iostream>
#include <fstream>
#include <array>
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
    if(c >= 100){
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

void agregarRevista(MaterialBibliografico* biblioteca[], int c){
    if(c >= 100){
        cout << "La Biblioteca está llena, NO se pueden añadir más Revistas." << endl;
        return;
    }
    string nom, isbn, autor, mesPublicacion, numEdicion;
    cout << "Escriba el nombre de la revista: ";           
    cin.ignore();
    getline(cin, nom);
    cout << "ISBN de la revista: ";
    getline(cin, isbn);
    cout << "Nombre del Autor(es): ";
    getline(cin, autor);
    cout << "Numero de edicion de la revista: ";
    getline(cin, numEdicion);
    cout << "Mes de publicacion de la revista: ";
    getline(cin, mesPublicacion);

    biblioteca[c] = new Revista(nom, isbn, autor, stoi(numEdicion), mesPublicacion);
    cout << "\nLa revista se ha agregado existosamente!\n" << endl;
}

void registrarUsuario(Usuario* usuarios[], int c){          //estoy usando la misma logica que los otros, si total es crear un objeto dentro de un registro
    if(c >= 100){
        cout << "La base de usuarios está completa, NO se pueden añadir más usuarios." << endl;
        return;
    } 

    string nom, id;  
    cout << "Escriba el nombre del usuario que desea registrar: ";            
    cin.ignore();
    getline(cin, nom);
    cout << "Id del usuario: ";
    cin.ignore();
    getline(cin, id);

    usuarios[c] = new Usuario(nom, id);
    cout << "\nEl usuario se ha registrado existosamente!\n" << endl;
}

Usuario* buscarUsuario(string nom, string id, Usuario* usuarios[], int c) {     //lo que busco aqui es que mediante el nombre e id que nos den
    for (int i = 0; i < c; i++)                                                //lo vaya comparando con lo que tenga en la lista, algo como 
    {                                                                          // if(nom == this -> nom) { return usuarios[i] }
        
    }
}

void eliminarUsuario(Usuario* usuarios[], int c){          //ta ma latero pq hay que pedirle QUE usuario quiere eliminar, asi que hay que usar una funcion logica XD
    string nom, id;
    cout << "Escriba el nombre del usuario que desea eliminar:";
    cin.ignore();
    getline(cin, nom);
    cout<< "Escriba el ID del usuario que desea eliminar:";
    cin.ignore();
    getline(cin, id);
    
                                            //aqui iria la funcion de buscar usuarios                                            
    cout << "\nEl usuario se ha eliminado existosamente!\n" << endl;
}

void guardarDatos(MaterialBibliografico* biblioteca[] ,int c){
    ofstream archivo("materiales.txt");
    if(!archivo){
        cout << "No se pudo guardar la información de la biblioteca" << endl;
        return;
    }

    archivo << c << endl;
    for (int i = 0; i < c; ++i) {
        Libro* libro = dynamic_cast<Libro*>(biblioteca[i]);
        Revista* revista = dynamic_cast<Revista*>(biblioteca[i]);

        if (libro) {
            archivo << "Libro\n" << libro->getNombre() << "\n" << libro->getAutor() << "\n"
                    << libro->estaPrestado() << "\n";
            // Guardar otros atributos de Libro
        } else if (revista) {
            archivo << "Revista\n" << revista->getNombre() << "\n" << revista->getAutor() << "\n"
                    << revista->estaPrestado() << "\n";
            // Guardar otros atributos de Revista
        }
    }

    archivo.close();
    cout << "Biblioteca guardada exitosamente.\n";
}

void cargarDatos(MaterialBibliografico* biblioteca[], int c){
    ifstream archivo("materiales.txt");
    if (!archivo) {
        cout << "No se pudo abrir el archivo de los Materiales.\n";
        return;
    }

    archivo >> c;
    archivo.ignore(); // Ignorar el salto de línea

    for (int i = 0; i < c; ++i) {
        string tipo, nombre, autor;
        bool prestado;

        getline(archivo, tipo);
        getline(archivo, nombre);
        getline(archivo, autor);
        archivo >> prestado;
        archivo.ignore();  // Ignorar el salto de línea

        if (tipo == "Libro") {
            // Leer otros atributos del libro
            biblioteca[i] = new Libro(nombre, "", autor, "", "");  // Añadir los valores correctos
        } else if (tipo == "Revista") {
            // Leer otros atributos de la revista
            biblioteca[i] = new Revista(nombre, "", autor, 0, "");  // Añadir los valores correctos
        }

        if (prestado) {
            biblioteca[i]->prestar();
        }
    }

    archivo.close();
    cout << "Biblioteca cargada exitosamente.\n";
}

int main(){
    //aqui linea de codigo para cargar los archivos txt (creo que ya entendi como o eso espero)

    Usuario* usuarios[100] = {nullptr};
    int contadorUsuarios = 0;
    MaterialBibliografico* biblioteca[100] = {nullptr};  //lo voy creando acá pero no se si por ejemplo quieres crear otra clase
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
                agregarRevista(biblioteca, contador);
                break;

            case 3:
                registrarUsuario(usuarios, contadorUsuarios); 
                contadorUsuarios++;
                break;

            case 4:
                //buscarUsuario();                        //necesito buscarUsuario para eliminarlo en primer lugar
                break;
                //sizeof
            case 5:
            if (contadorUsuarios == 0)
            {
                cout << "No se pueden eliminar usuarios, no hay usuarios registrados" << endl;    //control de error en caso de que un
            } else {                                                                              //desquiciado quiera eliminar algo iniciando el programa
                eliminarUsuario(usuarios,contadorUsuarios);
                contadorUsuarios--;
            }
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
    //
    //for(int i = 0; i < contador; i++){
    //    delete biblioteca[i];
    //}

    //for(int j = 0; j < contadorUsuarios; j++){
    //    delete usuarios[j];
    //}

    return 0;
}