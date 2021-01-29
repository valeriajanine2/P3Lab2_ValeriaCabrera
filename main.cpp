#include <iostream>
#include <array>
#include <string>
#include <ctime>
#include <random>
using namespace std;

/* run this program using the console pauser or add your own getch, system("pause") or input loop */

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

int main(int argc, char** argv) {
	
	int opcion = 0;
	while(opcion!=4){
		cout<<"MENU\n1)Ejercicio 1\n2)Ejercicio 2\n3)Ejercicio 3\n4)Salir"<<endl;
		cout<<"Ingrese la opcion que desea realizar: ";
		cin>>opcion;
		switch(opcion){
			case 1:{
				
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
