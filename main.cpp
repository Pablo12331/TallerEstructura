#include <iostream>
#include <vector>
#include <fstream>
#include <sstream>
#include "Eventos.h"
#include "Asistentes.h"

using namespace std;

void actualizarDatos(vector<Eventos*>& eventos)
{
    Eventos* aux;
    string actualizacionEventos = "", actualizacionAsistentes = "";
    int contadorSaltoLinea;
    for(Eventos* evento : eventos)
    {
        if(contadorSaltoLinea < eventos.size())
        {
            actualizacionEventos += evento->informacionCompletaEventos() + "\n";
        }
        else
        {
            actualizacionEventos += evento->informacionCompletaEventos();
        }
    }
    aux->actualizarDatosEventos(actualizacionEventos);
}

void agregarDatos(vector<Eventos*>& eventos, string fechaHoy)
{
    ifstream datosEvento;
    string texto, tipoEvento, ubicacion, alimentos, fecha, tipoMusica, codigoEvento;

    datosEvento.open("prueba de leerArchivos.txt", ios::in);

    if(datosEvento.fail())
    {
        cout<<"ERROR! no se pudo leer el archivo eventos."<<endl;
        exit(1);
    }

    while(!datosEvento.eof())
    {
        Eventos* aux;
        getline(datosEvento, texto);
        aux->agregarDatosEventos(eventos, fechaHoy, texto);
    }
    datosEvento.close();

    ifstream datosAsistentes;

    datosAsistentes.open("Prueba asistentes.txt", ios::in);

    if(datosAsistentes.fail())
    {
        cout<<"ERROR! no se pudo leer el archivo de asistentes."<<endl;
        exit(1);
    }  

    while(!datosAsistentes.eof())
    {
        Asistentes* aux;
        Asistentes* asistente;
        getline(datosAsistentes, texto);
        asistente = aux->agregarDatosAsistentes(texto);

        for(Eventos* evento : eventos)
        {
            if(asistente == nullptr)
            {
                break;
            }
            else if(stoi(evento->getCodigoEvento()) == stoi(asistente->getCodigoEvento()))
            {
                evento->agregarAsistente(asistente);
            }
        }
    }

    datosAsistentes.close();
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
                if(aux->cantidadEventosDia(eventos, fechaActualidad))
                {
                    aux->crearEvento(eventos, fechaActualidad);
                }
                else
                {
                    cout<<"Capacidad maxima de eventos alcanzada, no se pueden crear mas eventos."<<endl;
                }
                break;
            case 2:
                aux->registrarAsistente(eventos);
                break;
            case 3:

                break;
            case 4:
                aux->informacionGeneral(eventos);
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
    actualizarDatos(eventos);
    return 0;
}
int main()
{
    sistema();
    return 0;
}

