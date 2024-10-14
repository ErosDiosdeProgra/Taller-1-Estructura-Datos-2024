#include "Libro.h"
#include "Revista.h"
#include "Usuario.h"
#include <iostream>
#include <fstream>
#include <stdexcept>
#include <limits>
using namespace std;

/*Esta funcion imprime las opciones que tiene el menu
y posee el control de errores en caso de que escriba algun dato que 
no sea un entero*/
/*Esta funcion imprime las opciones que tiene el menu
y posee el control de errores en caso de que escriba algun dato que 
no sea un entero*/
int mostrarOpciones(){              
    cout << "**** Bienvenido al Sistema de Bibliotecas UCN ****" << endl;
    cout << "1. Agregar Libros" << endl;
    cout << "2. Agregar Revista" << endl;
    cout << "3. Registrar Usuario" << endl;
    cout << "4. Agregar material a un usuario" << endl;
    cout << "4. Agregar material a un usuario" << endl;
    cout << "5. Eliminar Usuario" << endl;
    cout << "6. Mostrar Libros/Revistas prestados a Usuarios" << endl;
    cout << "7. Desplegar todos los materiales del sistema" << endl;
    cout << "8. Buscar materiales por titulo" << endl;
    cout << "9. Buscar materiales por autor" << endl;
    cout << "10. Devolver un material de un usuario" << endl;
    cout << "0. Salir del Sistema" << endl;
    cout << "Seleccione una opcion: ";
    int op;
    cin >> op;
    cout << " " << endl;
    cout << " " << endl;


    if (cin.fail()) {
        cin.clear(); // Entre el fail y el clear, se encargan de ver si falla la entrada (por pedir un int y que nos den otro tipo) y el clear "limpia" cin pa que no hayan errores
        cin.ignore(numeric_limits<streamsize>::max(), '\n'); //se ignoran la mayor cantidad de numeros que se encuentren hasta un salto de linea (el enter u espacio)
        throw invalid_argument("Entrada invalida, ingrese un numero");
    }

    return op;
}

/*Esta funcion crea un objeto libro, solicitando los datos al que use el menu
y luego lo añade a la lista de llamada biblioteca
además comprueba que estemos dentro de los limites de almacenamiento de la lista*/
/*Esta funcion crea un objeto libro, solicitando los datos al que use el menu
y luego lo añade a la lista de llamada biblioteca
además comprueba que estemos dentro de los limites de almacenamiento de la lista*/
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

/*Esta funcion crea un objeto revista, solicitando los datos al que use el menu
y luego lo añade a la lista de MaterialBibliografico llamado biblioteca
además comprueba que estemos dentro de los limites de almacenamiento de la lista*/
/*Esta funcion crea un objeto revista, solicitando los datos al que use el menu
y luego lo añade a la lista de MaterialBibliografico llamado biblioteca
además comprueba que estemos dentro de los limites de almacenamiento de la lista*/
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

/*Esta funcion crea un objeto Usuario, solicitando los datos al que use el menu
y luego lo añade a la lista llamada usuarios, y comprueba que estemos dentro
de los limites de la lista antes de agregar un nuevo usuario*/
/*Esta funcion crea un objeto Usuario, solicitando los datos al que use el menu
y luego lo añade a la lista llamada usuarios, y comprueba que estemos dentro
de los limites de la lista antes de agregar un nuevo usuario*/
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
    getline(cin, id);

    usuarios[c] = new Usuario(nom, id);
    cout << "\nEl usuario se ha registrado existosamente!\n" << endl;
}

/*Esta funcion recibe como parametros una lista de usuarios y un int que es un contador, solicitando dentro que
se ingresen un nombre y un id con el cual, mediante una revision de la lista, se nos devolvera el puntero del objeto 
deseado*/

Usuario* buscarUsuario(Usuario* usuarios[], int c) {     
    string nom, id;
    cout << "Escriba el nombre del usuario que esta buscando: ";
    cin.ignore();
    getline(cin, nom);
    cout << "Escriba el Id del usuario que esta buscando: ";
    getline(cin, id);
    for (int i = 0; i < c; i++)                                                
    {                                                                          
        if(nom == usuarios[i]->getNombre() && id == usuarios[i]->getId())
        {
            return usuarios[i];
        }
    }
    return nullptr;
}

MaterialBibliografico* buscarMaterial(MaterialBibliografico* biblioteca[], int c) {     //si coloco un cin.ignore se me muere (se salta la primera letra)
    string nom, isbn, autor;                                    
    cout << "Escriba el nombre del libro que esta buscando: ";
    getline(cin, nom);
    cout << "Escriba el isbn del usuario que esta buscando: ";
    getline(cin, isbn);
    cout << "Escriba el autor del usuario que esta buscando: ";
    getline(cin, autor);
    for (int i = 0; i < c; i++)                                                
    {                  
        cout << biblioteca[i]->getNombre() << endl;           
        cout << nom << endl;                                            
        if(nom == biblioteca[i]->getNombre() && isbn == biblioteca[i]->getIsbn() && autor == biblioteca[i]->getAutor())
        {
            return biblioteca[i];
        }
    }
    return nullptr;
}

void buscarMaterialPorTitulo(MaterialBibliografico* biblioteca[], int c) {     //si coloco un cin.ignore se me muere (se salta la primera letra)
    string tit;                                    
    cout << "Escriba el titulo del material que esta buscando: ";
    cin.ignore();
    getline(cin, tit);
    bool existe = false; //verificar si hay uno o no

    for (int i = 0; i < c; ++i) 
    {    
        if (Libro* libro = dynamic_cast<Libro*>(biblioteca[i])) {
            if(tit == biblioteca[i]->getNombre()) {
            libro->mostrarInformacion();
            existe = true; }
        } else if (Revista* revista = dynamic_cast<Revista*>(biblioteca[i])) {
            if (tit == biblioteca[i]->getNombre()) {
            revista->mostrarInformacion(); 
            existe = true; }
            }

    }
            if (!existe) {
        cout << "No se encontraron materiales con el titulo especificado." << endl;
    }
}

void buscarMaterialPorAutor(MaterialBibliografico* biblioteca[], int c) {     //si coloco un cin.ignore se me muere (se salta la primera letra)
    string autor;                                    
    cout << "Escriba el autor del material que esta buscando: ";
    cin.ignore();
    getline(cin, autor);
    bool existe = false; //verificar si hay uno o no

    for (int i = 0; i < c; ++i) 
    {    
        if (Libro* libro = dynamic_cast<Libro*>(biblioteca[i])) {
            if (autor == libro->getAutor()) {
            libro->mostrarInformacion();
            cout << " " << endl; 
            existe = true; }
        } else if (Revista* revista = dynamic_cast<Revista*>(biblioteca[i])) {
            if (autor == revista->getAutor()) {
            revista->mostrarInformacion();
            cout << " " << endl; 
            existe = true; }
            }

    }
            if (!existe) {
        cout << "No se encontraron materiales del autor especificado." << endl;
    }
}

/*Esta funcion recibe como parametros una lista de materiales bibliograficos y un int que es un contador, solicitando dentro que
se ingresen un nombre (titulo), isbn y un autor, lo que nos permite mediante una revision de la lista la devolucion del puntero al
objeto deseado*/

MaterialBibliografico* buscarMaterial(MaterialBibliografico* biblioteca[], int c) {     //si coloco un cin.ignore se me muere (se salta la primera letra)
    string nom, isbn, autor;                                    
    cout << "Escriba el nombre del libro que esta buscando: ";
    getline(cin, nom);
    cout << "Escriba el isbn del usuario que esta buscando: ";
    getline(cin, isbn);
    cout << "Escriba el autor del usuario que esta buscando: ";
    getline(cin, autor);
    for (int i = 0; i < c; i++)                                                
    {                  
        cout << biblioteca[i]->getNombre() << endl;           
        cout << nom << endl;                                            
        if(nom == biblioteca[i]->getNombre() && isbn == biblioteca[i]->getIsbn() && autor == biblioteca[i]->getAutor())
        {
            return biblioteca[i];
        }
    }
    return nullptr;
}

/*Esta funcion recibe como parametros una lista de materiales bibliograficos y un int que es un contador, solicitando dentro que
se ingresen un nombre (titulo), lo que nos permite mediante una revision de la lista la devolucion (con su informacion) de TODOS los
objeto deseado mediante un casteo dinamico*/

void buscarMaterialPorTitulo(MaterialBibliografico* biblioteca[], int c) {     //si coloco un cin.ignore se me muere (se salta la primera letra)
    string tit;                                    
    cout << "Escriba el titulo del material que esta buscando: ";
    cin.ignore();
    getline(cin, tit);
    bool existe = false; //verificar si hay uno o no

    for (int i = 0; i < c; ++i) 
    {    
        if (Libro* libro = dynamic_cast<Libro*>(biblioteca[i])) {
            if(tit == biblioteca[i]->getNombre()) {
            libro->mostrarInformacion();
            existe = true; }
        } else if (Revista* revista = dynamic_cast<Revista*>(biblioteca[i])) {
            if (tit == biblioteca[i]->getNombre()) {
            revista->mostrarInformacion(); 
            existe = true; }
            }

    }
            if (!existe) {
        cout << "No se encontraron materiales con el titulo especificado." << endl;
    }
}

/*Esta funcion recibe como parametros una lista de materiales bibliograficos y un int que es un contador, solicitando dentro que
se ingresen un autor, lo que nos permite mediante una revision de la lista la devolucion (con su informacion) de TODOS los
objeto deseado mediante un casteo dinamico*/

void buscarMaterialPorAutor(MaterialBibliografico* biblioteca[], int c) {     //si coloco un cin.ignore se me muere (se salta la primera letra)
    string autor;                                    
    cout << "Escriba el autor del material que esta buscando: ";
    cin.ignore();
    getline(cin, autor);
    bool existe = false; //verificar si hay uno o no

    for (int i = 0; i < c; ++i) 
    {    
        if (Libro* libro = dynamic_cast<Libro*>(biblioteca[i])) {
            if (autor == libro->getAutor()) {
            libro->mostrarInformacion();
            cout << " " << endl; 
            existe = true; }
        } else if (Revista* revista = dynamic_cast<Revista*>(biblioteca[i])) {
            if (autor == revista->getAutor()) {
            revista->mostrarInformacion();
            cout << " " << endl; 
            existe = true; }
            }

    }
            if (!existe) {
        cout << "No se encontraron materiales del autor especificado." << endl;
    }
}

/*Esta funcion recibe como parametros una lista de usuarios y un int que es un contador, solicitando dentro que
se ingresen las credenciales (nombre e id) del usuario el cual se esta buscando eliminar, lo que nos permite mediante
 una revision de la lista la eliminacion del puntero, a la vez que "limpia" y ordena la lista*/

void eliminarUsuario(Usuario* usuarios[], int c){          
    string nom, id;                                                                         
        cout << "Escriba el nombre del usuario que esta buscando: ";                          
        cin.ignore();
        getline(cin, nom);
        cout << "Escriba el Id del usuario que esta buscando: ";
        getline(cin, id);
        cout <<"has llegado aqui"<<endl;
        for (int i = 0; i < c; i++)                                                
        {                                                                          
            if(nom == usuarios[i]->getNombre() && id == usuarios[i]->getId())
            {
                delete usuarios[i];
                for (int j = i; j < c-1; j++)
                {
                    usuarios[j] = usuarios[j+1];
                }
                usuarios[c -1] = nullptr;
                cout << "\nEl usuario se ha eliminado existosamente!\n" << endl;
                return;
            }
        }                                                                                                             
        cout << "\nEl usuario no existe!\n" << endl;
}
}

/*Esta funcion guarda la informacion de la lista biblioteca en el 
archivo "Materiales.txt" para que se mantenga la información luego
de utilizar el programa. ademas comprueba si es que existe o no el archivo
antes de ejecutarlo*/
/*Esta funcion guarda la informacion de la lista biblioteca en el 
archivo "Materiales.txt" para que se mantenga la información luego
de utilizar el programa. ademas comprueba si es que existe o no el archivo
antes de ejecutarlo*/
void guardarDatos(MaterialBibliografico* biblioteca[] ,int c){
    ofstream archivo("Materiales.txt");
    ofstream archivo("Materiales.txt");
    if(!archivo){
        cout << "No se pudo guardar la información de la biblioteca ya que el archivo NO EXISTE!" << endl;
        return;
    }

    archivo << c << endl;                //esto guarda cantidad de materiales tecnicamente
    for (int i = 0; i < c; ++i) {        //tecnicamente esto funcionaria como un instanceof en JAVA para la lectura de la biblioteca...
        Libro* libro = dynamic_cast<Libro*>(biblioteca[i]);
        Revista* revista = dynamic_cast<Revista*>(biblioteca[i]);

        if (libro) {
            archivo << "Libro\n" << libro -> getNombre() << "\n" << libro -> getIsbn() << libro -> getAutor() << "\n"
                    << libro -> estaPrestado() << "\n" << "\n" << libro -> getFechaPublicacion() << "\n" << libro -> getResumen();
            
        } else if (revista) {
            archivo << "Revista\n" << revista -> getNombre() << "\n" << revista -> getIsbn() << "\n" << revista -> getAutor() << "\n"
                    << revista -> estaPrestado() << "\n" << revista -> getMesPublicacion() << "\n" << revista -> getNumEdicion();
        }
    }

    archivo.close();
    cout << "Biblioteca guardada EXITOSAMENTE!" <<endl;
}

/*Esta funcion carga los datos de un archivo.txt llamado "Materiales.txt"
primero comprueba si es que existe el archivo con ese nombre, y de ser asi comienza la lectura
del archivo, para luego ir creando los objetos correspondientes e ir añadiendolos a la lista
de la biblioteca*/
void cargarDatos(MaterialBibliografico* biblioteca[], int mat){
    ifstream archivo("Materiales.txt");
/*Esta funcion carga los datos de un archivo.txt llamado "Materiales.txt"
primero comprueba si es que existe el archivo con ese nombre, y de ser asi comienza la lectura
del archivo, para luego ir creando los objetos correspondientes e ir añadiendolos a la lista
de la biblioteca*/
void cargarDatos(MaterialBibliografico* biblioteca[], int mat){
    ifstream archivo("Materiales.txt");
    if (!archivo) {
        cout << "No se pudo abrir el archivo de los Materiales ya que NO EXISTE!\n";
        return;
    }
    int c; 
    archivo >> c;
    mat = c;         //esto es para asignarle el numero de materiales a la variable del menu
    mat = c;         //esto es para asignarle el numero de materiales a la variable del menu
    archivo.ignore(); 

    for (int i = 0; i < c; ++i) {
        string tipo, nombre, autor, isbn, fechaPublicacion, mesPublicacion, resumen;
        int numeroEdicion;
        bool prestado;

        getline(archivo, tipo);
        getline(archivo, nombre);
        getline(archivo, isbn);
        getline(archivo, autor);
        archivo >> prestado;
        archivo.ignore();  

        if (tipo == "Libro") {
            getline(archivo, fechaPublicacion);
            getline(archivo, resumen);

            biblioteca[i] = new Libro(nombre, isbn, autor, fechaPublicacion, resumen);  

        } else if (tipo == "Revista") {
            getline(archivo, mesPublicacion);
            archivo >> numeroEdicion;  //porque es int, al igual que con el bool ¿?

            biblioteca[i] = new Revista(nombre, isbn, autor, numeroEdicion, mesPublicacion);  
        }

        if (prestado) {
            biblioteca[i]->prestar();
        }
    }

    archivo.close();
    cout << "La Biblioteca ha sido cargada exitosamente!" << endl;
}

/*Esta funcion guarda la informacion de los usuarios, tanto sus datos como los materiales que tenga
prestado en aquel momento, comprueba si es que existe el archivo "Usuario.txt" y de ser asi 
comienza a guardar los datos en el archivo.*/
/*Esta funcion guarda la informacion de los usuarios, tanto sus datos como los materiales que tenga
prestado en aquel momento, comprueba si es que existe el archivo "Usuario.txt" y de ser asi 
comienza a guardar los datos en el archivo.*/
void guardarUsuarios(Usuario* usuarios[], int c){
    ofstream archivo("Usuario.txt");
    if(!archivo){
        cout << "No se pudo guardar a los Usuarios debido a que NO EXISTE el archivo!" << endl;
        return;
    } 

    archivo << c << endl;
    for(int i = 0; i < c; ++i){
        archivo << usuarios[i] -> getNombre() << endl;
        archivo << usuarios[i] -> getId() << endl;
        archivo << usuarios[i] -> getMaterialPrestado() << endl;

        for(int j = 0; j < usuarios[i] -> getMaterialPrestado(); ++j){
            MaterialBibliografico* material = usuarios[i] -> getMaterial(j);

            if(Libro* libro = dynamic_cast<Libro*>(material)){
                archivo << "Libro" << endl;
                archivo << libro -> getNombre() << endl;
                archivo << libro -> getIsbn() << endl;
                archivo << libro -> getAutor() << endl;
                archivo << libro -> getFechaPublicacion() << endl;
                archivo << libro -> getResumen() << endl;
            }

            if(Revista* revista = dynamic_cast<Revista*>(material)){
                archivo << "Revista" << endl;
                archivo << revista -> getNombre() << endl;
                archivo << revista -> getIsbn() << endl;
                archivo << revista -> getAutor() << endl;
                archivo << revista -> getMesPublicacion() << endl;
                archivo << revista -> getNumEdicion() << endl;
            }
            archivo << material -> estaPrestado() << endl;
        }
    }
    archivo.close();
    cout << "Usuarios guardados EXISTOSAMENTE!" << endl;
}

/*Esta funcion verifica si existe el archivo Usuario.txt, y de ser asi comienza la lectura de el
donde despues va creando los objetos Usuario y tambien dependiendo de cuantos materiales tenga prestado
los va creando y añadiendo a sus listas de materiales prestados (correspondiente a cada usuario)*/
void cargarUsuarios(Usuario* usuarios[], int usu){
    ifstream archivo("Usuario.txt");
/*Esta funcion verifica si existe el archivo Usuario.txt, y de ser asi comienza la lectura de el
donde despues va creando los objetos Usuario y tambien dependiendo de cuantos materiales tenga prestado
los va creando y añadiendo a sus listas de materiales prestados (correspondiente a cada usuario)*/
void cargarUsuarios(Usuario* usuarios[], int usu){
    ifstream archivo("Usuario.txt");
    if(!archivo){
        cout << "No se pudo abrir el archivo ya que NO EXISTE!" << endl;
        return;
    }
    int c;
    int c;
    archivo >> c ;
    usu = c;            //esto es para asignarle el numero de usuarios a la variable del menu
    usu = c;            //esto es para asignarle el numero de usuarios a la variable del menu
    archivo.ignore();

    for(int i = 0; i < c; ++i){
        string nombre, id;
        int materialesPrestados;

        getline(archivo, nombre);
        getline(archivo, id);
        archivo >> materialesPrestados;  //se supone va asi porque es int y no string
        archivo.ignore();

        usuarios[i] = new Usuario(nombre, id);
        for(int j = 0; j < materialesPrestados; ++j){     //debiera ser j??
            string tipo, nombre, isbn, autor; 
        for(int j = 0; j < materialesPrestados; ++j){     //debiera ser j??
            string tipo, nombre, isbn, autor; 
            bool prestado;

            getline(archivo, tipo);
            getline(archivo, nombre);
            getline(archivo, isbn);
            getline(archivo, autor);
            
            if(tipo == "Libro"){
                string fechaPublicacion, resumen;
                getline(archivo, fechaPublicacion);
                getline(archivo, resumen);

                Libro* libro = new Libro(nombre, isbn, autor, fechaPublicacion, resumen);
                usuarios[i] -> prestarMaterial(libro);
            }

            if(tipo == "Revista"){
                string mesPublicacion;
                int numeroEdicion;
                getline(archivo, mesPublicacion);
                archivo >> numeroEdicion;
                archivo.ignore();
                Revista* revista = new Revista(nombre, isbn, autor, numeroEdicion, mesPublicacion);
                usuarios[i] -> prestarMaterial(revista);
            }
            

            archivo >> prestado;
            archivo.ignore();
            if(prestado){
                usuarios[i] -> getMaterial(j) -> prestar();  //ya que deberia decirle al material que esta prestado (parte usuario y biblioteca)
            }
        }
    }
    archivo.close();
    cout << "Los usuarios se cargaron EXISTOSAMENTE!" << endl;
}

int main(){
    //aqui linea de codigo para cargar los archivos txt (creo que ya entendi como o eso espero)
    Usuario* temp;
    MaterialBibliografico* tempMat;
    MaterialBibliografico* tempMat;
    Usuario* usuarios[100] = {nullptr};
    int contadorUsuarios = 0;
    MaterialBibliografico* biblioteca[100] = {nullptr};  //lo voy creando acá pero no se si por ejemplo quieres crear otra clase
    int contador = 0;                 //tipo biblioteca o algo asi y ahí ir creando las listas de material y usuarios

    cargarDatos(biblioteca, contador);
    cargarUsuarios(usuarios, contadorUsuarios);

    cargarDatos(biblioteca, contador);
    cargarUsuarios(usuarios, contadorUsuarios);

    bool menu = true;
    while(menu){
        try {            
            int opcion = mostrarOpciones();
            switch(opcion){
                case 0:
                    guardarDatos(biblioteca, contador);
                    guardarUsuarios(usuarios, contadorUsuarios);
                    guardarDatos(biblioteca, contador);
                    guardarUsuarios(usuarios, contadorUsuarios);
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
                    contador++;
                    break;

                case 3:
                    registrarUsuario(usuarios, contadorUsuarios); 
                    contadorUsuarios++;
                    break;

                case 4:
                    temp = buscarUsuario(usuarios, contadorUsuarios);                        //necesito buscarUsuario para eliminarlo en primer lugar
                    if (temp != nullptr) {
                        cout << "Usuario encontrado: " << temp->getNombre() << endl;
                        tempMat = buscarMaterial(biblioteca, contador);
                        if (tempMat != nullptr) {
                            temp ->prestarMaterial(tempMat);
                            cout << "El material " << tempMat->getNombre() << " se ha prestado exitosamente a " << temp->getNombre() << endl;
                            } else {
                            cout << "Material no encontrado." << endl;
                            cout << " " << endl;
                            }
                        tempMat = buscarMaterial(biblioteca, contador);
                        if (tempMat != nullptr) {
                            temp ->prestarMaterial(tempMat);
                            cout << "El material " << tempMat->getNombre() << " se ha prestado exitosamente a " << temp->getNombre() << endl;
                            } else {
                            cout << "Material no encontrado." << endl;
                            cout << " " << endl;
                            }
                    } else {
                        cout << "Usuario no encontrado." << endl;
                        cout << " " << endl;
                    }
                    break;
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
                    temp = buscarUsuario(usuarios, contadorUsuarios);
                    if (temp != nullptr) {
                        cout << "Los materiales prestados del usuario: " << temp->getNombre() << "son: " << endl;
                        temp->mostrarMaterialesPrestados();
                    } else {
                        cout << "Usuario no encontrado." << endl;
                        cout << " " << endl;
                    }
                    break;

                default:
                    cout << "Opción inválida. Intente nuevamente..." << endl;
                    cout << " " << endl;
                    cout << " " << endl;
                    break;
                case 7: 
                for (int i = 0; i < contador; ++i) {    
                        if (Libro* libro = dynamic_cast<Libro*>(biblioteca[i])) {
                            libro->mostrarInformacion();
                        } else if (Revista* revista = dynamic_cast<Revista*>(biblioteca[i])) {
                            revista->mostrarInformacion();
                        }
                }
                break;
                case 8:
                buscarMaterialPorTitulo(biblioteca, contador);
                break;
                case 9:
                buscarMaterialPorAutor(biblioteca, contador);
                break;
                case 10:
                 temp = buscarUsuario(usuarios, contadorUsuarios);                        //necesito buscarUsuario para eliminarlo en primer lugar
                    if (temp != nullptr) {
                        cout << "Usuario encontrado: " << temp->getNombre() << endl;
                        tempMat = buscarMaterial(biblioteca, contador);
                        if (tempMat != nullptr) {
                            temp ->devolverMaterial(tempMat);
                            cout << "El material " << tempMat->getNombre() << " se ha devuelto exitosamente de parte de " << temp->getNombre() << endl;
                            } else {
                            cout << "Material no encontrado." << endl;
                            cout << " " << endl;
                            }
                    } else {
                        cout << "Usuario no encontrado." << endl;
                        cout << " " << endl;
                    }      
                break;
            }
        } catch (const invalid_argument& e) {
            cout << e.what() << endl; //el what devuelve un mensaje descriptivo, establecido mas arriba
            cout << "Intentelo de nuevo"<< endl;
            cout << " " << endl;
        }
    }

    //esto tengo entendido que es para liberar la memoria al finalizar la ejecucion del menú...
    
    for(int i = 0; i < contador; i++){
        delete biblioteca[i];
    }
    
    for(int i = 0; i < contador; i++){
        delete biblioteca[i];
    }

    for(int j = 0; j < contadorUsuarios; j++){
        delete usuarios[j];
    }
    for(int j = 0; j < contadorUsuarios; j++){
        delete usuarios[j];
    }

    return 0;
}
