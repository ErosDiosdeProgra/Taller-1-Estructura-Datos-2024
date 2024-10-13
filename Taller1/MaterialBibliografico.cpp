#include "MaterialBibliografico.h"
#include <iostream>
using namespace std;

MaterialBibliografico :: MaterialBibliografico(string nombre, string isbn, string autor) : nombre(nombre), isbn(isbn), 
    autor(autor), prestado(false){  //falso ya que cada que se crea un objeto, este no ha sido prestado
}

string MaterialBibliografico :: getNombre(){return nombre;}

string MaterialBibliografico :: getIsbn(){return isbn;}

string MaterialBibliografico :: getAutor(){return autor;}

bool MaterialBibliografico :: estaPrestado(){return prestado;}

void MaterialBibliografico :: prestar(){
    prestado = true;}

void MaterialBibliografico :: devolver(){
    prestado = false;}

void MaterialBibliografico :: mostrarInformacion(){
}

MaterialBibliografico :: ~MaterialBibliografico(){
}

