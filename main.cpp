#include <iostream>
#include <vector>
#include "Eventos.h"
//#include "Asistentes.h"

using namespace std;

int main()
{
    sistema();   
    return 0;
}
int sistema()
{
    string dia;
    string resp;

    vector<Eventos*> eventos;

    cout<<"Bienvenido. Ingrese la fecha y hora actuales (Ej:28/03/2024-22:00): ";
    cin >> dia;

    int respuesta;
    do
    {
        cout<<"\nEscoja una opción válida: "<<endl<<"1)Crear nuevo evento"<<endl<<"2)Registrar asistentes"<<
        endl<<"3)Revisión de Asistentes"<<endl<<"4)Informes de eventos"<<endl
        <<"5)Cancelar evento"<<endl<<"6)Salir."<<endl<<"\nColoque su opciones aqui(Ejemplo: 1): ";
        cin >> resp;

        respuesta = stoi(resp);

        switch(respuesta)
        {
            case 1:
                
                break;
            case 2:

                break;
            case 3:

                break;
            case 4:

                break;
            case 5:
                
                break;
            case 6:
                cout<<"saliendo..."<<endl;
                cin.clear();
                cin.ignore();
                break;
        }

    }
    while(respuesta != 6);
    return 0;
}