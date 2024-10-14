#include "Libro.h"
#include <iostream>
using namespace std;

Libro :: Libro(string nombre, string isbn, string autor, string fechaPublicacion, string resumen) 
    : MaterialBibliografico(nombre, isbn, autor), fechaPublicacion(fechaPublicacion), resumen(resumen){
}

void Libro :: mostrarInformacion(){                                             //nos muestra toda la informacion posible del elemento
    cout << "Libro: " << nombre << " (ISBN: " << isbn << ")" << endl;           
    cout << "Autor: " << autor << " (Publicado: " << fechaPublicacion << ")" << endl;
    cout << "Resumen: " << resumen << endl;
    cout << "Estado: " << (prestado ? "Prestado" : "Disponible") << endl;
}

string Libro :: getNombre(){return nombre;}                             //nos retorna un string, que es el nombre

string Libro :: getIsbn(){return isbn;}                                 //nos retorna un string, que es el isbn

string Libro :: getAutor(){return autor;}                               //nos retorna un string, que es el autor

bool Libro :: getPrestado(){return prestado;}                           //nos retorna un bool, que es el estado

string Libro :: getFechaPublicacion(){return fechaPublicacion;}         //nos retorna un string, que es la fecha de publicacion

string Libro :: getResumen(){ return resumen;}                          //nos retorna un string, que es el resumen

Libro :: ~Libro(){                                                      //destruimos el objeto
}