#include <iostream>
#include <vector>
#include "Asistentes.h"
#include "Eventos.h"

using namespace std;

int main()
{
    string dia;
    string resp;

    cout<<"Bienvenido. Ingrese la fecha y hora actuales (Ej:28/03/2024-22:00): "<<endl;
    cin >> dia;

    do
    {
        cout<<"Escoja una opción válida: "<<endl<<"1)Crear nuevo evento"<<endl<<"2)Registrar asistentes"<<endl<<"3)Revisión de Asistentes"<<endl<<"4)Informes de eventos"<<endl<<"5)Salir."<<endl;
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