#include <iostream>
#include <vector>
#include "Eventos.h"
//#include "Asistentes.h"

using namespace std;

int main()
{
    string dia;
    string resp;

    cout<<"Bienvenido. Ingrese la fecha y hora actuales (Ej:28/03/2024-22:00): ";
    cin >> dia;
    vector<Eventos*> eventos;
    Eventos *aux;
    do
    {
        cout<<"\nEscoja una opción válida: "<<endl<<"1)Crear nuevo evento"<<endl<<"2)Registrar asistentes"<<
        endl<<"3)Revisión de Asistentes"<<endl<<"4)Informes de eventos"<<endl<<"5)Salir."<<endl<<"\nColoque su opciones aqui(Ejemplo: 1): ";
        cin >> resp;
        if (resp=="1")
        {
            
        }
        if (resp=="2")
        {
            
        }
        if (resp=="3")
        {
        
        }
        if (resp=="4")
        {
        
        }
        if (resp=="5")
        {
            cout<<"Saliendo..."<<endl;
            break;
        }
    }
    while(resp != "5");
    return 0;
}
int sistema()
{
    return 0;
}