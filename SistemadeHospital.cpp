//Systema de Hospital .....
#include<iostream>
#include<fstream>
#include<cstdlib>
#include<conio.h>
#include<time.h>
#include<iomanip>

using namespace std;



 
/*                Estructura de los nodos de la cola      
------------------------------------------------------------------------*/
struct nodo
{
    int nro;
    struct nodo *sgte;
};
 
 
/*                      Estructura de la cola      
------------------------------------------------------------------------*/
struct cola
{
    nodo *delante;
    nodo *atras  ;
};

/*                        Encolar elemento      
------------------------------------------------------------------------*/
void encolar( struct cola &q, int valor )
{
     struct nodo *aux = new(struct nodo);
     
     aux->nro = valor;
     aux->sgte = NULL;
     
     if( q.delante == NULL)
         q.delante = aux;   // encola el primero elemento
     else
         (q.atras)->sgte = aux;
         
     q.atras = aux;        // puntero que siempre apunta al ultimo elemento
     
}
 
/*                        Desencolar elemento      
------------------------------------------------------------------------*/
int desencolar( struct cola &q )
{
     int num ;
     struct nodo *aux ;
     
     aux = q.delante;      // aux apunta al inicio de la cola
     num = aux->nro;
     q.delante = (q.delante)->sgte;
     delete(aux);          // libera memoria a donde apuntaba aux
     
     return num;
}
 
/*                        Mostrar Cola      
------------------------------------------------------------------------*/
void muestraCola( struct cola q )
{
     struct nodo *aux;
     
     aux = q.delante;
         
     while( aux != NULL )
     {
            cout<<"   "<< aux->nro ;
            aux = aux->sgte;
     }    
}
/*              Eliminar todos los elementos de la Cola      
------------------------------------------------------------------------*/
void vaciaCola( struct cola &q)
{
     struct nodo *aux;
     
     while( q.delante != NULL)
     {
            aux = q.delante;
            q.delante = aux->sgte;
            delete(aux);
     }
     q.delante = NULL;
     q.atras   = NULL;
     
}
/*                        Menu de opciones    
------------------------------------------------------------------------*/
void menu()
{
    cout<<"\n\t IMPLEMENTACION DE TURNOS EN HOSPITAL\n\n";
    cout<<" 1. ASIGNAR TURNO                               "<<endl;
    cout<<" 2. QUITAR  TURNO                            "<<endl;
    cout<<" 3. MOSTRAR TURNOS                          "<<endl;
    cout<<" 4. VACIAR  TURNOS                          "<<endl;
    cout<<" 5. SALIR                                 "<<endl;
 
    cout<<"\n INGRESE OPCION: ";
}

int main()
{

char fname[20];
time_t rawtime;
struct tm * timeinfo;
time ( &rawtime );
timeinfo = localtime ( &rawtime );
//printing the welcome note
re:
cout<<"\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\t\t\t\t\t@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@\n";
cout<<"\t\t\t\t\t@@ _______________________________________________________________________________________ @@\n";
cout<<"\t\t\t\t\t@@|                                           		                                  |@@\n";
cout<<"\t\t\t\t\t@@|                                           		                                  |@@\n";
cout<<"\t\t\t\t\t@@|                                           		                                  |@@\n";
cout<<"\t\t\t\t\t@@|                                           		                                  |@@\n";
cout<<"\t\t\t\t\t@@|                                           		                                  |@@\n";
cout<<"\t\t\t\t\t@@|                                           		                                  |@@\n";
cout<<"\t\t\t\t\t@@|                              BIENVENIDOS AL                                           |@@\n";
cout<<"\t\t\t\t\t@@|                                                                                       |@@\n";
cout<<"\t\t\t\t\t@@|                           SISTEMA DE HOSPITAL  2020                                   |@@\n";
cout<<"\t\t\t\t\t@@|                                                                                       |@@\n";
cout<<"\t\t\t\t\t@@|                                                                                       |@@\n";
cout<<"\t\t\t\t\t@@|                                                                                       |@@\n";
cout<<"\t\t\t\t\t@@|                                                                                       |@@\n";
cout<<"\t\t\t\t\t@@|                                                                                       |@@\n";
cout<<"\t\t\t\t\t@@|                                         -Proyecto Universitario 5to. semestre         |@@\n";
cout<<"\t\t\t\t\t@@|_______________________________________________________________________________________|@@\n";
cout<<"\t\t\t\t\t@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@\n\n\n\n\t\t\t\t\t";
system("pause");
system("cls");



int i;
system("pause");
system("cls");
//Dar opción al usuario para su elección.
b:
cout<<"\n\n\n\n\n\n\n\n\n\n\n\n\t\t\t\t\t\t\t\t  SYSTEMA DE HOSPITAL \n\n";	
cout<<"\n\n\t\t\t\t\t\tPor favor, elija entre las siguientes opciones \n\n";
cout<<"\t\t\t\t\t\t _________________________________________________________________ \n";
cout<<"\t\t\t\t\t\t|                                           	                  |\n";
cout<<"\t\t\t\t\t\t|             1  >> Agregar nuevo registro de paciente            |\n";
cout<<"\t\t\t\t\t\t|             2  >> Agregar informacion de diagnostico            |\n";
cout<<"\t\t\t\t\t\t|             3  >> Conozca la historia completa del paciente     |\n";
cout<<"\t\t\t\t\t\t|             4  >> Informacion sobre el hospital                 |\n";
cout<<"\t\t\t\t\t\t|             5  >> Turno de Pacientes                            |\n";
cout<<"\t\t\t\t\t\t|             6  >> Salir del Programa                            |\n";
cout<<"\t\t\t\t\t\t|_________________________________________________________________|\n\n";
a:cout<<"\t\t\t\t\t\tSelecciona una opcion: ";cin>>i;
if(i>6||i<1){cout<<"\n\n\t\t\t\t\t\tEleccion invalida\n";cout<<"\t\t\t\t\t\tIntentalo de nuevo...........\n\n";goto a;} //si la elección introducida es diferente a la elección dada



system("cls");

//mostrando la información sobre el hospital ........ opción 4
if(i==4)
{
	ifstream file;
	file.open("hos.txt");
		if(!file)
		{
		cout<<"\nError al abrir el archivo\n";goto b;
		}
		else
		{
		    cout<<"\n\n\n\n\n\n\n\t\t\t\t\t   ...........................Información sobre el hospital.............................\n\n";
		    string line;
			while(file.good())
			{
			getline(file,line);
			cout<<line<<"\n\t\t";
			}
			cout<<"\n\n\t\t";
			system("pause");
            system("cls");
			goto b;
		}
}



//Anexar información de diagnóstico del paciente según nombre, la edad y asignar turno ................. opción 5
if(i==5)
{
    fstream pat_file;
    cout<<"\n\nIngrese el nombre del archivo del paciente que se abrira : ";
    cin.ignore();
    gets(fname);
    system("cls");
	pat_file.open(fname, ios::in);
		if(!pat_file)
		{
		cout<<"\nError al abrir el archivo\n";goto b;
		}
		else
		{
		    cout<<"\n\n\n\n\t\t\t\t........................................ Informacion sobre "<<fname<<" ........................................\n\n\n\n";
		    string info;
			while(pat_file.good())
			{
			getline(pat_file,info);
			cout<<info<<"\n";
			}
			cout<<"\n";
			pat_file.close();
                                     	 struct cola q;
   
                                         q.delante = NULL;
                                         q.atras   = NULL;
   
   
                                         int dato;  // numero a encolar
                                         int op;    // opcion del menu
                                         int x ;    // numero que devuelve la funcon pop
   
                                         system("color 0b"); // color de texto en pantalla
 do
    {
        menu();  cin>> op;
 
        switch(op)
        {
            case 1:
 
                 cout<< "\n Digite la edad del paciente: "; cin>> dato;
                 //	int edad;
	
               	//cout<<"Digite su edad: "; 
               //	cin>>edad;
	
	if((dato>=0)&&(dato<=17)){  //Estable el rango de edad para asignar turnos a pacientes 
		cout<<"Usted es menor de edad va a la izquierda";
	}
	else{
		cout<<"Usted es mayor de edad va a la derecha";
      	}
                 encolar( q, dato );
                 cout<<"\n\n\t\tNumero " << dato << " de turno...\n\n";
            break;
 
 
            case 2:
 
                 x = desencolar( q );
                 cout<<"\n\n\t\tQuitar  "<< x <<" turno...\n\n";
            break;
                 
 
            case 3:
 
                 cout << "\n\n MOSTRANDO COLA DE TURNOS\n\n";
                 if(q.delante!=NULL) muestraCola( q );
                 else   cout<<"\n\n\tCola de turnos vacia...!"<<endl;
            break;
 
 
            case 4:
 
                 vaciaCola( q );
                 cout<<"\n\n\t\tHecho...\n\n";
            break;
           
         }
 
        cout<<endl<<endl;
        system("pause");  
		//system("cls");
 
    }while(op!=5);
   
   
    return 0;

			cout<<"\n\n";
			system("pause");
            system("cls");
			goto b;
		 }
 }

//Termina la opción 5 parte de los turnos 




//Agregar el registro del nuevo paciente .................. opción 1
if(i==1)
{
  time_t rawtime;
  struct tm * timeinfo;

  time ( &rawtime );
  timeinfo = localtime ( &rawtime );
  cout<<"\n\n\t\t\t\t\t\t\t\t"<< asctime (timeinfo);
  ofstream pat_file;
  char fname[20];
  cout<<"\n\n\n\nIngrese el nombre del archivo del paciente : ";
  cin.ignore();
  gets(fname);
  pat_file.open(fname);
  		if(!fname)
		{
		cout<<"\nError al abrir el archivo\n";goto b;
		}
		else
		{
                        struct patient_info
                        {
                            char nombre[20];
                            char direccion[100];
                            char telefono[10];
                            char edad[5];
                            char sexo[8];
                            char grupo_sanguineo[5];
                            char ef_antigua[50];
                            char id[15];
                        };

            patient_info ak;
            cout<<"\n********************************************************************\n";pat_file<<"\n********************************************************************\n\n";//fn1353 st
            cout<<"\nNombre : ";pat_file<<"Nombre : ";gets(ak.nombre);pat_file<<ak.nombre<<"\n";
            cout<<"\nDireccion : ";pat_file<<"Direccion : ";gets(ak.direccion);pat_file<<ak.direccion<<"\n";
            cout<<"\nNumero de Telefono : ";pat_file<<"Numero de telefono : ";gets(ak.telefono);pat_file<<ak.telefono<<"\n";
            cout<<"\nEdad : ";pat_file<<"Edad : ";gets(ak.edad);pat_file<<ak.edad<<"\n";
            cout<<"\nSexo : ";pat_file<<"Sexo : ";gets(ak.sexo);pat_file<<ak.sexo<<"\n";
            cout<<"\nGrupo sanguineo : ";pat_file<<"Grupo sanguineo : ";gets(ak.grupo_sanguineo);pat_file<<ak.grupo_sanguineo<<"\n";
            cout<<"\nCualquier enfermedad mayor sufrida antes : ";pat_file<<"Cualquier enfermedad mayor sufrida antes : ";gets(ak.ef_antigua);pat_file<<ak.ef_antigua<<"\n";
            cout<<"\nCodigo del paciente : ";pat_file<<"Codigo del paciente : ";gets(ak.id);pat_file<<ak.id<<"\n";
            cout<<"\n********************************************************************\n";pat_file<<"\n********************************************************************\n\n";
            cout<<"\nInformacion guardada con exito\n";
            }
  system("pause");
  system("cls");
  goto b;

}

//Anexar información de diagnóstico del paciente según la fecha ................. opción 2

if(i==2)
{
    fstream pat_file;
    cout<<"\n\nIngrese el nombre del archivo del paciente que se abrira : ";
    cin.ignore();
    gets(fname);
    system("cls");
	pat_file.open(fname, ios::in);
		if(!pat_file)
		{
		cout<<"\nError al abrir el archivo\n";goto b;
		}
		else
		{
		    cout<<"\n\n\n\n\t\t\t\t........................................ Informacion sobre "<<fname<<" ........................................\n\n\n\n";
		    string info;
			while(pat_file.good())
			{
			getline(pat_file,info);
			cout<<info<<"\n";
			}
			cout<<"\n";
			pat_file.close();
			pat_file.open(fname, ios::out | ios::app);
            cout<<"\n";
			cout<<"Agregar mas informacion en el archivo del paciente................on : "<<asctime (timeinfo);pat_file<<"Descripcion de "<<asctime (timeinfo)<<"\n";
                            struct app
                            {
                                char sintomas[500];
                                char diagnosis[500];
                                char medicine[500];
                                char addmission[30];
                                char ward[15];
                                char medico[20];
                                char codigo[10];
                                char nombre[30];
                                
                            };
            app add;
            cout<<"\nSintomas: "; pat_file<<"Sintomas: ";gets(add.sintomas); pat_file<<add.sintomas<<"\n";
            cout<<"\nDiagnostico : "; pat_file<<"Diagnostico : ";gets(add.diagnosis); pat_file<<add.diagnosis<<"\n";
            cout<<"\nMedicinas : "; pat_file<<"Medicinas : ";gets(add.medicine); pat_file<<add.medicine<<"\n";
            cout<<"\nAdmision requerida? : "; pat_file<<"Admision requerida? : ";gets(add.addmission); pat_file<<add.addmission<<"\n";
           // cout<<"\nmedico :";pat_file<<"medico :";gets(add.medico); pat_file<<add.medico<<"\n";
            cout<<"\nMedico_Especialista : "; pat_file<<"Medico_especialista: ";gets(add.medico); pat_file<<add.medico<<"\n";
            cout<<"\nCodigo_Medico: "; pat_file<<"Codigo_Medico: ";gets(add.codigo); pat_file<<add.codigo<<"\n";
            cout<<"\nNombre_Medico: "; pat_file<<"Nombre_Medico: ";gets(add.nombre); pat_file<<add.nombre<<"\n";
            cout<<"\nTipo de sala : "; pat_file<<"Tipo de sala : ";gets(add.ward); pat_file<<add.ward<<"\n";pat_file<<"\n*************************************************************************\n";
            cout<<"\n\n"<<add.ward<<" la sala se asigna con exito\n";
            //cout<<"\nMédico_Consulta: "; pat_file<<"Médico_Consulta: ";gets(add.medico); pat_file<<add.medico<<"\n";
			pat_file.close();
			cout<<"\n\n";
			system("pause");
            system("cls");
			goto b;
		}
}

//Para mostrar el historial médico completo del paciente en ese hospital ............ opción 3
if(i==3)
{
    fstream pat_file;
    cout<<"\n\nIngrese el nombre del archivo del paciente que se abrira : ";
    cin.ignore();
    gets(fname);
    system("cls");
	pat_file.open(fname, ios::in);
		if(!pat_file)
		{
		cout<<"\nError al abrir el archivo\n";goto b;
		}
		else
		{
		    cout<<"\n\n\n\n\t\t\t\t........................................Historial medico completo de "<<fname<<" ........................................\n\n\n\n";
		    string info;
			while(pat_file.good())
			{
			getline(pat_file,info);
			cout<<info<<"\n";
			}
			cout<<"\n";
        }
        system("pause");
        system("cls");
        goto b;
}

//Salir del sistema con una nota de agradecimiento ........................ opción 6
if(i==6)
{
system("cls");
cout<<"\n\n\n\n\n\n\n\n\n\n\n\n\t\t\t\t\t@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@\n";
cout<<"\t\t\t\t\t@@ _______________________________________________________________________________________ @@\n";
cout<<"\t\t\t\t\t@@|                                           		                                  |@@\n";
cout<<"\t\t\t\t\t@@|                                           		                                  |@@\n";
cout<<"\t\t\t\t\t@@|                                           		                                  |@@\n";
cout<<"\t\t\t\t\t@@|                                           		                                  |@@\n";
cout<<"\t\t\t\t\t@@|                                           		                                  |@@\n";
cout<<"\t\t\t\t\t@@|                                 GRACIAS POR USAR                                      |@@\n";
cout<<"\t\t\t\t\t@@|                                                                                       |@@\n";
cout<<"\t\t\t\t\t@@|                            NUESTRO SISTEMA DE HOSPITAL                                |@@\n";
cout<<"\t\t\t\t\t@@|                                                                                       |@@\n";
cout<<"\t\t\t\t\t@@|                                                                                       |@@\n";
cout<<"\t\t\t\t\t@@|                                                                                       |@@\n";
cout<<"\t\t\t\t\t@@|                                                                                       |@@\n";
cout<<"\t\t\t\t\t@@|                                                                                       |@@\n";
cout<<"\t\t\t\t\t@@|                                        -Proyecto Universitario 5to. semestre          |@@\n";
cout<<"\t\t\t\t\t@@|_______________________________________________________________________________________|@@\n";
cout<<"\t\t\t\t\t@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@\n\n\n\n\t\t\t\t\t";
}


cout<<"\n";

}


