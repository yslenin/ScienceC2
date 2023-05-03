#define PERSONAJE_H
#include<iostream>
using namespace std;
class Personaje{
    private:
        char *nombre=new char[100];
        char *especie=new char[100];
        char *tipo=new char[100];
        char *genero=new char[100];
        char *tamanio=new char[100];
    public:
        void llenar();
        void mostrar();
        char* getnombre();
};
void Personaje::llenar(){
    cout<<"Nombre: ";cin>>nombre;
    cout<<"Especie: ";cin>>especie;
    cout<<"Tipo: ";cin>>tipo;
    cout<<"Genero: ";cin>>genero;
    cout<<"Tamanio: ";cin>>tamanio;
}
void Personaje::mostrar(){
    cout<<"Nombre: "<<nombre<<endl;
    cout<<"Especie: "<<especie<<endl;
    cout<<"Tipo: "<<tipo<<endl;
    cout<<"Tamanio: "<<tamanio<<endl;
    cout<<"\n";
}
char* Personaje::getnombre(){
    return nombre;
}