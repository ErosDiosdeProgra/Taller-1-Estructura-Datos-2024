#pragma once
#include <iostream>
#include <string>    //no se que tan necesario sea este pero lo puse por si acaso dado que resumen puede ser un string muy largo
using namespace std;
#include "MaterialBibliografico.h"

class Libro : public MaterialBibliografico {
    private:
        string fechaPublicacion;
        string resumen;

    public:
        Libro(string nombre, string isbn, string autor, string fechaPublicacion, string resumen);
        string getNombre();                                                        
        string getIsbn();                                                          
        string getAutor();
        bool getPrestado();
        string getFechaPublicacion();
        string getResumen();
        void mostrarInformacion() override;
        ~Libro();
};