

#include <iostream>
#include<conio.h>
using namespace std;
void mostrar();
void ingreso();
void eliminar();
void buscar();
struct datos
{
	int anio;
	string marca;
	string placa;
	string color;
	string modelo;
	string fecha;
	
	datos *direccion_sig;
}*primero,*cola,*ultimo=NULL;

int main(int argc, char** argv) {

int opcion;
	while(true){
		system("cls");
		cout<<"1 Ingreso de datos a la Cola"<<endl;
		cout<<"2 Mostrar Datos de la cola"<<endl;
		cout<<"3 Eliminar datos de la cola"<<endl;
		cout<<"4 Buscar datos en la cola"<<endl;
		cin>>opcion;
		switch(opcion){
			
			case 1:{
			system ("cls");
				ingreso();			
				break;
			}
			case 2:{
				system("cls");
				mostrar();
				break;
			}
			case 3:{
				system("cls");
				eliminar();
				break;
			}
			case 4:{
				system("cls");
				buscar();
				break;
			}
		}
	}
	return 0;
}	
	

void ingreso(){
	
	cola=new(datos);
	cout<<"Ingrese dato a la cola"<<endl;
	cout<<"Ingrese el año:"<<endl;
	cin>>cola->anio;
	cout<<"Ingrese la marca:"<<endl;
	cin>>cola->marca;
	cout<<"Ingrese el color:"<<endl;
	cin>>cola->color;
	cout<<"Ingrese la placa:"<<endl;
	cin>>cola->placa;
	cout<<"Ingrese el modelo:"<<endl;
	cin>>cola->modelo;
	cout<<"Ingrese fecha de ingreso:"<<endl;
	cin>>cola->fecha;
	
	if(ultimo!=NULL){
		ultimo->direccion_sig=cola;
		cola->direccion_sig=NULL;
		ultimo=cola;
		cout<<"Dato Ingresado "<<endl;
	     getch();
	}

	else {
		primero=ultimo=cola;
		cout<<"Primer dato ingresado"<<endl;
		//NO mostrando direccion cout<<primero<<" "<<ultimo<<" "<<cola<<endl;
	}
	//	cout<<ultimo->direccion_sig<<" "<<cola->direccion_sig<<endl;
}
void mostrar(){
	if(ultimo==NULL){
		cout<<"La cola esta vacia"<<endl;
		return;
	}
	cola=primero;
	cout<<"Los dato de la cola son: "<<endl;
	while(cola!=NULL){
		cout<<"Marca:";
		cout<<cola->marca<<endl;
		cout<<"Modelo:";
		cout<<cola->modelo<<endl;
		cout<<"aÑo:";
		cout<<cola->anio<<endl;
		cout<<"Color:";
		cout<<cola->color<<endl;
		cout<<"Placa:";
		cout<<cola->placa<<endl;
		cout<<"Fecha:";
		cout<<cola->fecha<<endl;
		cola=cola->direccion_sig;
		cout<<"\tSiguiente:\n";
}
	getch();
}
void eliminar(){
	if(primero!=NULL){
		cola=primero;
		cout<<"Elemento Eliminado "<<primero->placa<<endl;
		primero=cola->direccion_sig;
		delete(cola);
		if(primero==NULL){
			cola=NULL;
			ultimo=NULL;
		}
	}
	else{
		cout<<"La cola esta vacia"<<endl;
	}
	getch();
}
void buscar(){
	if(primero==NULL){
		cout<<"La cola esta vacia"<<endl;
		return;
	}
	cola=primero;
	bool encontrado=false;
	string buscardatos;
	cout<<"Ingrese dato a buscar"<<endl;
	cin>>buscardatos;
	while(cola!=NULL){
		if(buscardatos==cola->placa){
			cout<<"Encontrado, los datos del vehiculo son: "<<cola->placa<<endl;
			
			encontrado=true;
			break;
		} 
		cola=cola->direccion_sig;
	}
	if(encontrado==false){
		cout<<"No se encontro el dato de vehiculo"<<endl;
	}
getch();
}
