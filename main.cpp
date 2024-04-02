#include <iostream>
#include <vector>
#include <fstream>
#include <sstream>
#include "Eventos.h"
#include "Asistentes.h"

using namespace std;

void agregarDatos(vector<Eventos*>& eventos, string fechaHoy)
{
    ifstream archivo;
    string texto, tipoEvento, ubicacion, alimentos, fecha, tipoMusica, codigoEvento;

    archivo.open("prueba de leerArchivos.txt", ios::in);

    if(archivo.fail())
    {
        cout<<"ERROR! no se pudo abrir el archivo."<<endl;
        exit(1);
    }

    while(!archivo.eof())
    {
        Eventos* aux;
        getline(archivo, texto);
        aux->agregarDatosEventos(eventos, fechaHoy, texto);
    }

    archivo.close();
}

int sistema()
{
    string fechaActualidad;
    string resp;

    vector<Eventos*> eventos;
    Eventos* aux;
    
    cout<<"Bienvenido. Ingrese la fecha de hoy(Ej:28/03/2024): ";
    cin >> fechaActualidad;

    agregarDatos(eventos, fechaActualidad);

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
                cout<<eventos.size()<<endl;
                if(aux->cantidadEventosDia(eventos, fechaActualidad))
                {
                    aux->crearEvento(eventos, fechaActualidad);
                }
                else
                {
                    cout<<"Capacidad maxima de eventos alcanzada, no se pueden crear mas eventos."<<endl;
                }
                cout<<eventos.size()<<endl;
                //delete(eventos[0]);
                cout<<eventos.size()<<endl;
                cout<<eventos[0]->getFecha();
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
int main()
{
    sistema();
    return 0;
}

