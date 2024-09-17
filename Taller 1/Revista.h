#pragma once
#include <iostream>
using namespace std;
#include "MaterialBibliografico.h"

class Revista : public MaterialBibliografico {
    private:
        int numeroEdicion;
        string mesPublicacion;

    public:
        Revista(string nombre, string isbn, string autor, int numeroEdicion, string mesPublicacion);
        string getNombre();                                                        
        string getIsbn();                                                          
        string getAutor();
        int getNumEdicion();
        string getMesPublicacion();
        bool getPrestado();
        void mostrarInformacion() override;
        ~Revista();
};