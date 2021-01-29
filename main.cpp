#include <iostream>
#include <array>
#include <string.h>
#include <ctime>
#include <random>
using namespace std;

/* run this program using the console pauser or add your own getch, system("pause") or input loop */

//Ejercicio 1

void ejercicio1(string cadena){
	
	//utilizar la cadena como arreglo de caracteres
	int resp=0;
	for(int i = 0; i < cadena.size();i++){
		char aux = cadena[i];
		//solamente la A porque ya se sabe cuales son las letras que proceden
		if(aux=='A' && i==1){
			//revisar si lo que le sigue al and es 0 u 1
			if((cadena[i-1]=='1' && cadena[i+3]=='0')||(cadena[i-1] == '0' && cadena[i+3] == '1')||(cadena[i-1] == '0' && cadena[i+3] == '0')){
				resp=0;
			}else if(cadena[i-1]=='1' && cadena[i+3]=='1'){
				resp=1;
			}else{
				cout<<"revise la cadena que ingreso..."<<endl;
			}
		
		}
		else if(aux=='A'){
			if((resp==1 && cadena[i+3] == '0')||(resp==0 && cadena[i+3] == '1')||(resp==0 && cadena[i+3] == '0')){
				resp=0;
			}else{
				resp=1;
			}
		}
		//revisar si es or con el caracter o
		else if(aux=='O' && i==1){
			if(resp=='0' && cadena[i+2]=='0' ){
				resp=0;
			}else{
				resp=1;
			}
		}else if(aux=='O'){
			if(resp==0 && cadena[i+2]=='0'){
				resp=0;
			}else{
				resp=1;
			}
		}
	}//fin del for que recorre la cadena
	if(resp!=1){
		cout<<"False"<<endl;
	}else{
		cout<<"True"<<endl;
	}
}

//Ejercicio 2

void imprimirArr(int arreglo[]){
	for(int i = 0; i < 20; i++){
		cout<<"["<<arreglo[i]<<"] ";
	}
	cout<<endl;
}

void recursivo2(int arreglo[],int tam){
	if(tam==20){
		//si ya llega al final se imprime el arreglo nuevo en el main
		
	}else{
		//recorrer con metodo burbuja
		int aux=0;
		for(int i = 0; i < 20; i++){
			for(int j = 0; j < 20; j++){
				if(arreglo[j]>arreglo[j+1]){
					aux=arreglo[j];
					arreglo[j]=arreglo[j+1];
					arreglo[j+1]=aux;
				}
				
				
			}//fin del for interno
			imprimirArr(arreglo);
		}//fin del for externo
		
		
		
		tam++;
	}
}

//Ejercicio 3

double recursivo3(double n,double cont, double k,double resp){
	double aux=0;
	if(cont==n){
		//termina el ciclo
		
		return resp+aux;
	}else{
		aux=(((2*k)-1)/(k*(k+1)));
		return recursivo3(n,cont+1,k,resp+aux);
	}
}

int main(int argc, char** argv) {
	
	int opcion = 0;
	while(opcion!=4){
		cout<<"MENU\n1)Ejercicio 1\n2)Ejercicio 2\n3)Ejercicio 3\n4)Salir"<<endl;
		cout<<"Ingrese la opcion que desea realizar: ";
		cin>>opcion;
		switch(opcion){
			case 1:{
				string cadena;
				
				cout<<"Ingrese una cadena de AND y OR: ";
				cin>>cadena;
				
				ejercicio1(cadena);
				
				break;
			}//fin del case 1
			
			case 2:{
				
				int arreglo[20];
				
				//llenar el arreglo con random
				for(int i = 0; i < 20; i++){
					arreglo[i]=0+(rand()%99);
				}
				
				//imprimir original
				cout<<"Arreglo Original\n";
				for(int i = 0; i < 20; i++){
					cout<<"["<<arreglo[i]<<"] ";
				}
				cout<<endl;
				
				cout<<endl<<"Iteraciones"<<endl;
				recursivo2(arreglo,0);
				
				//imprimir el final
				cout<<endl<<"Arreglo Ascendente"<<endl;
				for(int i = 0; i < 20; i++){
					cout<<"["<<arreglo[i]<<"] ";
				}
				
				cout<<endl;
				
				break;
			}//fin del case 2
			case 3:{
				
				double n,k=1,cont=0,resp=0;
				
				cout<<"Ingrese un numero: ";
				cin>>n;
				
				while(n<1){
					cout<<"Asegurese de ingresar un numero mayor de 1"<<endl;
					cout<<"Ingrese un numero: ";
					cin>>n;
				}
				
				cout<<recursivo3(n,cont,k,resp)<<endl;
				
				
				break;
			}//fin del case 3
			
			case 4:{
				cout<<"Adios, tenga buen dia";
				break;
			}//fin del case 4 de salida del menu
			
			default:{
				cout<<"Asegurese de ingresar una de las opciones del menu"<<endl;
				break;
			}
		}//fin del switch
	}//fin del while principal
	
	return 0;
}
