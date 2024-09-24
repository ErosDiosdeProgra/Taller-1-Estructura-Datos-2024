#pragma once
#include <iostream>
using namespace std;
#include "MaterialBibliografico.h"

class Usuario {
    private:
        string nombre;
        string id;
        MaterialBibliografico* materialesPrestados[5];
        int materialPrestado;  //no se si existe un .size() como en java xd, por eso puse esto

    public:
        Usuario(string nombre, string id);
        bool prestarMaterial(MaterialBibliografico* material);             //estos 2 (prestar y devolver) deberian ser bool??
        bool devolverMaterial(MaterialBibliografico* material);
        void mostrarMaterialesPrestados();
        ~Usuario();
};