#include "Usuario.h"
#include <iostream>
using namespace std;

Usuario :: Usuario(string nombre, string id) : nombre(nombre), id(id), materialPrestado(0){
}

bool Usuario :: prestarMaterial(MaterialBibliografico* material){
    if(materialPrestado >= 5){
        cout << "Limite alcanzado. NO se puede pedir prestado más de 5 Materiales" << endl;
        cout << " " << endl;
        return false;
    }

    if(material -> estaPrestado()){
        cout << "El Recurso que quieres solicitar ya ha sido prestado" << endl;
        cout << " " << endl;
        return false;
    }

    materialesPrestados[materialPrestado] = material;
    materialPrestado++;
    material -> prestar();
    return true;
}

bool Usuario :: devolverMaterial(MaterialBibliografico* material){
    return false;
}