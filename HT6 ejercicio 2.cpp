/* Modificar el número de unidades vendidas, solicitando al usuario el día y código de articulo 
(modificación del archivo) ? Eliminación de un día especifico de venta (modificación del archivo)?
 Calcular el total recaudado por modelo en los 30 días. ? Calcular cuál fue el modelo que se vendió 
 mas en los 30 días  */
 
#include <iostream>
#include <fstream>
#include <string>
#include <iomanip>
using namespace std;

void archivo();
void datos_guardados();
void eliminar();
void editar_reg();

void menu(){
	int ops;
	
	do{
	
		cout<<"-------------------------------------"<<endl;
		cout<<"        SELECCIONE SU OPCION        "<<endl;
		cout<<"-------------------------------------"<<endl;
		cout<<"1. ARCHIVO"<<endl;
		cout<<"2. DATOS GUARDADOS "<<endl;
		cout<<"3. ELIMIMAR REGISTROS GUARDADOS"<<endl;
		cout<<"4. MODIFICAR REGISTRO"<<endl;
		//cout<<" "<<endl;
		cin>>ops;
		system("cls");
		
		if(ops==1){
		
		archivo();
		system("cls");
		}
		else if(ops==2){
			datos_guardados();
			system("cls");
		}
			else if(ops==3){
				eliminar();
				system("cls");
			}
				else if(ops==4){
					editar_reg();
					system("cls");
			}
					else if(ops==5)
					break;
					else 
					break;
	
	}while(ops!=5);
		
}
int main(){
	menu();
}


/*En una librería se venden 4 modelos diferentes de cuadernos, con los siguientes precios: ?
 Modelo#1 – Q10.00 ? Modelo#2 – Q15.00 ? Modelo#3 – Q18.50 ? Modelo#4 – Q25.00 
 */

void archivo(){
	int  dia, op, s, n=1;
	int cantidad;
	int modelo;
	float compra;
	 
		cout<<"INGRESE EL NUMERO DEL DIA DE LA COMPRA 1 A 30"<<endl; 
		cin>>dia;
		//for(int i=0;i<=n;i++){
		//cout<<"CUANTOS CUADERNOS COMPRARA"<<i+1<<endl;
		//	cin>>n;
			
	cout<<"INGRESE LA CANTIDAD DE CUADERNOS A COMPRAR: "<<endl;			
	cin>>cantidad;
	cout<<"__________________________________________"<<endl;
	cout<<"INGRESE EL MODELO DEL CUADERNO A COMPRAR: "<<endl<<endl;
	cout<<"      Modelo#1 = Q10.00"<<endl;
	cout<<"      Modelo#2 = Q15.00"<<endl;
	cout<<"      Modelo#3 = Q18.50"<<endl;
	cout<<"      Modelo#4 = Q25.00"<<endl;
	cin>>modelo;
	

	//Calcular el total recaudado por modelo en los 30 días. 
	// Calcular cuál fue el modelo que se vendió mas en los 30 días 

	int mod=0;
	if(modelo==1){
	compra=10*cantidad;
		if(modelo==1)
		mod=modelo+mod;
	}
		{
		
		if(modelo==2){
		compra=15*cantidad;
		if(modelo==2)
		mod=modelo+modelo;
		}
			if(modelo==3){
			compra=18.50*cantidad;
			if(modelo==3)
			mod=modelo+modelo;
			}
				if(modelo==4){
				compra=25*cantidad;
					if(modelo==3)
					mod=modelo+modelo;
			}
				
			
}			
				
			//}
	ofstream archivo;
	archivo.open("libreria.txt", ios::app);
	archivo<<dia<<"\t"<<modelo<<"\t"<<cantidad<<"\t"<<compra<<endl;
	archivo.close();

}


 
void datos_guardados(){
		int  dia;
	int cantidad;
	int modelo;
	float compra;
	int mayormod=-1,i;
		ifstream archivo;
		string texto;
			cout<<"REGISTROS DE DE LAS VENTAS"<<endl<<endl;;
			cout<<"DIA"<<"  MODELO"<<"  CANTIDAD"<<"	PRECIO"<<endl;
		archivo.open("libreria.txt",ios::in);
		if(archivo.fail()){
			cout<<"EL ARCHIVO NO EXISTE"<<endl;
			}
			
			while(archivo>>dia>>modelo>>cantidad>>compra){
				
					cout<<setw(2)<<dia<<setw(6)<<modelo<<setw(9)<<cantidad<<setw(12)<<compra<<endl;
			
			}
			//Calcular cuál fue el modelo que se vendió mas en los 30 días 
			i++;
			if(modelo>mayormod){
			
				mayormod = modelo;
		}
			system("pause");
			archivo.close();
			//cout<<"el modelo mas vendido es"<<mayormod<<endl;
			
			
		}
		
void eliminar(){
	int dia, aux, flag;
	int  modelo;
	int cantidad;
	float compra;
	ifstream archivo_a;
	ofstream archivo_b;
	archivo_a.open("libreria.txt",ios::in);
	archivo_b.open("temporal.txt",ios::out);
		
	cout<<"INGRESE EL DIA A ELIMINAR "<<endl;
	cin>>aux;
	
	while(archivo_a>>dia>>modelo>>cantidad>>compra){
	system("cls");
		if(aux==dia){
		cout<<"Registro Eliminado"<<endl;
		flag=1;
	}else if(aux!=dia){
	//	cout<<"Registro Insertado"<<endl;
		archivo_b<<setw(2)<<dia<<setw(6)<<modelo<<setw(9)<<cantidad<<setw(12)<<compra<<endl;
	}
		
	}
	archivo_a.close();
	archivo_b.close();
	if(flag==1){
		remove("libreria.txt");
		rename("temporal.txt","libreria.txt");
	}
	cout<<"REGISTRO ACTUALIZADO"<<endl;	
	system("pause");
}

void editar_reg(){
		int dia, aux, flag;
	int  modelo;
	int cantidad;
	float compra;
	char resp;
	ifstream archivo_a;
	ofstream archivo_b;
	archivo_a.open("libreria.txt",ios::in);
	archivo_b.open("temporal.txt",ios::app);
	
	cout<<"INGRESE EL DIA QUE SE MODIFICARA"<<endl;
	cin>>aux;
	do{
		cout<<"INGRESE EL NUEVO MODELO "<<endl;
		cin>>modelo;
		cout<<"INGRESE LA CANTIDAD A MODIFICAR"<<endl;
		cin>>cantidad;
		cout<<"\n\nSEGURO QUE DESEA MODIFICAR EL REGISTRO S/N"<<endl;
		cin>>resp;
		cout<<"\n"<<endl;
		resp=toupper (resp);
	}while (resp!='S');
	while(archivo_a>>dia>>modelo>>cantidad>>compra){
		if(aux==dia){
			archivo_b<<setw(2)<<dia<<setw(6)<<modelo<<setw(9)<<cantidad<<setw(12)<<compra<<endl;
			cout<<"REGISTROS ACTUALIZADO"<<endl;
			flag=1;
		
		 system("pause");
		}    else if(aux!=dia)
			archivo_b<<setw(2)<<dia<<setw(6)<<modelo<<setw(9)<<cantidad<<setw(12)<<compra<<endl;
	}
	archivo_a.close();
	archivo_b.close();
	if(flag==1){
		remove("libreria.txt");
		rename("temporal.txt","libreria.txt");
	}
}


