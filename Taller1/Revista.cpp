#include "Revista.h"
#include <iostream>
using namespace std;

Revista :: Revista(string nombre, string isbn, string autor, int numeroEdicion, string mesPublicacion) 
    : MaterialBibliografico(nombre, isbn, autor), numeroEdicion(numeroEdicion), mesPublicacion(mesPublicacion){
}

void Revista :: mostrarInformacion(){
    cout << "Libro: " << nombre << " (ISBN: " << isbn << ")" << endl;
    cout << "Autor: " << autor << " (Publicado: " << mesPublicacion << ")" << endl;
    cout << "Edición: " << numeroEdicion << endl;
    cout << "Estado: " << (prestado ? "Prestado" : "Disponible") << endl;
}

string Revista :: getNombre(){return nombre; }

string Revista :: getIsbn(){ return isbn;}

string Revista :: getAutor(){ return autor;}

bool Revista :: getPrestado(){return prestado;}

int Revista :: getNumEdicion(){ return numeroEdicion;}

string Revista :: getMesPublicacion(){return mesPublicacion;}

Revista :: ~Revista(){
}