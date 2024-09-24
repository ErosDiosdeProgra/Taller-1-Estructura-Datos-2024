#include "MaterialBibliografico.h"
#include <iostream>
using namespace std;

MaterialBibliografico :: MaterialBibliografico(string nombre, string isbn, string autor) : nombre(nombre), isbn(isbn), 
    autor(autor), prestado(false){
}

bool MaterialBibliografico :: estaPrestado(){return prestado;}

void MaterialBibliografico :: prestar(){
    prestado = true;}

void MaterialBibliografico :: devolver(){
    prestado = false;}

void MaterialBibliografico :: mostrarInformacion(){
}

MaterialBibliografico :: ~MaterialBibliografico(){
}

