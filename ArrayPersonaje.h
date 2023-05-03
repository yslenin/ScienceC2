#include<iostream>
#include "Personaje.h"
bool compare(string cadena1, char *cadena2){
    int i=0;
    for( ; cadena2[i]!='\0' && cadena2[i]!='\0'  ; i++){
        if(cadena1[i]!=cadena2[i])
            return false;
    }
    if( cadena1[i]=='\0' && cadena2[i]=='\0')
        return true;
    return false;
}
class DataPersonaje{
    private:
        Personaje *listaPersonaje[100];
        int actualPersonaje;
    public:
        DataPersonaje();
        void Ingresar(int);
        void PushBack();
        void listar();
        void buscar(string);
        void eliminar(string);
};
DataPersonaje::DataPersonaje(){
    for(int i=0;i<100;i++){
        listaPersonaje[i]=new Personaje;
    }
    actualPersonaje=0;
}
void DataPersonaje::Ingresar(int posicion){
    Personaje *aux;
    if(posicion>=actualPersonaje){
        cout<<"La poscicion maxima es: "<<actualPersonaje-1;
    }else{
        for(int i=actualPersonaje;i>posicion;i--){
            aux=listaPersonaje[i];
            listaPersonaje[i]=listaPersonaje[i-1];
            listaPersonaje[i-1]=aux;
        }
        actualPersonaje++;
        listaPersonaje[posicion]->llenar();
    }
}
void DataPersonaje::PushBack(){
    listaPersonaje[actualPersonaje]->llenar();
    actualPersonaje++;
}
void DataPersonaje::listar(){
    for(int i=0;i<actualPersonaje;i++){
        cout<<"\tPersonaje "<<i+1<<"\n";
        listaPersonaje[i]->mostrar();
    }
}
void DataPersonaje::buscar(string nombre){
    bool cond=true;
    for(int i=0;i<actualPersonaje;i++){
        if(compare(nombre, listaPersonaje[i]->getnombre())){
            listaPersonaje[i]->mostrar();
            cond=false;
            break;
        }
    }
    if(cond){
        cout<<"No se encontro el Personaje: ";
    }
}
void DataPersonaje::eliminar(string nombre){
    int i_eli;
    bool cond=true;
    for(int i=0;i<actualPersonaje;i++){
        if(compare(nombre,listaPersonaje[i]->getnombre())){
            i_eli=i;
            cond=false;
            break;
        }
    }
    if(cond){
        cout<<"No se encontro al Personaje ";
    }else{
        for(int i=i_eli;i<actualPersonaje-1;i++){
            listaPersonaje[i]=listaPersonaje[i+1];
        }
        //listaPersonaje[actualPersonaje-1]=new Personaje;
        actualPersonaje--;
    }
}