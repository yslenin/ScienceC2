#include<iostream>
using namespace std;
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