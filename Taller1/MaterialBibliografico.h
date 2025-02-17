#pragma once
#include <iostream>
using namespace std;

class MaterialBibliografico{
    protected:
        string nombre;
        string isbn;
        string autor;
        bool prestado;

    public:
        MaterialBibliografico(string nombre, string isbn, string autor);
        string getNombre();
        string getIsbn();
        string getAutor();
        bool estaPrestado();
        void prestar();
        void devolver();
        virtual void mostrarInformacion();
        virtual ~MaterialBibliografico(); 
};