#include "Revista.h"
#include <iostream>
using namespace std;

Revista :: Revista(string nombre, string isbn, string autor, int numeroEdicion, string mesPublicacion) 
    : MaterialBibliografico(nombre, isbn, autor), numeroEdicion(numeroEdicion), mesPublicacion(mesPublicacion){
}

void Revista :: mostrarInformacion(){                                                  //nos muestra toda la informacion posible del elemento
    cout << "Libro: " << nombre << " (ISBN: " << isbn << ")" << endl;
    cout << "Autor: " << autor << " (Publicado: " << mesPublicacion << ")" << endl;
    cout << "Edición: " << numeroEdicion << endl;
    cout << "Estado: " << (prestado ? "Prestado" : "Disponible") << endl;
}

string Revista :: getNombre(){return nombre; }      //nos retorna un string, que es el nombre

string Revista :: getIsbn(){ return isbn;}          //nos retorna un string, que es el isbn

string Revista :: getAutor(){ return autor;}        //nos retorna un string, que es el autor

bool Revista :: getPrestado(){return prestado;}     //nos retorna un bool, que es el estado

int Revista :: getNumEdicion(){ return numeroEdicion;} //nos retorna un int, que es el numero de edicion

string Revista :: getMesPublicacion(){return mesPublicacion;} //nos retorna un string, que es el mes de publicacion

Revista :: ~Revista(){          //destruimos el objeto
}