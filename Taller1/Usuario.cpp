#include "Usuario.h"
#include <iostream>
using namespace std;

Usuario :: Usuario(string nombre, string id) : nombre(nombre), id(id), materialPrestado(0){
    for(int i = 0; i < 5; ++i){                 //establecemos que el arreglo que contenga materiales prestados este lleno de punteros nulos 
        materialesPrestados[i] = nullptr;
    }
}

bool Usuario :: prestarMaterial(MaterialBibliografico* material){           //verificamos si es posible que un material pueda ser prestado,
                                                                            //luego de verificar el caso (de lista llena o prestado) recien lo prestamos (retorna bool)
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

string Usuario :: getNombre(){return nombre;}       //retornamos un string, que es el nombre del usuario

string Usuario :: getId(){return id;}               //retornamos un string, que es el id del usuario

int Usuario :: getMaterialPrestado(){return materialPrestado;}      //retornamos un int, que es la posicion de lista del material prestado

bool Usuario :: devolverMaterial(MaterialBibliografico* material){  //revisa si el material se encuentra aca, con el fin de devolverlo
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

void Usuario :: mostrarMaterialesPrestados(){                                   //por todos los materiales presentes, se llama a la funcion mostrarInformacion
                                                                                //que se encargara de mostrar TODOS los datos del material
    cout << nombre << " tiene los siguientes materiales prestados" << endl;
    for(int i = 0; i < materialPrestado; i++){
        materialesPrestados[i] -> mostrarInformacion();
    }
}

MaterialBibliografico* Usuario :: getMaterial(int i){                           //por todos los materiales presentes, se retornan los punteros de estas
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