#include "Libro.h"
#include <iostream>
using namespace std;

Libro :: Libro(string nombre, string isbn, string autor, string fechaPublicacion, string resumen) 
    : MaterialBibliografico(nombre, isbn, autor), fechaPublicacion(fechaPublicacion), resumen(resumen){
}

void Libro :: mostrarInformacion(){
    cout << "Libro: " << nombre << " (ISBN: " << isbn << ")" << endl;
    cout << "Autor: " << autor << " (Publicado: " << fechaPublicacion << ")" << endl;
    cout << "Resumen: " << resumen << endl;
    cout << "Estado: " << (prestado ? "Prestado" : "Disponible") << endl;
}

string Libro :: getNombre(){return nombre;}

string Libro :: getIsbn(){return isbn;}

string Libro :: getAutor(){return autor;}

bool Libro :: getPrestado(){return prestado;}

string Libro :: getFechaPublicacion(){return fechaPublicacion;}

string Libro :: getResumen(){ return resumen;}

Libro :: ~Libro(){
}