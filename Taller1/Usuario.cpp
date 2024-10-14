#include "Usuario.h"
#include <iostream>
using namespace std;

Usuario :: Usuario(string nombre, string id) : nombre(nombre), id(id), materialPrestado(0){
    for(int i = 0; i < 5; ++i){
        materialesPrestados[i] = nullptr;
    }
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

string Usuario :: getNombre(){return nombre;}

string Usuario :: getId(){return id;}

int Usuario :: getMaterialPrestado(){return materialPrestado;}

bool Usuario :: devolverMaterial(MaterialBibliografico* material){
    if(materialPrestado == 0){
        cout << "No tiene ningún Material Bibliográfico prestado!!" << endl;
        cout << " " << endl;
        return false;
    }

    for(int i = 0; i < materialPrestado; ++i){
        if(materialesPrestados[i] == material){
            materialesPrestados[i] -> devolver();
            materialesPrestados[i] = materialesPrestados[--materialPrestado]; //esto es para mover el ultimo al espacio vacio
            return true;
        }
    }
    return false;
}

void Usuario :: mostrarMaterialesPrestados(){
    cout << nombre << " tiene los siguientes materiales prestados" << endl;
    for(int i = 0; i < materialPrestado; i++){
        materialesPrestados[i] -> mostrarInformacion();
    }
}

MaterialBibliografico* Usuario :: getMaterial(int i){
    if(i >= 0 && i < materialPrestado){
        return materialesPrestados[i];
    }

    return nullptr;
}

Usuario :: ~Usuario(){
    for(int i = 0; i < 5; ++i){
        delete materialesPrestados[i];  //para eliminar los punteros de la lista de materiales de cada usuario
    }
}