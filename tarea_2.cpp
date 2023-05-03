#include "ArrayPersonaje.h"
#include<iostream>
using namespace std;
int main(){
    DataPersonaje D1;
    string nombre;
    int opc, posicion;
    for( ; ; ){
        cout<<"\t(1) Agregar Personaje "<<endl;
        cout<<"\t(2) Listar Personajes "<<endl;
        cout<<"\t(3) Buscar Personaje "<<endl;
        cout<<"\t(4) Eliminar Personaje "<<endl;
        cout<<"\t(5) Insertar Personaje "<<endl;
        cout<<"\t(6) Salir "<<endl;
        cin>>opc;
        cout<<"\n";
        switch(opc){
            case 1:
                D1.PushBack();
                cout<<"\n";
                break;
            case 2:
                D1.listar();
                cout<<"\n";
                break;
            case 3: 
                cout<<"Nombre? ";cin>>nombre;
                D1.buscar(nombre);
                cout<<"\n";break;
            case 4:
                cout<<"Nombre? ";cin>>nombre;
                D1.eliminar(nombre);
                cout<<"\n";break;
            case 5: 
                cout<<"Posicion ";cin>>posicion;
                D1.Ingresar(posicion);
                cout<<"\n";break;
            case 6: cout<<"\tBYE";return 0;
        }
    }
}